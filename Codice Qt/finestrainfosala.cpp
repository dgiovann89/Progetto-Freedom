#include "finestrainfosala.h"

FinestraInfoSala::FinestraInfoSala(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Info Inserisci Sala Compressori");
    this->setMinimumSize(320,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Informazioni Sala Compressori:");
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraInfoSala::torna(){
    this->close();
}
