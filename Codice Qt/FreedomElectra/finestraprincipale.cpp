#include "finestraprincipale.h"

FinestraPrincipale::FinestraPrincipale(QDialog* parent): QDialog(parent){
    this->setWindowTitle("Finestra Principale");
    this->setMinimumSize(320,240);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Benvenuto!");
    bottoneCambia=new QPushButton("Cambia",this);
    bottoneEsci=new QPushButton("Esci!",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneCambia);
    layout->addSpacing(20);
    layout->addWidget(bottoneEsci);

    this->setLayout(layout);

    connect(bottoneEsci,SIGNAL(clicked()),this,SLOT(esci()));
    connect(bottoneCambia,SIGNAL(clicked()),this,SLOT(apriNuovaFinestra()));
}

void FinestraPrincipale::esci() {
    this->close();
}

void FinestraPrincipale::apriNuovaFinestra(){
    FinestraCercaCliente fin;
    this->close();
    fin.exec();
}
