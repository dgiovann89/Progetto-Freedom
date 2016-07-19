#include "finestrainseriscisala.h"

FinestraInserisciSala::FinestraInserisciSala(DatabaseClienti* d, Cliente* c, QDialog *parent):QDialog(parent), dbc(d), cl(c){
    this->setWindowTitle("Finestra inserisci sala compressori");
    this->setMinimumSize(420,340);

    // new layout e groupbox
    layoutSfondo = new QVBoxLayout(this);
    layoutInfoSala = new QGridLayout();
    layoutBottoni = new QHBoxLayout();
    boxInfoSala = new QGroupBox(this);
    boxBottoni = new QGroupBox(this);

    // new label e lineEdit
    labelNomeSala = new QLabel("Nome Sala:");
    labelCliente = new QLabel("Cliente");
    labelStabilimento = new QLabel("Stablimento");
    labelPressioneRichiesta = new QLabel("Pressione richiesta (Bar):");
    labelPortataRichiesta = new QLabel("Portata richiesta (Lt/s):");
    lineEditNomeSala = new QLineEdit(this);
    lineEditCliente = new QLineEdit(QString::fromStdString(c->getRagioneSociale()));
    lineEditCliente->setDisabled(true);
    lineEditStabilimento = new QLineEdit(QString::fromStdString(c->getStabilimento()));
    lineEditStabilimento->setDisabled(true);
    lineEditPressioneRichiesta = new QLineEdit("0");
    lineEditPortataRichiesta = new QLineEdit("0");

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

    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneSalva);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
}

void FinestraInserisciSala::torna() {
    this->close();
}

void FinestraInserisciSala::salva(){
    if(lineEditNomeSala->text()!="" && lineEditPressioneRichiesta->text()!="" &&
            lineEditPortataRichiesta->text()!=""){

        SalaCompressori sala(lineEditNomeSala->text().toStdString(),
                             cl,
                             0,
                             0,
                             lineEditPressioneRichiesta->text().toFloat(),
                             lineEditPortataRichiesta->text().toInt(),
                             "Nessuno",
                             0
                             );

        cl->aggiungiSala(sala);
        QMessageBox messageBox(this);
        messageBox.setText("Dati inseriti correttamente");
        messageBox.exec();
        this->close();
    }
    else{
        QMessageBox messageBox(this);
        messageBox.setText("Compilare tutti i campi");
        messageBox.exec();
    }
}
