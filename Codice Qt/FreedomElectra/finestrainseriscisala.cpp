#include "finestrainseriscisala.h"

FinestraInserisciSala::FinestraInserisciSala(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra inserisci sala compressori");
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
    lineEditNomeSala = new QLineEdit(this);
    lineEditCliente = new QLineEdit(this);
    lineEditStabilimento = new QLineEdit(this);
    lineEditPressioneRichiesta = new QLineEdit(this);
    lineEditPortataRichiesta = new QLineEdit(this);
    lineEditImpianto = new QLineEdit(this);

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
}

void FinestraInserisciSala::torna() {
    this->close();
}
