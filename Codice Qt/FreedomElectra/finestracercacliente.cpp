#include "finestracercacliente.h"

FinestraCercaCliente::FinestraCercaCliente(DatabaseClienti* d, DatabaseComponenti* db, QDialog* parent): QDialog(parent), dbCli(d), dbComp(db){
    this->setWindowTitle("Finestra Cerca Cliente");
    this->showMaximized(); // metti la finestra a tutto schermo

//    fromJasonClienti.loadClienti(DatabaseClienti::Json); // tira su i dati da file json

    // new layout e groupbox
    layoutSfondo=new QVBoxLayout(this);
    layoutCompilazione=new QHBoxLayout();
    layoutBottoni = new QHBoxLayout();
    boxCompilazione=new QGroupBox(this);
    layoutLista= new QVBoxLayout();
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
    bottoneReset=new QPushButton("Reset campi",this);

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
    layoutCompilazione->addWidget(bottoneReset);

    layoutCompilazione->setAlignment(Qt::AlignTop);

    // layout lista
    layoutLista->addWidget(labelLista);
    layoutLista->addWidget(tabellaClienti);

    lineEditRagioneSociale->setCursorPosition(0);

    this->setLayout(layoutSfondo);

    // eseguo metdo riempiTabellaClieni
    riempiTabellaClienti();

    connect(bottoneApriCliente,SIGNAL(clicked()),this,SLOT(apriFinestraClienteSelezionato()));
    connect(bottoneReset,SIGNAL(clicked()),this,SLOT(resetCampi()));
    connect(tabellaClienti,SIGNAL(cellClicked(int,int)),this,SLOT(mostraBottoneVisualizza()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneCercaCliente,SIGNAL(clicked()),this,SLOT(cercaCliente()));
    connect(lineEditRagioneSociale,SIGNAL(textEdited(QString)),this,SLOT(abilitaLineEditPIva()));
    connect(lineEditPIva,SIGNAL(textEdited(QString)),this,SLOT(abilitaLineEditRagioneSociale()));
    connect(tabellaClienti,SIGNAL(cellDoubleClicked(int,int)), this,SLOT(apriFinestraClienteSelezionato()));

}

void FinestraCercaCliente::intestazioneTabella() {
    QStringList header;
    header=QStringList() << "Rag. Sociale" << "Stabilimento" << "Via" << "Partita Iva";
    tabellaClienti->setHorizontalHeaderLabels(header);
    QHeaderView* q=tabellaClienti->horizontalHeader();
    q->setStretchLastSection(true);
    tabellaClienti->setHorizontalHeader(q);
    tabellaClienti->setColumnWidth(0,250);
    tabellaClienti->setColumnWidth(1,250);
    tabellaClienti->setColumnWidth(2,250);
}

// metodi privati
// riempi tabella clienti
void FinestraCercaCliente::riempiTabellaClienti() {
   int row = tabellaClienti->rowCount();
   for (unsigned int i= 0; i<dbCli->getDatabase().size(); ++i) { // si prende i dati dal file e nn dal dbCli
         tabellaClienti->setRowCount(row+1);
         QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getRagioneSociale()));
         tabellaClienti->setItem(row, 0, itemRagioneSociale);
         itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getStabilimento()));
         itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 1, itemStabilimento);
         QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getIndirizzo().getVia()));
         itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 2, itemVia);
         QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getPIva()));
         itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 3, itemPartitaIva);
         ++row;
   }
//   intestazioneTabella();
}

// aggiorna tabella clienti
void FinestraCercaCliente::aggiornaTabellaClienti() {
   int row = 0;
   for (unsigned int i= 0; i<dbCli->getDatabase().size(); ++i) { // si prende i dati dal file e nn dal dbCli
         tabellaClienti->setRowCount(row+1);
         QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getRagioneSociale()));
         tabellaClienti->setItem(row, 0, itemRagioneSociale);
//         itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getStabilimento()));
//         itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 1, itemStabilimento);
         QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getIndirizzo().getVia()));
//         itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 2, itemVia);
         QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getPIva()));
//         itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
         tabellaClienti->setItem(row, 3, itemPartitaIva);
         ++row;
   }
}

void FinestraCercaCliente::resetCampi(){
    lineEditRagioneSociale->clear();
    lineEditPIva->clear();
    aggiornaTabellaClienti();
//    intestazioneTabella();
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
        int i=0;
        bool trovato=false;
//        int row = 0;
        vector<Cliente>::const_iterator it=dbCli->getDatabase().begin();
        int row = tabellaClienti->rowCount();
        for(;it!=dbCli->getDatabase().end();++it){

            if(QString::fromStdString(dbCli->getCliente(i).getRagioneSociale()) == lineEditRagioneSociale->text()){
                if (trovato==false){
                    trovato=true;
                    tabellaClienti->clear();
                    tabellaClienti->setRowCount(row+1);
                                        row = 0;

                    QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getRagioneSociale()));
                    tabellaClienti->setItem(0, 0, itemRagioneSociale);
                    //                    itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getStabilimento()));
                    tabellaClienti->setItem(0, 1, itemStabilimento);\
                    //                    itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getIndirizzo().getVia()));
                    tabellaClienti->setItem(0, 2, itemVia);
                    //                    itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getPIva()));
                    tabellaClienti->setItem(0, 3, itemPartitaIva);
                    //                    itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                }
                else{ // trovato==true ->ho gia trovato un cliente con lo stesso nome
                    tabellaClienti->setRowCount(row+1);

                    QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getRagioneSociale()));
                    tabellaClienti->setItem(row, 0, itemRagioneSociale);
                    //                    itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getStabilimento()));
                    tabellaClienti->setItem(row, 1, itemStabilimento);
                    //                    itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getIndirizzo().getVia()));
                    tabellaClienti->setItem(row, 2, itemVia);
                    //                    itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                    QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getPIva()));
                    tabellaClienti->setItem(row, 3, itemPartitaIva);
                    //                    itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                }
                row++;
            }
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
            int i=0;
            bool trovato=false;
//            int row = 0;


            vector<Cliente>::const_iterator it=dbCli->getDatabase().begin();
            int row = tabellaClienti->rowCount();
            for(;it!=dbCli->getDatabase().end();++it){

                if(QString::fromStdString(dbCli->getCliente(i).getPIva()) == lineEditPIva->text()){
                    if (trovato==false){
                        trovato=true;
                        cout<<"sono nell if" << endl;
                        cout << trovato << endl;
                        tabellaClienti->clear();
                        tabellaClienti->setRowCount(row+1);
                        row = 0;

                        QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getRagioneSociale()));
                        tabellaClienti->setItem(0, 0, itemRagioneSociale);
                        //                    itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                        QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getStabilimento()));
                        tabellaClienti->setItem(0, 1, itemStabilimento);
                        //                    itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                        QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getIndirizzo().getVia()));
                        tabellaClienti->setItem(0, 2, itemVia);
                        //                    itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                        QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getPIva()));
                        tabellaClienti->setItem(0, 3, itemPartitaIva);
                        //                    itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                    }
                    else{ // trovato==true ->ho gia trovato un cliente con lo stesso nome
                        tabellaClienti->setRowCount(row+1);

                        QTableWidgetItem* itemRagioneSociale= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getRagioneSociale()));
                        tabellaClienti->setItem(row, 0, itemRagioneSociale);
                        //                    itemRagioneSociale->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                        QTableWidgetItem* itemStabilimento= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getStabilimento()));
                        tabellaClienti->setItem(row, 1, itemStabilimento);
                        //                    itemStabilimento->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                        QTableWidgetItem* itemVia= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getIndirizzo().getVia()));
                        tabellaClienti->setItem(row, 2, itemVia);
                        //                    itemVia->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                        QTableWidgetItem* itemPartitaIva= new QTableWidgetItem (QString::fromStdString(dbCli->getCliente(i).getPIva()));
                        tabellaClienti->setItem(row, 3, itemPartitaIva);
                        //                    itemPartitaIva->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                    }
                    row++;
                }
                i++;
            }
            if(!trovato){
                QMessageBox err;
                err.setText("Utente non trovato");
                err.exec();
            }
        }
       intestazioneTabella();
}

void FinestraCercaCliente::apriFinestraClienteSelezionato(){
    if(!(tabellaClienti->selectedItems().isEmpty())){
            int riga=tabellaClienti->currentRow();
            Cliente* c;
            int i=0;
            bool trovato=false;
             vector<Cliente>::const_iterator it=dbCli->getDatabase().begin();
             for(;it!=dbCli->getDatabase().end() && !trovato;++it){
                 if((QString::fromStdString(dbCli->getCliente(i).getRagioneSociale())==tabellaClienti->item(riga,0)->text()) &&
                         QString::fromStdString(dbCli->getCliente(i).getStabilimento())==tabellaClienti->item(riga,1)->text()){
                     c=&(dbCli->getCliente(i));
                     trovato=true;
                 }
                 i++;
             }
            FinestraClienteSelezionato fin(dbCli,dbComp,c);
            fin.exec();
        }
        tabellaClienti->clearContents();
        tabellaClienti->setRowCount(0);
        riempiTabellaClienti();
}

void FinestraCercaCliente::torna(){
    this->close();
}
