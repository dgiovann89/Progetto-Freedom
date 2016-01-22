#include "finestracercacliente.h"

FinestraCercaCliente::FinestraCercaCliente(DatabaseClienti* d, QDialog* parent): QDialog(parent), dbc(d){
    this->setWindowTitle("Finestra Cerca Cliente");
    this->showMaximized(); // metti la finestra a tutto schermo

//    fromJasonClienti.loadClienti(DatabaseClienti::Json); // tira su i dati da file json

    // new layout e groupbox
    layoutSfondo=new QVBoxLayout(this);
    layoutCompilazione=new QHBoxLayout();
    layoutBottoni = new QHBoxLayout();
    boxCompilazione=new QGroupBox(this);
    layoutLista= new QVBoxLayout(this);
    boxLista= new QGroupBox("",this);
    boxBottoni = new QGroupBox(this);

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

    // tabella clienti
    tabellaClienti=new QTableWidget(0,4);
    tabellaClienti->setColumnWidth(0,200);
    QStringList header;
    header=QStringList() << "Rag. Sociale" << "Stabilimento" << "Via" << "Partita Iva";
    tabellaClienti->setHorizontalHeaderLabels(header);
    QHeaderView* q=tabellaClienti->horizontalHeader();
    q->setStretchLastSection(true);
    tabellaClienti->setHorizontalHeader(q);
    tabellaClienti->setColumnWidth(0,250);
    tabellaClienti->setColumnWidth(1,250);
    tabellaClienti->setColumnWidth(2,250);

    // associazioni box e layout
    boxCompilazione->setLayout(layoutCompilazione);
    boxLista->setLayout(layoutLista);
    boxBottoni->setLayout(layoutBottoni);
    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneApriCliente);
    layoutSfondo->addWidget(labelTitolo);
    layoutSfondo->addWidget(boxCompilazione);
    layoutSfondo->addWidget(boxLista);
    layoutSfondo->addWidget(boxBottoni);

    // layout compilazione
    layoutCompilazione->addWidget(labelRagioneSociale);
    layoutCompilazione->addWidget(lineEditRagioneSociale);
    layoutCompilazione->addWidget(labelPIva);
    layoutCompilazione->addWidget(lineEditPIva);
    layoutCompilazione->addWidget(bottoneCercaCliente);

    layoutCompilazione->setAlignment(Qt::AlignTop);

    // layout lista
    layoutLista->addWidget(labelLista);
    layoutLista->addWidget(tabellaClienti);

    lineEditRagioneSociale->setCursorPosition(0);

    this->setLayout(layoutSfondo);

    // eseguo metdo riempiTabellaClieni
    riempiTabellaClienti();

    connect(bottoneApriCliente,SIGNAL(clicked()),this,SLOT(apriFinestraClienteSelezionato()));
    connect(tabellaClienti,SIGNAL(cellClicked(int,int)),this,SLOT(mostraBottoneVisualizza()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneCercaCliente,SIGNAL(clicked()),this,SLOT(cercaCliente()));
    connect(lineEditRagioneSociale,SIGNAL(textEdited(QString)),this,SLOT(abilitaLineEditPIva()));
    connect(lineEditPIva,SIGNAL(textEdited(QString)),this,SLOT(abilitaLineEditRagioneSociale()));
    connect(tabellaClienti,SIGNAL(cellDoubleClicked(int,int)), this,SLOT(apriFinestraClienteSelezionato()));

}
// metodi privati
// riempi tabella clienti
void FinestraCercaCliente::riempiTabellaClienti() {
   int row = tabellaClienti->rowCount();
   cout << row << endl;
   for (unsigned int i= 0; i<dbc->getDatabase().size(); ++i) { // si prende i dati dal file e nn dal dbc
         tabellaClienti->setRowCount(row+1);
         QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getRagioneSociale()));
         tabellaClienti->setItem(row, 0, itemRagioneSociale);
         itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getStabilimento()));
         itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 1, itemStabilimento);
         QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getIndirizzo().getVia()));
         itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 2, itemVia);
         QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getPIva()));
         itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 3, itemPartitaIva);
         ++row;
   }
   cout << "row dopo il for:" << row << endl;
}

void FinestraCercaCliente::mostraBottoneVisualizza(){
    bottoneApriCliente->setDisabled(false);
}

void FinestraCercaCliente::abilitaLineEditPIva(){
    if (lineEditRagioneSociale->text()!="")
    lineEditPIva->setDisabled(true);
    else
        lineEditPIva->setDisabled(false);
}

void FinestraCercaCliente::abilitaLineEditRagioneSociale(){
    if(lineEditPIva->text()!="")
        lineEditRagioneSociale->setDisabled(true);
    else
        lineEditRagioneSociale->setDisabled(false);
}

// slot cerca cliente
void FinestraCercaCliente::cercaCliente() {
   if (lineEditRagioneSociale->text()!=""){
       Cliente* cliente;
       int i=0;
       bool trovato=false;
        vector<Cliente>::const_iterator it=dbc->getDatabase().begin();
        int row = tabellaClienti->rowCount();
        for(;it!=dbc->getDatabase().end();++it){

            if(QString::fromStdString(dbc->getCliente(i).getRagioneSociale()) == lineEditRagioneSociale->text()){
                cliente=&(dbc->getCliente(i));
                if (trovato==false){
                    trovato=true;
                    tabellaClienti->clear();
                    tabellaClienti->setRowCount(1);
                    row = 0;

                    QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getRagioneSociale()));
                    tabellaClienti->setItem(0, 0, itemRagioneSociale);
                    itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getStabilimento()));
                    tabellaClienti->setItem(0, 1, itemStabilimento);\
                    itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getIndirizzo().getVia()));
                    tabellaClienti->setItem(0, 2, itemVia);
                    itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getPIva()));
                    tabellaClienti->setItem(0, 3, itemPartitaIva);
                    itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                    cout << "entrato" << endl;
                }
                else{ // trovato==true ->ho gia trovato un cliente con lo stesso nome
                    tabellaClienti->setRowCount(row+1);

                    QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getRagioneSociale()));
                    tabellaClienti->setItem(row, 0, itemRagioneSociale);
                    itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getStabilimento()));
                    tabellaClienti->setItem(row, 1, itemStabilimento);
                    itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getIndirizzo().getVia()));
                    tabellaClienti->setItem(0, 2, itemVia);
                    itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getPIva()));
                    tabellaClienti->setItem(row, 3, itemPartitaIva);
                    itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                }
            row++;

            }
            else
                cout<< "cliente " << i << "non corrisponendente" << endl;
          i++;
        }
       if(!trovato){
           QMessageBox err;
           err.setText("Utente non trovato");
           err.exec();
       }
   }
   else
       if (lineEditPIva->text()!=""){
           Cliente* cliente;
           int i=0;
           bool trovato=false;
            vector<Cliente>::const_iterator it=dbc->getDatabase().begin();
            for(;it!=dbc->getDatabase().end() && !trovato;++it){

                if(QString::fromStdString(dbc->getCliente(i).getPIva()) == lineEditPIva->text()){
                    cliente=&(dbc->getCliente(i));
                    trovato=true;
                    tabellaClienti->clear();
                    tabellaClienti->setRowCount(1);

                    QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getRagioneSociale()));
                    tabellaClienti->setItem(0, 0, itemRagioneSociale);
                    itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getStabilimento()));
                    tabellaClienti->setItem(0, 1, itemStabilimento);
                    itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getIndirizzo().getVia()));
                    tabellaClienti->setItem(0, 2, itemVia);
                    itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbc->getCliente(i).getPIva()));
                    tabellaClienti->setItem(0, 3, itemPartitaIva);
                    itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                }
              i++;
            }
           if(!trovato){
               QMessageBox err;
               err.setText("Utente non trovato");
               err.exec();
           }
       }
}

void FinestraCercaCliente::apriFinestraClienteSelezionato(){
    if(!(tabellaClienti->selectedItems().isEmpty())){
            int riga=tabellaClienti->currentRow();
            Cliente* c;
            int i=0;
            bool trovato=false;
             vector<Cliente>::const_iterator it=dbc->getDatabase().begin();
             for(;it!=dbc->getDatabase().end() && !trovato;++it){
                 if((QString::fromStdString(dbc->getCliente(i).getRagioneSociale())==tabellaClienti->item(riga,0)->text()) &&
                         QString::fromStdString(dbc->getCliente(i).getStabilimento())==tabellaClienti->item(riga,1)->text()){
                     c=&(dbc->getCliente(i));
                     trovato=true;
                 }
                 i++;
             }
            FinestraClienteSelezionato fin(dbc,c);
            fin.exec();
        }
        tabellaClienti->clearContents();
        tabellaClienti->setRowCount(0);
        riempiTabellaClienti();
}

void FinestraCercaCliente::torna(){
    this->close();
}
