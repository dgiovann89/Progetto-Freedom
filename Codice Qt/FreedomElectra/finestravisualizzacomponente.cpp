#include "finestravisualizzacomponente.h"

FinestraVisualizzaComponente::FinestraVisualizzaComponente(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra Visualizza Componente");
    this->setMinimumSize(320,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Visualizza Componente:");
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraVisualizzaComponente::torna(){
    this->close();
}
