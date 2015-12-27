#include "finestrainseriscicliente.h"

FinestraInserisciCliente::FinestraInserisciCliente(QDialog* parent): QDialog(parent){
    this->setWindowTitle("Finestra Inserisci Cliente");
    this->setMinimumSize(420,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Inserisci cliente");
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraInserisciCliente::torna(){
//    FinestraPrincipale finprinc;
    this->close();
}
