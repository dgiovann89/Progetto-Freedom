#include "modificainfosala.h"

ModificaInfoSala::ModificaInfoSala(DatabaseClienti* d, Cliente* c, SalaCompressori* s, QDialog *parent):QDialog(parent), dbc(d), cl(c), sala(s){
    this->setWindowTitle("Finestra Modifica info sala compressori");
    this->setMinimumSize(420,340);

    // new layout e groupbox
    layoutSfondo = new QVBoxLayout(this);
    layoutInfoSala = new QGridLayout();
    layoutBottoni = new QHBoxLayout(this);
    boxInfoSala = new QGroupBox(this);
    boxBottoni = new QGroupBox(this);

    // new label e lineEdit
    labelNomeSala = new QLabel("Nome Sala:");
    labelCliente = new QLabel("Cliente");
    labelStabilimento = new QLabel("Stablimento");
    labelPressioneRichiesta = new QLabel("Pressione richiesta:");
    labelPortataRichiesta = new QLabel("Portata richiesta:");
    labelImpianto = new QLabel("Impianto:");
    lineEditNomeSala = new QLineEdit(QString::fromStdString(sala->getNome()));
    lineEditCliente = new QLineEdit(QString::fromStdString(cl->getRagioneSociale()));
    lineEditCliente->setDisabled(true);
    lineEditStabilimento = new QLineEdit(QString::fromStdString(c->getStabilimento()));
    lineEditStabilimento->setDisabled(true);
    lineEditPressioneRichiesta = new QLineEdit(QString::number(sala->getPressioneRichiesta()));
    lineEditPortataRichiesta = new QLineEdit(QString::number(sala->getPortataRichiesta()));
    lineEditImpianto = new QLineEdit(QString::fromStdString(sala->getImpianto()));

    // new bottoni
    bottoneIndietro = new QPushButton("Indietro",this);
    bottoneSalva = new QPushButton("Salva",this);

    // associazioni box e layout
    boxInfoSala->setLayout(layoutInfoSala);
    boxBottoni->setLayout(layoutBottoni);
    layoutSfondo->addWidget(boxInfoSala);
    layoutSfondo->addWidget(boxBottoni);

    // associazioni label e lineedit a layout
    layoutInfoSala->addWidget(labelNomeSala);
    layoutInfoSala->addWidget(lineEditNomeSala);
    layoutInfoSala->addWidget(labelCliente);
    layoutInfoSala->addWidget(lineEditCliente);
    layoutInfoSala->addWidget(labelStabilimento);
    layoutInfoSala->addWidget(lineEditStabilimento);
    layoutInfoSala->addWidget(labelPressioneRichiesta);
    layoutInfoSala->addWidget(lineEditPressioneRichiesta);
    layoutInfoSala->addWidget(labelPortataRichiesta);
    layoutInfoSala->addWidget(lineEditPortataRichiesta);
    layoutInfoSala->addWidget(labelImpianto);
    layoutInfoSala->addWidget(lineEditImpianto);

    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneSalva);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
}

void ModificaInfoSala::torna() {
    this->close();
}

void ModificaInfoSala::salva(){

    if(lineEditNomeSala->text()!="" && lineEditPressioneRichiesta->text()!="" &&
       lineEditPortataRichiesta->text()!="" && lineEditImpianto->text()!=""){
        sala->setNome(lineEditNomeSala->text().toStdString());
        sala->setPortataRichiesta(lineEditPortataRichiesta->text().toInt());
        sala->setPressioneRichiesta(lineEditPressioneRichiesta->text().toInt());
        sala->setImpianto(lineEditImpianto->text().toStdString());

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
