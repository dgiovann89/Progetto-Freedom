#include "finestracercacliente.h"

FinestraCercaCliente::FinestraCercaCliente(DatabaseClienti* d, QDialog* parent): QDialog(parent), dbc(d){
    this->setWindowTitle("Finestra Cerca Cliente");
    this->setMinimumSize(620,440);

    // new layout e groupbox
    layoutSfondo=new QHBoxLayout(this);
//    layoutCompilazione=new QFormLayout();
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
    bottoneApriCliente->setDisabled(true);
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

    // layout compilazione
    layoutCompilazione->addWidget(labelTitolo,0,0,1,0);
    layoutCompilazione->addWidget(labelRagioneSociale,1,0);
    layoutCompilazione->addWidget(lineEditRagioneSociale,1,1);
    layoutCompilazione->addWidget(labelPIva,2,0);
    layoutCompilazione->addWidget(lineEditPIva,2,1);
    layoutCompilazione->addWidget(bottoneCercaCliente,3,0,1,0,Qt::AlignBottom);
    layoutCompilazione->addWidget(bottoneIndietro,4,0,1,0,Qt::AlignBottom);

    layoutCompilazione->setAlignment(Qt::AlignTop);

    // layout lista
    layoutLista->addWidget(labelLista);
    layoutLista->addWidget(tabellaClienti);
    layoutLista->addWidget(bottoneApriCliente);
    layoutLista->addWidget(bottoneEliminaCliente);

    this->setLayout(layoutSfondo);

    // eseguo metdo riempiTabellaClieni
    riempiTabellaClienti();

    connect(bottoneApriCliente,SIGNAL(clicked()),this,SLOT(apriFinestraClienteSelezionato()));
    connect(tabellaClienti,SIGNAL(cellClicked(int,int)),this,SLOT(mostraBottoneVisualizza()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneEliminaCliente,SIGNAL(clicked()),this,SLOT(rimuoviClienteSelezionato()));

}
// metodi privati
// riempi tabella clienti
void FinestraCercaCliente::riempiTabellaClienti() {
   int row = tabellaClienti->rowCount();
   cout << row << endl;
   for (unsigned int i= 0; i<dbc->getDatabase().size(); ++i) {
         tabellaClienti->setRowCount(row+1);
         QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getRagioneSociale()));
         tabellaClienti->setItem(row, 0, itemRagioneSociale);
         itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getStabilimento()));
         itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 1, itemStabilimento);
         ++row;
   }
   cout << "row dopo il for:" << row << endl;
}

void FinestraCercaCliente::mostraBottoneVisualizza(){
    bottoneApriCliente->setDisabled(false);
}

void FinestraCercaCliente::rimuoviClienteSelezionato() {
   if (tabellaClienti->currentItem()!= 0)
      dbc->rimuoviCliente(tabellaClienti->currentRow());
      tabellaClienti->clearContents();
      tabellaClienti->setRowCount(0);
      riempiTabellaClienti();
      bottoneApriCliente->setDisabled(true);
}

void FinestraCercaCliente::apriFinestraClienteSelezionato(){
    if(!(tabellaClienti->selectedItems().isEmpty())){
        Cliente* c;
        int riga = tabellaClienti->currentRow();
        c = &(dbc->getCliente(riga));
        FinestraClienteSelezionato finCliSel(dbc,c);
        finCliSel.exec();
        tabellaClienti->clearContents();
        tabellaClienti->setRowCount(0);
        riempiTabellaClienti();
    }
//    bottoneApriCliente->setDisabled(true);
}

void FinestraCercaCliente::torna(){
    this->close();
}
