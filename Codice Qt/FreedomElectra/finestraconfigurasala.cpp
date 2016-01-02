#include "finestraconfigurasala.h"

FinestraConfiguraSala::FinestraConfiguraSala(QDialog *parent):QDialog(parent){
    this->setWindowTitle("Finestra Configurazione sala compressori");
    this->setMinimumSize(720,440);

    // new layout e groupBox
    layoutInfoSala = new QGridLayout(this);
    layoutTabella = new QVBoxLayout(this);
    layoutSinistra = new QVBoxLayout(this);
    layoutDestra = new QVBoxLayout(this);
    layoutBottoniFinestra = new QVBoxLayout(this);
    layoutBottoniTabella = new QHBoxLayout(this);
    layoutSfondo = new QHBoxLayout(this);
    layoutParametriSala = new QGridLayout();
    boxSinistra = new QGroupBox(this);
    boxDestra = new QGroupBox(this);
    boxInfoSala = new QGroupBox(this);
    boxTabella = new QGroupBox(this);
    boxBottoniTabella = new QGroupBox(this);
    boxBottoniFinestra = new QGroupBox(this);
    boxParametriSala = new QGroupBox(this);

    // new label e lineEdit
    labelInfoSala = new QLabel("Info Sala:");
    labelTabella = new QLabel("Componenti sala:");
    labelRagioneSociale = new QLabel("Ragione Sociale",this);
    lineEditRagioneSociale = new QLineEdit(this);
    labelStabilimento = new QLabel("Stabilimento",this);
    lineEditStabilimento = new QLineEdit(this);
    labelNomeSala = new QLabel("Nome Sala:",this);
    lineEditNomeSala = new QLineEdit(this);
    labelPressioneRichiesta = new QLabel("Pressione Richiesta:", this);
    lineEditPressioneRichiesta = new QLineEdit(this);
    labelPortataRichiesta = new QLabel("Portata Richiesta:", this);
    lineEditPortataRichiesta = new QLineEdit(this);
    labelImpianto = new QLabel("Impianto:",this);
    lineEditImpianto = new QLineEdit(this);
    labelKwTot = new QLabel("Kw Tot:",this);
    lineEditKwTot = new QLineEdit(this);
    labelPortatEffettiva = new QLabel("Portata effettiva:", this);
    lineEditPortataEffettiva = new QLineEdit(this);
    labelPressioneEffettiva = new QLabel("Pressione Effettiva:", this);
    lineEditPressioneEffettiva = new QLineEdit(this);
    labelCadutaDiPressioneTot = new QLabel("Caduta di pressione Totale:",this);
    lineEditCadutaDiPressioneTot = new QLineEdit(this);

    // new tabella
    tabellaComponenti = new QTableWidget(0,5);
    tabellaComponenti->setColumnWidth(0,250);
    QStringList header;
    header=QStringList() << "Nome" << "Stabilimento" << "Tipo Impianto" << "KW" << "Lt/minuto";
    tabellaComponenti->setHorizontalHeaderLabels(header);

    // new bottoni
    bottoneModificaSala=new QPushButton("Modifica Info Sala",this);
    bottoneInserisciComponente=new QPushButton("Inserisci componente",this);
    bottoneVisualizzaComponente=new QPushButton("Visualizza componente",this);
    bottoneEliminaComponente=new QPushButton("Elimina Componente",this);
    bottoneSalva=new QPushButton("Salva",this);
    bottoneEsportaPDF=new QPushButton("Esporta PDF",this);
    bottoneIndietro=new QPushButton("Torna indietro",this);

    // associazione box e layout
    layoutSfondo->addWidget(boxSinistra);
    layoutSfondo->addWidget(boxDestra);
    layoutSinistra->addWidget(boxInfoSala);
    layoutSinistra->addWidget(boxTabella);
    layoutSinistra->addWidget(boxBottoniTabella);
    layoutTabella->addWidget(boxParametriSala);
    layoutTabella->addWidget(boxBottoniFinestra);
    boxSinistra->setLayout(layoutSinistra);
    boxDestra->setLayout(layoutDestra);
    boxInfoSala->setLayout(layoutInfoSala);
    boxTabella->setLayout(layoutTabella);
    boxBottoniTabella->setLayout(layoutBottoniTabella);
    boxParametriSala->setLayout(layoutParametriSala);
    boxBottoniFinestra->setLayout(layoutBottoniFinestra);

    // associazion label e linedit a layoutCliente
    layoutInfoSala->addWidget(labelInfoSala);
    layoutInfoSala->addWidget(labelRagioneSociale,1,0);
    layoutInfoSala->addWidget(lineEditRagioneSociale,1,1);
    layoutInfoSala->addWidget(labelStabilimento,2,0);
    layoutInfoSala->addWidget(lineEditStabilimento,2,1);
    layoutInfoSala->addWidget(labelNomeSala,3,0);
    layoutInfoSala->addWidget(lineEditNomeSala,3,1);
    layoutInfoSala->addWidget(labelPressioneRichiesta,1,2);
    layoutInfoSala->addWidget(lineEditPressioneRichiesta,1,3);
    layoutInfoSala->addWidget(labelPortataRichiesta,2,2);
    layoutInfoSala->addWidget(lineEditPortataRichiesta,2,3);
    layoutInfoSala->addWidget(labelImpianto,3,2);
    layoutInfoSala->addWidget(lineEditImpianto,3,3);
    layoutInfoSala->addWidget(bottoneModificaSala,2,4);

    // associazione tabella a layoutTabella
    layoutTabella->addWidget(labelTabella);
    layoutTabella->addWidget(tabellaComponenti);

    // associazione sul layoutTabella dei bottoni
    layoutBottoniTabella->addWidget(bottoneInserisciComponente);
    layoutBottoniTabella->addWidget(bottoneVisualizzaComponente);
    layoutBottoniTabella->addWidget(bottoneEliminaComponente);

    layoutParametriSala->addWidget(labelKwTot);
    layoutParametriSala->addWidget(lineEditKwTot);
    layoutParametriSala->addWidget(labelPortatEffettiva);
    layoutParametriSala->addWidget(lineEditPortataEffettiva);
    layoutParametriSala->addWidget(labelCadutaDiPressioneTot);
    layoutParametriSala->addWidget(lineEditCadutaDiPressioneTot);
    layoutParametriSala->addWidget(labelPressioneEffettiva);
    layoutParametriSala->addWidget(lineEditPressioneEffettiva);

    this->setLayout(layoutSfondo);

    connect(bottoneModificaSala,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciSala()));
    connect(bottoneInserisciComponente,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciComponente()));
    connect(bottoneVisualizzaComponente,SIGNAL(clicked()),this,SLOT(apriFinestraVisualizzaComponente()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

void FinestraConfiguraSala::apriFinestraInserisciSala(){
    FinestraInserisciSala finInfoSala;
    finInfoSala.exec();
}

void FinestraConfiguraSala::apriFinestraInserisciComponente(){
    FinestraInserisciComponente finInsComp;
    finInsComp.exec();
}

void FinestraConfiguraSala::apriFinestraVisualizzaComponente(){
    FinestraVisualizzaComponente finVisComp;
    finVisComp.exec();
}

void FinestraConfiguraSala::torna(){
    this->close();
}
