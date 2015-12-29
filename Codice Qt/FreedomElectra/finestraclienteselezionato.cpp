#include "finestraclienteselezionato.h"

FinestraClienteSelezionato::FinestraClienteSelezionato(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra Cliente Selezionato");
    this->setMinimumSize(520,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Cliente Selezionato:");
    bottoneInserisciSala=new QPushButton("Inserisci nuova Sala Compressori",this);
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneInserisciSala);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneInserisciSala,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciSala()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraClienteSelezionato::apriFinestraInserisciSala(){
    FinestraInserisciSala finInsSala;
    finInsSala.exec();
}

void FinestraClienteSelezionato::torna(){
    this->close();
}
