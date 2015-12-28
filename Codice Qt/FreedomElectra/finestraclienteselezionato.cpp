#include "finestraclienteselezionato.h"

FinestraClienteSelezionato::FinestraClienteSelezionato(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra Cliente Selezionato");
    this->setMinimumSize(520,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Cliente Selezionato:");
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraClienteSelezionato::torna(){
    this->close();
}
