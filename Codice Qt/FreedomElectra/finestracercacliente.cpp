#include "finestracercacliente.h"

FinestraCercaCliente::FinestraCercaCliente(QDialog* parent): QDialog(parent){
    this->setWindowTitle("Finestra Cerca Cliente");
    this->setMinimumSize(420,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Cerca i clienti");
    bottoneVisualizzaCliente=new QPushButton("Visualizza Cliente",this);
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneVisualizzaCliente);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneVisualizzaCliente,SIGNAL(clicked()),this,SLOT(apriFinestraClienteSelezionato()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraCercaCliente::apriFinestraClienteSelezionato(){
    FinestraClienteSelezionato finCliSel;
    finCliSel.exec();
}

void FinestraCercaCliente::torna(){
    this->close();
}
