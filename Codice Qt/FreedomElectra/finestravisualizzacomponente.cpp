#include "finestravisualizzacomponente.h"

FinestraVisualizzaComponente::FinestraVisualizzaComponente(DatabaseComponenti* d, Componente* cp, QDialog *parent):QDialog(parent), db(d), c(cp){
    this->setWindowTitle("Finestra Visualizza Componente");
    this->setMinimumSize(340,340);

    // new
    layoutSfondo=new QVBoxLayout(this);
    layoutDatiComponente = new QGridLayout();
    layoutBottoni = new QHBoxLayout();
    boxDatiComponente = new QGroupBox(this);
//    boxDatiComponente->setDisabled(true);
    boxBottoni = new QGroupBox(this);

    labelTipo = new QLabel("Tipo:");
    labelMarca=new QLabel("Marca:");
    labelModello = new QLabel("Modello:");
    labelAnno = new QLabel("Anno:");
    labelPressione = new QLabel("Pressione: (Bar)");
    labelPortata_Capacita = new QLabel("Portata o Capacita (Lt/s):");
    labelKw = new QLabel("Kw:");
    labelCdP = new QLabel("Caduta di Pressione (Bar):");

//    lineEditTipo = new QLineEdit(comboBoxTipo->currentText());
    lineEditTipo = new QLineEdit(QString::fromStdString(c->getTipo()));
    lineEditTipo->setDisabled(true);
    lineEditMarca = new QLineEdit(QString::fromStdString(c->getMarca()));
    lineEditMarca->setDisabled(true);
    lineEditModello = new QLineEdit(QString::fromStdString(c->getModello()));
    lineEditModello->setDisabled(true);
    lineEditAnno = new QLineEdit(QString::number(c->getAnno()));
    lineEditAnno->setDisabled(true);
    lineEditPressione = new QLineEdit(QString::number(c->getPressione()));
    lineEditPressione->setDisabled(true);
    lineEditPortata_Capacita = new QLineEdit(QString::number(c->getPortata_capacita()));
    lineEditPortata_Capacita->setDisabled(true);
    lineEditCdP = new QLineEdit(QString::number(c->getCadutaDiPressione()));
    lineEditCdP->setDisabled(true);


//    lineEditKw = new QLineEdit(this);
//    lineEditKw->setDisabled(true);
    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneModifica = new QPushButton("Modifica",this);
//    comboBoxTipo = new QComboBox(this);

//    // set comboBox
//    QStringList list= (QStringList()<< "Compressore On-Off"<< "Compressorie Vel variable"<< "Essiccatore On-Off" << "Essiccatore Vel variabile" << "Impianto" << "Filtro" << "Serbatoio");
//    comboBoxTipo->addItems(list);

    const Macchinario* comp = dynamic_cast <const Macchinario*>  (c);
    if (comp){
        lineEditKw = new QLineEdit(QString::number(comp->getKw()));
        lineEditKw->setDisabled(true);
    }
    else{
        lineEditKw = new QLineEdit(this);
        lineEditKw->setDisabled(true);
    }
    // associazione box e layout
    layoutSfondo->addWidget(boxDatiComponente);
    layoutSfondo->addWidget(boxBottoni);
    boxDatiComponente->setLayout(layoutDatiComponente);
    boxBottoni->setLayout(layoutBottoni);

    // associazione a layoutDatiComponente
    layoutDatiComponente->addWidget(labelTipo,0,0);
//    layoutDatiComponente->addWidget(comboBoxTipo,0,1);
    layoutDatiComponente->addWidget(lineEditTipo,0,1);
    layoutDatiComponente->addWidget(labelMarca,1,0);
    layoutDatiComponente->addWidget(lineEditMarca,1,1);
    layoutDatiComponente->addWidget(labelModello,2,0);
    layoutDatiComponente->addWidget(lineEditModello,2,1);
    layoutDatiComponente->addWidget(labelAnno,3,0);
    layoutDatiComponente->addWidget(lineEditAnno,3,1);
    layoutDatiComponente->addWidget(labelPressione,4,0);
    layoutDatiComponente->addWidget(lineEditPressione,4,1);
    layoutDatiComponente->addWidget(labelPortata_Capacita,5,0);
    layoutDatiComponente->addWidget(lineEditPortata_Capacita,5,1);
    layoutDatiComponente->addWidget(labelKw,6,0);
    layoutDatiComponente->addWidget(lineEditKw,6,1);
    layoutDatiComponente->addWidget(labelCdP,7,0);
    layoutDatiComponente->addWidget(lineEditCdP,7,1);

    // associazione a layoutBottoni
    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneModifica);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneModifica,SIGNAL(clicked()),this,SLOT(apriModificaDatiComponente()));
}

void FinestraVisualizzaComponente::apriModificaDatiComponente(){
    ModificaDatiComponente modDatiCompo(db,c);
    this->close();
    modDatiCompo.exec();
}

void FinestraVisualizzaComponente::torna(){
    this->close();
}
