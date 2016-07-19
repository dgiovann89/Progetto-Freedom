#include "finestraprincipale.h"

FinestraPrincipale::FinestraPrincipale(QDialog* parent): QDialog(parent){
    dbc = new DatabaseClienti();
    dbc->loadClienti(DatabaseClienti::Json); // carica il dbc da file
    dbComp=new DatabaseComponenti();
    this->setWindowTitle("Finestra Principale");
    this->setMinimumSize(320,240);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("FreedomElectra by Electra System sas");
    labelTitolo->setFont(QFont("Arial",20));
    bottoneInserisciCliente=new QPushButton("Inserisci Cliente",this);
    bottoneCercaCliente=new QPushButton("Cerca Cliente",this);
    bottoneEsci=new QPushButton("Esci",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneInserisciCliente);
    layout->addSpacing(20);
    layout->addWidget(bottoneCercaCliente);
    layout->addSpacing(20);
    layout->addWidget(bottoneEsci);

    this->setLayout(layout);

    connect(bottoneInserisciCliente,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciCliente()));
    connect(bottoneCercaCliente,SIGNAL(clicked()),this,SLOT(apriFinestraCercaCliente()));
    connect(bottoneEsci,SIGNAL(clicked()),this,SLOT(esci()));
}

void FinestraPrincipale::apriFinestraInserisciCliente(){
    FinestraInserisciCliente finInsCli(dbc);
    finInsCli.exec();
}

void FinestraPrincipale::apriFinestraCercaCliente(){
    FinestraCercaCliente finCerCli(dbc,dbComp);
    finCerCli.exec();
}

void FinestraPrincipale::esci() {
    this->close();
}
