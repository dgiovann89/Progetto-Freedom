#include "finestracercacliente.h"

FinestraCercaCliente::FinestraCercaCliente(QDialog* parent): QDialog(parent){
    this->setWindowTitle("Finestra Cerca Cliente");
    this->setMinimumSize(620,340);

    // new layout e groupbox
    layoutSfondo=new QHBoxLayout(this);
    layoutCompilazione=new QGridLayout();
    boxCompilazione=new QGroupBox(this);
    layoutLista= new QVBoxLayout(this);
    boxLista= new QGroupBox("",this);

    // new label
    labelRagioneSociale=new QLabel("Ragione Sociale:",this);
    lineEditRagioneSociale=new QLineEdit(this);
    labelPIva=new QLabel("Partita Iva:",this);
    lineEditPIva=new QLineEdit(this);
    labelTitolo=new QLabel("Cerca cliente per Nome o PIva:");
    labelLista=new QLabel("Lista Clienti:");

    // new bottoni
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

    // associazioni box e layout
    boxCompilazione->setLayout(layoutCompilazione);
    boxLista->setLayout(layoutLista);
    layoutSfondo->addWidget(boxCompilazione);
    layoutSfondo->addWidget(boxLista);

//    labelTitolo->setAlignment(Qt::AlignTop);

//    labelRagioneSociale->setAlignment(0);
//    lineEditRagioneSociale->s eTT

    // layout compilazione
    layoutCompilazione->addWidget(labelTitolo,0,0,1,0,Qt::AlignTop);
    layoutCompilazione->addWidget(labelRagioneSociale,1,0);
    layoutCompilazione->addWidget(lineEditRagioneSociale,1,1);
    layoutCompilazione->addWidget(labelPIva,2,0);
    layoutCompilazione->addWidget(lineEditPIva,2,1);
    layoutCompilazione->addWidget(bottoneCercaCliente,3,0,1,0);
    layoutCompilazione->addWidget(bottoneIndietro,4,0,1,0);

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
