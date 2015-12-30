#include "finestracercacliente.h"

FinestraCercaCliente::FinestraCercaCliente(QDialog* parent): QDialog(parent){
    this->setWindowTitle("Finestra Cerca Cliente");
    this->setMinimumSize(620,340);

    layoutSfondo=new QHBoxLayout(this);
    layoutCompilazione=new QGridLayout();
    boxCompilazione=new QGroupBox(this);
    layoutLista= new QVBoxLayout(this);
    boxLista= new QGroupBox("",this);
    labelRagioneSociale=new QLabel("Ragione Sociale:",this);
    lineEditRagioneSociale=new QLineEdit(this);
    labelPIva=new QLabel("Partita Iva:",this);
    lineEditPIva=new QLineEdit(this);
    labelTitolo=new QLabel("Cerca cliente per Nome o PIva:");
    labelLista=new QLabel("Lista Clienti:");
    bottoneApriCliente=new QPushButton("Visualizza Cliente",this);
    bottoneCercaCliente=new QPushButton("Cerca",this);
    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneEliminaCliente=new QPushButton("Elimina Cliente",this);

    // tabella clienti
    tabellaClienti=new QTableWidget(0,2);
    tabellaClienti->setColumnWidth(0,150);
    QStringList header;
    header=QStringList() << "Rag. Sociale" << "Stabilimento";
    tabellaClienti->setHorizontalHeaderLabels(header);

    boxCompilazione->setLayout(layoutCompilazione);
    boxLista->setLayout(layoutLista);
    layoutSfondo->addWidget(boxCompilazione);
    layoutSfondo->addWidget(boxLista);

    // layout compilazione
    layoutCompilazione->addWidget(labelTitolo,0,0);
    layoutCompilazione->addWidget(labelRagioneSociale,1,0);
    layoutCompilazione->addWidget(lineEditRagioneSociale,1,1);
    layoutCompilazione->addWidget(labelPIva,2,0);
    layoutCompilazione->addWidget(lineEditPIva,2,1);
    layoutCompilazione->setSpacing(30);
    layoutCompilazione->addWidget(bottoneCercaCliente);
    layoutCompilazione->addWidget(bottoneIndietro);

    // layout lista
    layoutLista->addWidget(labelLista);
    layoutLista->addWidget(tabellaClienti);
    layoutLista->addWidget(bottoneApriCliente);
    layoutLista->addWidget(bottoneEliminaCliente);

    this->setLayout(layoutSfondo);

    connect(bottoneApriCliente,SIGNAL(clicked()),this,SLOT(apriFinestraClienteSelezionato()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraCercaCliente::apriFinestraClienteSelezionato(){
    FinestraClienteSelezionato finCliSel;
    finCliSel.exec();
}

void FinestraCercaCliente::torna(){
    this->close();
}
