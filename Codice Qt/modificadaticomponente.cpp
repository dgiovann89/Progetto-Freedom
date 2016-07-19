#include "modificadaticomponente.h"

ModificaDatiComponente::ModificaDatiComponente(DatabaseComponenti* d, Componente* cp, QDialog *parent):QDialog(parent), db(d), c(cp){
    this->setWindowTitle("Modifica dati Componente");
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
    labelPressione = new QLabel("Pressione (Bar):");
    labelPortata_Capacita = new QLabel("Portata o Capacita (Lt/s):");
    labelCadDiPress = new QLabel("Caduta di pressione (Bar):");
    labelKw = new QLabel("Kw:");
    labelCapacita = new QLabel("Capacità:");
    labelnCartucce = new QLabel("Num Cartucce:");
    labelMateriale = new QLabel("Materiale:");
    labelOreCarico = new QLabel("Ore a carico:");
    labelOreVuoto = new QLabel("Ore a vuoto:");
    lineEditMarca = new QLineEdit(QString::fromStdString(c->getMarca()));
    lineEditModello = new QLineEdit(QString::fromStdString(c->getModello()));
    lineEditAnno = new QLineEdit(QString::number(c->getAnno()));
    lineEditPressione = new QLineEdit(QString::number(c->getPressione()));
    lineEditPortata = new QLineEdit(QString::number(c->getPortata()));
    lineeditCadDiPress = new QLineEdit(QString::number(c->getCadutaDiPressione()));
    lineEditCapacita = new QLineEdit("0");
    lineEditnCartucce = new QLineEdit("0");
    lineeditMateriale = new QLineEdit("");
    lineEditOreCarico = new QLineEdit("0");
    lineEditOreVuoto = new QLineEdit("0");

    Macchinario* comp = dynamic_cast <Macchinario*>  (c);
    if (comp){
        lineEditKw = new QLineEdit(QString::number(comp->getKw()));
    }
    else{
        labelKw->setDisabled(true);
        lineEditKw = new QLineEdit(this);
        lineEditKw->setDisabled(true);
    }

    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneSalva = new QPushButton("Salva",this);
    lineEditTipo = new QLineEdit(QString::fromStdString(c->getTypeInfo()));
    lineEditTipo->setDisabled(true);

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
    layoutDatiComponente->addWidget(labelPortata_Capacita,5,0);
    layoutDatiComponente->addWidget(lineEditPortata,5,1);
    layoutDatiComponente->addWidget(labelCadDiPress,6,0);
    layoutDatiComponente->addWidget(lineeditCadDiPress,6,1);
    layoutDatiComponente->addWidget(labelKw,7,0);
    layoutDatiComponente->addWidget(lineEditKw,7,1);
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
    layoutBottoni->addWidget(bottoneSalva);

    OnOff* on = dynamic_cast<OnOff*>(c);
    VelocitaVariabile* vel = dynamic_cast<VelocitaVariabile*>(c);
    Filtro* f = dynamic_cast<Filtro*>(c);
    Serbatoio* s = dynamic_cast<Serbatoio*>(c);
    Impianto* i = dynamic_cast<Impianto*>(c);

    if (on){
        lineeditMateriale->setDisabled(true);
        lineEditnCartucce->setDisabled(true);
        lineEditCapacita->setDisabled(true);
    }
    if (vel){
        lineeditMateriale->setDisabled(true);
        lineEditnCartucce->setDisabled(true);
        lineEditCapacita->setDisabled(true);
        lineEditOreVuoto->setDisabled(true);
    }
    if (f){
        lineEditKw->setDisabled(true);
        lineeditMateriale->setDisabled(true);
        lineEditCapacita->setDisabled(true);
        lineEditOreCarico->setDisabled(true);
        lineEditOreVuoto->setDisabled(true);
    }
    if (s){
        lineEditKw->setDisabled(true);
        lineeditMateriale->setDisabled(true);
        lineEditOreCarico->setDisabled(true);
        lineEditOreVuoto->setDisabled(true);
    }

    if (i){
        lineEditKw->setDisabled(true);
        lineEditCapacita->setDisabled(true);
        lineEditOreCarico->setDisabled(true);
        lineEditOreVuoto->setDisabled(true);
    }


    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
}

void ModificaDatiComponente::salva(){
    if (lineEditMarca->text()!=""){
        // setto i campi comuni di componente
        c->setMarca(lineEditMarca->text().toStdString());
        c->setModello(lineEditModello->text().toStdString());
        c->setAnno(lineEditAnno->text().toInt());
        c->setPressione(lineEditPressione->text().toFloat());
        c->setPortata(lineEditPortata->text().toInt());
        c->setCadutaDiPressione(lineeditCadDiPress->text().toFloat());
        OnOff* on = dynamic_cast<OnOff*>(c);
        VelocitaVariabile* vel = dynamic_cast<VelocitaVariabile*>(c);
        Filtro* f = dynamic_cast<Filtro*>(c);
        Serbatoio* s = dynamic_cast<Serbatoio*>(c);
        Impianto* i = dynamic_cast<Impianto*>(c);
        if (on){
            on->setKw(lineEditKw->text().toInt());
            on->setOreCarico(lineEditOreCarico->text().toInt());
            on->setOreVuoto(lineEditOreVuoto->text().toInt());
            lineeditMateriale->setDisabled(true);
            lineEditnCartucce->setDisabled(true);
            lineEditCapacita->setDisabled(true);
        }
        else{
            if (vel){
                on->setKw(lineEditKw->text().toInt());
                on->setOreCarico(lineEditOreCarico->text().toInt());
            }
            else
                if (f)
                    f->setnCartucce(lineEditnCartucce->text().toInt());
                else
                    if (s)
                        s->setCapacita(lineEditCapacita->text().toInt());
                    else
                        i->setMateriale(lineeditMateriale->text().toStdString());
        }
        QMessageBox messageBox(this);
        messageBox.setText("Dati aggiornati correttamente");
        messageBox.exec();
        this->close();
    }

    else{
        QMessageBox messageBox(this);
        messageBox.setText("Compilare tutti i campi");
        messageBox.exec();
    }
}

void ModificaDatiComponente::torna(){
    this->close();
}
