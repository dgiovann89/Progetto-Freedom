#include "finestraconfigurasala.h"

FinestraConfiguraSala::FinestraConfiguraSala(DatabaseClienti* d, Cliente* c, SalaCompressori* sl, QDialog *parent): dbc(d), cl(c), sala(sl), QDialog(parent){
    db = new DatabaseComponenti();

    this->setWindowTitle("Finestra Configurazione sala compressori");
    this->setMinimumSize(1020,540);

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
    lineEditRagioneSociale = new QLineEdit(QString::fromStdString(cl->getRagioneSociale()));
    labelStabilimento = new QLabel("Stabilimento",this);
    lineEditStabilimento = new QLineEdit(QString::fromStdString(cl->getStabilimento()));
    labelNomeSala = new QLabel("Nome Sala:",this);
    lineEditNomeSala = new QLineEdit(QString::fromStdString(sala->getNome()));
    labelPressioneRichiesta = new QLabel("Pressione Richiesta:", this);
    lineEditPressioneRichiesta = new QLineEdit(QString::number(sala->getPressioneRichiesta()));
    labelPortataRichiesta = new QLabel("Portata Richiesta:", this);
    lineEditPortataRichiesta = new QLineEdit(QString::number(sala->getPortataRichiesta()));
    labelImpianto = new QLabel("Impianto:",this);
    lineEditImpianto = new QLineEdit(QString::fromStdString(sala->getImpianto()));
    labelKwTot = new QLabel("Kw Tot:",this);
    lineEditKwTot = new QLineEdit(QString::number(sala->getKwTot()));
    labelPortatEffettiva = new QLabel("Portata effettiva:", this);
    lineEditPortataEffettiva = new QLineEdit(this);
    labelPressioneEffettiva = new QLabel("Pressione Effettiva:", this);
    lineEditPressioneEffettiva = new QLineEdit(this);
    labelCadutaDiPressioneTot = new QLabel("Caduta di pressione Totale:",this);
    lineEditCadutaDiPressioneTot = new QLineEdit(this);

    // disabilito le lineEdit del cliente
    lineEditNomeSala->setDisabled(true);
    lineEditImpianto->setDisabled(true);
    lineEditPortataRichiesta->setDisabled(true);
    lineEditPressioneRichiesta->setDisabled(true);
    lineEditRagioneSociale->setDisabled(true);
    lineEditStabilimento->setDisabled(true);

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
    // sinistra
    boxSinistra->setLayout(layoutSinistra);
        layoutSinistra->addWidget(boxInfoSala);
        boxInfoSala->setLayout(layoutInfoSala);
        // associazione tabella a layoutTabella
        layoutSinistra->addWidget(boxTabella);
        boxTabella->setLayout(layoutTabella);
        layoutTabella->addWidget(labelTabella);
        layoutTabella->addWidget(tabellaComponenti);
        // associazione boxTabella, layoutTabella dei bottoni
        layoutSinistra->addWidget(boxBottoniTabella);
        boxBottoniTabella->setLayout(layoutBottoniTabella);
        layoutBottoniTabella->addWidget(bottoneInserisciComponente);
        layoutBottoniTabella->addWidget(bottoneVisualizzaComponente);
        layoutBottoniTabella->addWidget(bottoneEliminaComponente);
    //destra
    boxDestra->setLayout(layoutDestra);
        layoutDestra->addWidget(boxParametriSala);
        boxParametriSala->setLayout(layoutParametriSala);
        layoutDestra->addWidget(boxBottoniFinestra);
        boxBottoniFinestra->setLayout(layoutBottoniFinestra);
        layoutBottoniFinestra->addWidget(bottoneSalva);
        layoutBottoniFinestra->addWidget(bottoneEsportaPDF);
        layoutBottoniFinestra->addWidget(bottoneIndietro);

    // associazion label e lineEdit a layoutCliente
    layoutInfoSala->addWidget(labelInfoSala,0,0);
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

    layoutParametriSala->addWidget(labelKwTot,0,0);
    layoutParametriSala->addWidget(lineEditKwTot,0,1);
    layoutParametriSala->addWidget(labelPortatEffettiva,1,0);
    layoutParametriSala->addWidget(lineEditPortataEffettiva,1,1);
    layoutParametriSala->addWidget(labelCadutaDiPressioneTot,2,0);
    layoutParametriSala->addWidget(lineEditCadutaDiPressioneTot,2,1);
    layoutParametriSala->addWidget(labelPressioneEffettiva,3,0);
    layoutParametriSala->addWidget(lineEditPressioneEffettiva,3,1);

    this->setLayout(layoutSfondo);

//    connect(bottoneModificaSala,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciSala()));
    connect(bottoneInserisciComponente,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciComponente()));
    connect(bottoneVisualizzaComponente,SIGNAL(clicked()),this,SLOT(apriFinestraVisualizzaComponente()));
    connect(bottoneEliminaComponente,SIGNAL(clicked()),this,SLOT(eliminaComponente()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));

}

void FinestraConfiguraSala::eliminaComponente(){
    if (tabellaComponenti->selectedItems().isEmpty());
}

//void FinestraConfiguraSala::apriFinestraInserisciSala(){
//    FinestraInserisciSala finInfoSala();
//    finInfoSala.exec();
//}

void FinestraConfiguraSala::apriFinestraInserisciComponente(){
    FinestraInserisciComponente finInsComp(db,this);
    finInsComp.exec();
}

void FinestraConfiguraSala::apriFinestraVisualizzaComponente(){
    FinestraVisualizzaComponente finVisComp(db,this);
    finVisComp.exec();
}

void FinestraConfiguraSala::torna(){
    this->close();
}
