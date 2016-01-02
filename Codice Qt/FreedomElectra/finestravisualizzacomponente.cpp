#include "finestravisualizzacomponente.h"

FinestraVisualizzaComponente::FinestraVisualizzaComponente(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra Visualizza Componente");
    this->setMinimumSize(340,340);

    // new
    layoutSfondo=new QVBoxLayout(this);
    layoutDatiComponente = new QGridLayout();
    layoutBottoni = new QHBoxLayout(this);
    boxDatiComponente = new QGroupBox(this);
    boxBottoni = new QGroupBox(this);
    labelTipo = new QLabel("Tipo:");
    labelMarca=new QLabel("Marca:");
    labelModello = new QLabel("Modello:");
    labelAnno = new QLabel("Anno:");
    labelPressione = new QLabel("Pressione:");
    labelPortata_Capacità = new QLabel("Portata o Capacità:");
    labelKw = new QLabel("Kw:");
    lineEditMarca = new QLineEdit(this);
    lineEditModello = new QLineEdit(this);
    lineEditAnno = new QLineEdit(this);
    lineEditPressione = new QLineEdit(this);
    lineEditPortata_Capacità = new QLineEdit(this);
    lineEditKw = new QLineEdit(this);
    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneModifica = new QPushButton("Modifica",this);
    comboBoxTipo = new QComboBox();

    // set comboBox
    QStringList list= (QStringList()<< "Compressore On-Off"<< "Compressorie Vel variable"<< "Essiccatore On-Off" << "Essiccatore Vel variabile" << "Impianto" << "Filtro" << "Serbatoio");
    comboBoxTipo->addItems(list);

//    selezionato = comboBoxTipo->currentText();
//    if (selezionato=="Compressore On-Off")
//        lineEditKw->setDisabled(true);
//    else
//        lineEditKw->setDisabled(false);

    // associazione box e layout
    layoutSfondo->addWidget(boxDatiComponente);
    layoutSfondo->addWidget(boxBottoni);
    boxDatiComponente->setLayout(layoutDatiComponente);
    boxBottoni->setLayout(layoutBottoni);

    // associazione a layoutDatiComponente
    layoutDatiComponente->addWidget(labelTipo,0,0);
    layoutDatiComponente->addWidget(comboBoxTipo,0,1);
    layoutDatiComponente->addWidget(labelMarca,1,0);
    layoutDatiComponente->addWidget(lineEditMarca,1,1);
    layoutDatiComponente->addWidget(labelModello,2,0);
    layoutDatiComponente->addWidget(lineEditModello,2,1);
    layoutDatiComponente->addWidget(labelAnno,3,0);
    layoutDatiComponente->addWidget(lineEditAnno,3,1);
    layoutDatiComponente->addWidget(labelPressione,4,0);
    layoutDatiComponente->addWidget(lineEditPressione,4,1);
    layoutDatiComponente->addWidget(labelPortata_Capacità,5,0);
    layoutDatiComponente->addWidget(lineEditPortata_Capacità,5,1);
    layoutDatiComponente->addWidget(labelKw,6,0);
    layoutDatiComponente->addWidget(lineEditKw,6,1);

    // disabilito lineEdit
    lineEditMarca->setDisabled(true);
    lineEditModello->setDisabled(true);
    lineEditAnno->setDisabled(true);
    lineEditPressione->setDisabled(true);
    lineEditPortata_Capacità->setDisabled(true);
    lineEditKw->setDisabled(true);

    // associazione a layoutBottoni
    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneModifica);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneModifica,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciComponente()));
}

void FinestraVisualizzaComponente::apriFinestraInserisciComponente(){
    FinestraInserisciComponente finInsComp;
    this->close();
    finInsComp.exec();
}

void FinestraVisualizzaComponente::torna(){
    this->close();
}
