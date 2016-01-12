#include "modificadaticomponente.h"

ModificaDatiComponente::ModificaDatiComponente(DatabaseComponenti* d, Componente* cp, QDialog *parent):QDialog(parent), db(d), c(cp){
    this->setWindowTitle("Modifica dati Componente");
    this->setMinimumSize(340,340);

    // new
    layoutSfondo=new QVBoxLayout(this);
    layoutDatiComponente = new QGridLayout();
    layoutBottoni = new QHBoxLayout(this);
    boxDatiComponente = new QGroupBox(this);
//    boxDatiComponente->setDisabled(true);
    boxBottoni = new QGroupBox(this);
    labelTipo = new QLabel("Tipo:");
    labelMarca=new QLabel("Marca:");
    labelModello = new QLabel("Modello:");
    labelAnno = new QLabel("Anno:");
    labelPressione = new QLabel("Pressione:");
    labelPortata_Capacità = new QLabel("Portata o Capacità:");
    labelKw = new QLabel("Kw:");
    lineEditMarca = new QLineEdit(QString::fromStdString(c->getMarca()));
    lineEditModello = new QLineEdit(QString::fromStdString(c->getModello()));
    lineEditAnno = new QLineEdit(QString::number(c->getAnno()));
    lineEditPressione = new QLineEdit(QString::number(c->getPressione()));
    lineEditPortata_Capacità = new QLineEdit(QString::number(c->getPortata_capacità()));
    lineEditKw = new QLineEdit(this);
    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneSalva = new QPushButton("Salva",this);
    comboBoxTipo = new QComboBox();
    comboBoxTipo->setDisabled(true);

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
//    lineEditMarca->setDisabled(false);
//    lineEditModello->setDisabled(false);
//    lineEditAnno->setDisabled(false);
//    lineEditPressione->setDisabled(false);
//    lineEditPortata_Capacità->setDisabled(false);
//    lineEditKw->setDisabled(false);

    // associazione a layoutBottoni
    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneSalva);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
}

void ModificaDatiComponente::salva(){
    if (lineEditMarca->text()!=""){
    c->setMarca(lineEditMarca->text().toStdString());
    c->setModello(lineEditModello->text().toStdString());
    c->setAnno(lineEditAnno->text().toInt());
    c->setPressione(lineEditPressione->text().toInt());
    c->setPortata_capacità(lineEditPortata_Capacità->text().toInt());
//    if (c->getTipo()=="OnOff")
//        c->setKw();
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
