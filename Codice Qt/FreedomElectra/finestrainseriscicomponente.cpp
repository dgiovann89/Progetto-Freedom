#include "finestrainseriscicomponente.h"

FinestraInserisciComponente::FinestraInserisciComponente(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra Inserisci Componenti");
    this->setMinimumSize(620,440);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Inserisci un componente:");
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraInserisciComponente::torna(){
    this->close();
}
