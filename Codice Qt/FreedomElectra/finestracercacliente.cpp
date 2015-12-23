#include "finestracercacliente.h"

FinestraCercaCliente::FinestraCercaCliente(QDialog* parent): QDialog(parent){
    this->setWindowTitle("Finestra Cerca Cliente");
    this->setMinimumSize(420,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Cerca i clienti");
    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneEsci=new QPushButton("Esci!",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);
    layout->addSpacing(20);
    layout->addWidget(bottoneEsci);

    this->setLayout(layout);

    connect(bottoneEsci,SIGNAL(clicked()),this,SLOT(esci()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraCercaCliente::esci() {
    this->close();
}

void FinestraCercaCliente::torna(){
    FinestraPrincipale finprinc;
    this->close();
    finprinc.exec();
}
