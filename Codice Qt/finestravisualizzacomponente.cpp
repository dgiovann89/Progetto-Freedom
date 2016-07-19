#include "finestravisualizzacomponente.h"

FinestraVisualizzaComponente::FinestraVisualizzaComponente(DatabaseComponenti* d, Componente* cp, QDialog *parent):QDialog(parent), db(d), c(cp){
    this->setWindowTitle("Finestra Visualizza Componente");
    this->setMinimumSize(340,340);

    // new
    layoutSfondo=new QVBoxLayout(this);
    layoutDatiComponente = new QGridLayout();
    layoutBottoni = new QHBoxLayout();
    boxDatiComponente = new QGroupBox(this);
    boxBottoni = new QGroupBox(this);

    labelTipo = new QLabel("Tipo:");
    labelMarca=new QLabel("Marca:");
    labelModello = new QLabel("Modello:");
    labelAnno = new QLabel("Anno:");
    labelPressione = new QLabel("Pressione: (Bar)");
    labelPortata = new QLabel("Portata: ");
    labelKw = new QLabel("Kw:");
    labelCdP = new QLabel("Caduta di Pressione (Bar):");
    labelCapacita = new QLabel("Capacità:");
    labelnCartucce = new QLabel("Num Cartucce:");
    labelMateriale = new QLabel("Materiale:");
    labelOreCarico = new QLabel("Ore a carico:");
    labelOreVuoto = new QLabel("Ore a vuoto:");

    lineEditTipo = new QLineEdit(QString::fromStdString(c->getTypeInfo()));
    lineEditTipo->setDisabled(true);
    lineEditMarca = new QLineEdit(QString::fromStdString(c->getMarca()));
    lineEditMarca->setDisabled(true);
    lineEditModello = new QLineEdit(QString::fromStdString(c->getModello()));
    lineEditModello->setDisabled(true);
    lineEditAnno = new QLineEdit(QString::number(c->getAnno()));
    lineEditAnno->setDisabled(true);
    lineEditPressione = new QLineEdit(QString::number(c->getPressione()));
    lineEditPressione->setDisabled(true);
    lineEditPortata = new QLineEdit(QString::number(c->getPortata()));
    lineEditPortata->setDisabled(true);
    lineEditCdP = new QLineEdit(QString::number(c->getCadutaDiPressione()));
    lineEditCdP->setDisabled(true);
    lineEditCapacita = new QLineEdit("0");
    lineEditnCartucce = new QLineEdit("1");
    lineeditMateriale = new QLineEdit("Materiale");
    lineEditOreCarico = new QLineEdit("0");
    lineEditOreVuoto = new QLineEdit("0");
    lineEditnCartucce->setDisabled(true);
    lineEditCapacita->setDisabled(true);
    lineeditMateriale->setDisabled(true);
    lineEditOreCarico->setDisabled(true);
    lineEditOreVuoto->setDisabled(true);

    Filtro* f = dynamic_cast<Filtro*>(c);
    if (f){
        lineEditnCartucce = new QLineEdit(QString::number(f->getnCartucce()));
        lineEditnCartucce->setDisabled(true);
    }

    Serbatoio* s = dynamic_cast<Serbatoio*>(c);
    if (s){
        lineEditCapacita = new QLineEdit(QString::number(s->getCapacita()));
        lineEditCapacita->setDisabled(true);
    }

    Impianto* i = dynamic_cast<Impianto*>(c);
    if (i){
        lineeditMateriale = new QLineEdit(QString::fromStdString(i->getMateriale()));
        lineeditMateriale->setDisabled(true);
    }

    const Macchinario* comp = dynamic_cast <const Macchinario*>  (c);
    if (comp){
        lineEditKw = new QLineEdit(QString::number(comp->getKw()));
        lineEditKw->setDisabled(true);
    }
    else{
        lineEditKw = new QLineEdit(this);
        lineEditKw->setDisabled(true);
    }

    OnOff* on = dynamic_cast<OnOff*>(c);
    if (on){
        lineEditOreCarico = new QLineEdit(QString::number(on->getOreCarico()));
        lineEditOreVuoto = new QLineEdit(QString::number(on->getOreVuoto()));
        lineEditOreCarico->setDisabled(true);
        lineEditOreVuoto->setDisabled(true);
    }

    VelocitaVariabile* vel = dynamic_cast<VelocitaVariabile*>(c);
    if (vel){
        lineEditOreCarico = new QLineEdit(QString::number(vel->getOreCarico()));
        lineEditOreCarico->setDisabled(true);
    }


    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneModifica = new QPushButton("Modifica",this);

    // associazione box e layout
    layoutSfondo->addWidget(boxDatiComponente);
    layoutSfondo->addWidget(boxBottoni);
    boxDatiComponente->setLayout(layoutDatiComponente);
    boxBottoni->setLayout(layoutBottoni);

    // associazione a layoutDatiComponente
    layoutDatiComponente->addWidget(labelTipo,0,0);
    layoutDatiComponente->addWidget(lineEditTipo,0,1);
    layoutDatiComponente->addWidget(labelMarca,1,0);
    layoutDatiComponente->addWidget(lineEditMarca,1,1);
    layoutDatiComponente->addWidget(labelModello,2,0);
    layoutDatiComponente->addWidget(lineEditModello,2,1);
    layoutDatiComponente->addWidget(labelAnno,3,0);
    layoutDatiComponente->addWidget(lineEditAnno,3,1);
    layoutDatiComponente->addWidget(labelPressione,4,0);
    layoutDatiComponente->addWidget(lineEditPressione,4,1);
    layoutDatiComponente->addWidget(labelPortata,5,0);
    layoutDatiComponente->addWidget(lineEditPortata,5,1);
    layoutDatiComponente->addWidget(labelKw,6,0);
    layoutDatiComponente->addWidget(lineEditKw,6,1);
    layoutDatiComponente->addWidget(labelCdP,7,0);
    layoutDatiComponente->addWidget(lineEditCdP,7,1);
    layoutDatiComponente->addWidget(labelCapacita,8,0);
    layoutDatiComponente->addWidget(lineEditCapacita,8,1);
    layoutDatiComponente->addWidget(labelnCartucce,9,0);
    layoutDatiComponente->addWidget(lineEditnCartucce,9,1);
    layoutDatiComponente->addWidget(labelMateriale,10,0);
    layoutDatiComponente->addWidget(lineeditMateriale,10,1);
    layoutDatiComponente->addWidget(labelOreCarico,11,0);
    layoutDatiComponente->addWidget(lineEditOreCarico,11,1);
    layoutDatiComponente->addWidget(labelOreVuoto,12,0);
    layoutDatiComponente->addWidget(lineEditOreVuoto,12,1);


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
