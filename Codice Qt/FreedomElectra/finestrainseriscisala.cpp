#include "finestrainseriscisala.h"

FinestraInserisciSala::FinestraInserisciSala(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra Inserisci Sala Compressori");
    this->setMinimumSize(620,340);

    layout=new QVBoxLayout(this);
    labelTitolo=new QLabel("Sala Compressori:");
    bottoneModificaInfoSala=new QPushButton("Modifica Info Sala",this);
    bottoneInserisciComponente=new QPushButton("Inserisci nuovo componente",this);
    bottoneVisualizzaComponente=new QPushButton("Visualizza componente",this);
    bottoneIndietro=new QPushButton("Torna indietro",this);

    layout->addWidget(labelTitolo);
    layout->addSpacing(20);
    layout->addWidget(bottoneModificaInfoSala);
    layout->addSpacing(20);
    layout->addWidget(bottoneInserisciComponente);
    layout->addSpacing(20);
    layout->addWidget(bottoneVisualizzaComponente);
    layout->addSpacing(20);
    layout->addWidget(bottoneIndietro);

    this->setLayout(layout);

    connect(bottoneModificaInfoSala,SIGNAL(clicked()),this,SLOT(apriFinestraModificaInfoSala()));
    connect(bottoneInserisciComponente,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciComponente()));
    connect(bottoneVisualizzaComponente,SIGNAL(clicked()),this,SLOT(apriFinestraVisualizzaComponente()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraInserisciSala::apriFinestraModificaInfoSala(){
    FinestraInfoSala finInfoSala;
    finInfoSala.exec();
}

void FinestraInserisciSala::apriFinestraInserisciComponente(){
    FinestraInserisciComponente finInsComp;
    finInsComp.exec();
}

void FinestraInserisciSala::apriFinestraVisualizzaComponente(){
    FinestraVisualizzaComponente finVisComp;
    finVisComp.exec();
}

void FinestraInserisciSala::torna(){
    this->close();
}
