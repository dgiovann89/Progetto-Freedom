#include "finestraconfigurasala.h"

FinestraConfiguraSala::FinestraConfiguraSala(DatabaseClienti* d, Cliente* c, SalaCompressori* sl, QDialog *parent): QDialog(parent), dbc(d), cl(c), sala(sl) {
    db = new DatabaseComponenti();

    this->setWindowTitle("Finestra Configurazione sala compressori");
    this->setMinimumSize(1200,600);

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
    tabellaComponenti = new QTableWidget(0,6);
    tabellaComponenti->setColumnWidth(0,250);
    QStringList header;
    header=QStringList() << "Marca" << "Modello" << "Anno" << "Pressione" << "Portata/Capacita" << "Caduta di pressione";
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
    layoutInfoSala->addWidget(labelNomeSala,1,2);
    layoutInfoSala->addWidget(lineEditNomeSala,1,3);
    layoutInfoSala->addWidget(labelPressioneRichiesta,2,2);
    layoutInfoSala->addWidget(lineEditPressioneRichiesta,2,3);
    layoutInfoSala->addWidget(labelPortataRichiesta,1,4);
    layoutInfoSala->addWidget(lineEditPortataRichiesta,1,5);
    layoutInfoSala->addWidget(labelImpianto,2,4);
    layoutInfoSala->addWidget(lineEditImpianto,2,5);
    layoutInfoSala->addWidget(bottoneModificaSala,1,6);

    layoutParametriSala->addWidget(labelKwTot,0,0);
    layoutParametriSala->addWidget(lineEditKwTot,0,1);
    layoutParametriSala->addWidget(labelPortatEffettiva,1,0);
    layoutParametriSala->addWidget(lineEditPortataEffettiva,1,1);
    layoutParametriSala->addWidget(labelCadutaDiPressioneTot,2,0);
    layoutParametriSala->addWidget(lineEditCadutaDiPressioneTot,2,1);
    layoutParametriSala->addWidget(labelPressioneEffettiva,3,0);
    layoutParametriSala->addWidget(lineEditPressioneEffettiva,3,1);

    this->setLayout(layoutSfondo);

    riempiTabellaComponenti();

    connect(bottoneModificaSala,SIGNAL(clicked()),this,SLOT(apriModificaInfoSala()));
    connect(bottoneInserisciComponente,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciComponente()));
    connect(bottoneVisualizzaComponente,SIGNAL(clicked()),this,SLOT(apriFinestraVisualizzaComponente()));
    connect(bottoneEliminaComponente,SIGNAL(clicked()),this,SLOT(eliminaComponente()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
}

// metodo privato riempiTabellaComponenti
void FinestraConfiguraSala::riempiTabellaComponenti(){
    int row = tabellaComponenti->rowCount();
//    cout << "rowwasdasdasdasd:" << row;
//    cout << sala->getComponenti().size() << endl;

    for (unsigned int i=0; i<sala->getComponenti().size();++i){
        tabellaComponenti->setRowCount(row+1);
        QTableWidgetItem* itemMarca= new QTableWidgetItem (QString::fromStdString(sala->getComponente(i)->getMarca()));
        tabellaComponenti->setItem(row, 0, itemMarca);
        itemMarca->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemModello= new QTableWidgetItem (QString::fromStdString(sala->getComponente(i)->getModello()));
        tabellaComponenti->setItem(row, 1, itemModello);
        itemModello->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemAnno= new QTableWidgetItem (QString::number(sala->getComponente(i)->getAnno()));
        tabellaComponenti->setItem(row, 2, itemAnno);
        itemAnno->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemPressione= new QTableWidgetItem (QString::number(sala->getComponente(i)->getPressione()));
        tabellaComponenti->setItem(row, 3, itemPressione);
        itemPressione->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemPortata_Capacita= new QTableWidgetItem (QString::number(sala->getComponente(i)->getPortata_capacita()));
        tabellaComponenti->setItem(row, 4, itemPortata_Capacita);
        itemPortata_Capacita->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemCadDiPress= new QTableWidgetItem (QString::number(sala->getComponente(i)->getCadutaDiPressione()));
        tabellaComponenti->setItem(row, 5, itemCadDiPress);
        itemCadDiPress->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        row++;

//        if (Q) // manca da settare i kw!!!!
//        QTableWidgetItem* itemKw= new QTableWidgetItem (QString::fromStdString(sala->getComponente(i)-));
//        tabellaComponenti->setItem(row, 6, itemKw);
//        itemKw->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    }
}

void FinestraConfiguraSala::eliminaComponente(){
    if (tabellaComponenti->currentItem()!= 0){
           int riga=tabellaComponenti->currentRow();

           Componente* r=*(db->cercaComponente(tabellaComponenti->item(riga,0)->text().toStdString()));

           if(r){
               db->rimuoviComponente(r); //rimuove dal contenitore
               sala->rimuoviComponente(riga); //rimuove dal vector
           }

       tabellaComponenti->clearContents();
       tabellaComponenti->setRowCount(0);
       riempiTabellaComponenti();
       }

}

void FinestraConfiguraSala::apriModificaInfoSala(){
    ModificaInfoSala modInfoSala(dbc,cl,sala);
    modInfoSala.exec();
    // aggiorna anagrafica cliente nella finestra
    lineEditNomeSala->setText(QString::fromStdString(sala->getNome()));
    lineEditPortataRichiesta->setText(QString::number(sala->getPortataRichiesta()));
    lineEditPressioneRichiesta->setText(QString::number(sala->getPressioneRichiesta()));
    lineEditImpianto->setText(QString::fromStdString(sala->getImpianto()));
}

void FinestraConfiguraSala::apriFinestraInserisciComponente(){
    FinestraInserisciComponente finInsComp(db,cl,sala);
    finInsComp.exec();
    tabellaComponenti->clearContents();
    tabellaComponenti->setRowCount(0);
    riempiTabellaComponenti();
}

void FinestraConfiguraSala::apriFinestraVisualizzaComponente(){
//    if(!(tabellaComponenti->selectedItems().isEmpty())){
//        Componente* c;
//        int riga = tabellaComponenti->currentRow();
//        c = (sala->getComponente(riga));
//        FinestraVisualizzaComponente finVisComp(db,c);
//        finVisComp.exec();
//        tabellaComponenti->clearContents();
//        tabellaComponenti->setRowCount(0);
//        riempiTabellaComponenti();
//    }
    if(!(tabellaComponenti->selectedItems().isEmpty())){
            int riga=tabellaComponenti->currentRow();
            Componente* r;
            int i=0;
            bool trovato=false;
             vector<Componente*>::const_iterator it=sala->getComponenti().begin();
             for(;it!=sala->getComponenti().end() && !trovato;++it){
                 if(
                   (QString::fromStdString(sala->getComponente(i)->getMarca()))==(tabellaComponenti->item(riga,0)->text()) &&
                   (QString::fromStdString(sala->getComponente(i)->getModello()))==(tabellaComponenti->item(riga,1)->text())
                   ){
                     r=sala->getComponente(i);
                     trovato=true;
                 }
                 i++;
             }
        FinestraVisualizzaComponente finVisComp(db,r,this);
        finVisComp.exec();
        }
        tabellaComponenti->clearContents();
        tabellaComponenti->setRowCount(0);
        riempiTabellaComponenti();

}

void FinestraConfiguraSala::torna(){
    this->close();
}
