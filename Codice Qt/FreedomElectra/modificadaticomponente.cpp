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
    labelPortata_Capacita = new QLabel("Portata o Capacita:");
    labelCadDiPress = new QLabel("Caduta di pressione:");
    labelKw = new QLabel("Kw:");
    lineEditMarca = new QLineEdit(QString::fromStdString(c->getMarca()));
    lineEditModello = new QLineEdit(QString::fromStdString(c->getModello()));
    lineEditAnno = new QLineEdit(QString::number(c->getAnno()));
    lineEditPressione = new QLineEdit(QString::number(c->getPressione()));
    lineEditPortata_Capacita = new QLineEdit(QString::number(c->getPortata_capacita()));
    lineeditCadDiPress = new QLineEdit(QString::number(c->getCadutaDiPressione()));

    Macchinario* comp = dynamic_cast <Macchinario*>  (c);
    if (comp){
        cout << "è un macchinario" << endl;
        lineEditKw = new QLineEdit(QString::number(comp->getKw()));
    }
    else{
        labelKw->setDisabled(true);
        lineEditKw = new QLineEdit(this);
        lineEditKw->setDisabled(true);
        cout << "NON è un macchinario" << endl;
    }

    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneSalva = new QPushButton("Salva",this);
    lineEditTipo = new QLineEdit(QString::fromStdString(c->getTipo()));
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
    layoutDatiComponente->addWidget(lineEditPortata_Capacita,5,1);
    layoutDatiComponente->addWidget(labelCadDiPress,6,0);
    layoutDatiComponente->addWidget(lineeditCadDiPress,6,1);
    layoutDatiComponente->addWidget(labelKw,7,0);
    layoutDatiComponente->addWidget(lineEditKw,7,1);

    // associazione a layoutBottoni
    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneSalva);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
}

void ModificaDatiComponente::salva(){
    if (lineEditMarca->text()!=""){
        Macchinario* comp = dynamic_cast <Macchinario*>  (c);
        if (comp){
            cout << "comp" << endl;
            comp->setMarca(lineEditMarca->text().toStdString());
            comp->setModello(lineEditModello->text().toStdString());
            comp->setAnno(lineEditAnno->text().toInt());
            comp->setPressione(lineEditPressione->text().toInt());
            comp->setPortata_capacita(lineEditPortata_Capacita->text().toInt());
            comp->setCadutaDiPressione(lineeditCadDiPress->text().toInt());
            comp->setKw(lineEditKw->text().toInt());
        }
        else{
            c->setMarca(lineEditMarca->text().toStdString());
            c->setModello(lineEditModello->text().toStdString());
            c->setAnno(lineEditAnno->text().toInt());
            c->setPressione(lineEditPressione->text().toInt());
            c->setPortata_capacita(lineEditPortata_Capacita->text().toInt());
            c->setCadutaDiPressione(lineeditCadDiPress->text().toInt());
            cout << "NON è un macchinario" << endl;
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
