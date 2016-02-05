#include "finestraconfigurasala.h"

FinestraConfiguraSala::FinestraConfiguraSala(DatabaseClienti* d, DatabaseComponenti* db, Cliente* c, SalaCompressori* sl, QDialog *parent): QDialog(parent), dbComp(db), dbc(d),cl(c), sala(sl) {
    this->setWindowTitle("Finestra Configurazione sala compressori");
    this->showMaximized(); // metti la finestra a tutto schermo

    // new layout e groupBox
    layoutInfoSala = new QGridLayout();
    layoutTabella = new QVBoxLayout();
    layoutSinistra = new QVBoxLayout();
    layoutDestra = new QVBoxLayout();
    layoutBottoniFinestra = new QVBoxLayout();
    layoutBottoniTabella = new QHBoxLayout();
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
    labelPannelloDatiTot = new QLabel("Dati significativi TOTALI:");
    labelRagioneSociale = new QLabel("Ragione Sociale",this);
    lineEditRagioneSociale = new QLineEdit(QString::fromStdString(cl->getRagioneSociale()));
    labelStabilimento = new QLabel("Stabilimento",this);
    lineEditStabilimento = new QLineEdit(QString::fromStdString(cl->getStabilimento()));
    labelNomeSala = new QLabel("Nome Sala:",this);
    lineEditNomeSala = new QLineEdit(QString::fromStdString(sala->getNome()));
    labelPressioneRichiesta = new QLabel("Pressione Richiesta (Bar):", this);
    lineEditPressioneRichiesta = new QLineEdit(QString::number(sala->getPressioneRichiesta()));
    labelPortataRichiesta = new QLabel("Portata Richiesta (Lt/s):", this);
    lineEditPortataRichiesta = new QLineEdit(QString::number(sala->getPortataRichiesta()));
    labelImpianto = new QLabel("Impianto:",this);
    lineEditImpianto = new QLineEdit(QString::fromStdString(sala->getImpianto()));
    labelKwTot = new QLabel("Kw Tot:",this);
    lineEditKwTot = new QLineEdit(QString::number(sala->getKwTot()));
    lineEditKwTot->setDisabled(true);
    labelPortatEffettiva = new QLabel("Portata Effettiva: (Lt/s)", this);
    lineEditPortataEffettiva = new QLineEdit(this);
    lineEditPortataEffettiva->setDisabled(true);
    labelPressioneEffettiva = new QLabel("Pressione Effettiva (Bar):", this);
    lineEditPressioneEffettiva = new QLineEdit(this);
    lineEditPressioneEffettiva->setDisabled(true);
    labelCadutaDiPressioneTot = new QLabel("Caduta di press. Tot (Bar):",this);
    lineEditCadutaDiPressioneTot = new QLineEdit(this);
    lineEditCadutaDiPressioneTot->setDisabled(true);

    // disabilito le lineEdit del cliente
    lineEditNomeSala->setDisabled(true);
    lineEditImpianto->setDisabled(true);
    lineEditPortataRichiesta->setDisabled(true);
    lineEditPressioneRichiesta->setDisabled(true);
    lineEditRagioneSociale->setDisabled(true);
    lineEditStabilimento->setDisabled(true);

    // new tabella
    tabellaComponenti = new QTableWidget(0,7);
    tabellaComponenti->setColumnWidth(0,200);
    QStringList header;
    header=QStringList() << "Id" << "Marca" << "Modello" << "Anno" << "Pressione (Bar)" << "Portata/Capacita (Lt/s)" << "Caduta di pressione (Bar)";
    tabellaComponenti->setHorizontalHeaderLabels(header);
    QHeaderView* q=tabellaComponenti->horizontalHeader();
    q->setStretchLastSection(true);
    tabellaComponenti->setColumnWidth(0,50);
    tabellaComponenti->setColumnWidth(5,200);

    // new bottoni
    bottoneModificaSala=new QPushButton("Modifica Info Sala",this);
    bottoneInserisciComponente=new QPushButton("Inserisci componente",this);
    bottoneVisualizzaComponente=new QPushButton("Visualizza componente",this);
    bottoneEliminaComponente=new QPushButton("Elimina Componente",this);
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

    // boxParametriSala->setTitle("Totali:");
    layoutParametriSala->addWidget(labelKwTot,1,0);
    layoutParametriSala->addWidget(lineEditKwTot,1,1);
    layoutParametriSala->addWidget(labelPortatEffettiva,2,0);
    layoutParametriSala->addWidget(lineEditPortataEffettiva,2,1);
    layoutParametriSala->addWidget(labelCadutaDiPressioneTot,3,0);
    layoutParametriSala->addWidget(lineEditCadutaDiPressioneTot,3,1);
    layoutParametriSala->addWidget(labelPressioneEffettiva,4,0);
    layoutParametriSala->addWidget(lineEditPressioneEffettiva,4,1);

    // colori
    paletteRosso.setColor(QPalette::Base,Qt::red);
    paletteRosso.setColor(QPalette::Text,Qt::black);
    paletteVerde.setColor(QPalette::Base,Qt::green);
    paletteVerde.setColor(QPalette::Text,Qt::black);

    this->setLayout(layoutSfondo);

    riempiTabellaComponenti();
    aggiornaKwSala();
    aggiornaCDPTot();
    aggiornaPortataTot();
    aggiornaPressioneEff();

    connect(bottoneModificaSala,SIGNAL(clicked()),this,SLOT(apriModificaInfoSala()));
    connect(bottoneInserisciComponente,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciComponente()));
    connect(bottoneVisualizzaComponente,SIGNAL(clicked()),this,SLOT(apriFinestraVisualizzaComponente()));
    connect(bottoneEliminaComponente,SIGNAL(clicked()),this,SLOT(eliminaComponente()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(tabellaComponenti,SIGNAL(cellDoubleClicked(int,int)), this,SLOT(apriFinestraVisualizzaComponente()));

}

void FinestraConfiguraSala::aggiornaKwSala(){
    sala->setKwTot(0);
    int kw_parziale=sala->getKwTot();
    for(unsigned int it=0;it<sala->getComponenti().size();++it){
        const Macchinario* macc = dynamic_cast <const Macchinario*>  (sala->getComponente(it));
        if (macc){
            kw_parziale = kw_parziale + macc->getKw();
            sala->setKwTot(kw_parziale);
        }
    }
    lineEditKwTot->setText(QString::number(sala->getKwTot()));
}

void FinestraConfiguraSala::aggiornaCDPTot(){
    lineEditCadutaDiPressioneTot->setText(QString::number(0));
    float pressione_parziale=0;
    for(unsigned int it=0;it<sala->getComponenti().size();++it){
        pressione_parziale = pressione_parziale + sala->getComponente(it)->getCadutaDiPressione();
    }
    lineEditCadutaDiPressioneTot->setText(QString::number(pressione_parziale));
}

void FinestraConfiguraSala::aggiornaPortataTot(){
    lineEditPortataEffettiva->setText(QString::number(0));
    float portata_richiesta = lineEditPortataRichiesta->text().toFloat();
    int portata_partziale=0;
    for(unsigned int it=0;it<sala->getComponenti().size();++it){
        const Macchinario* macc = dynamic_cast <const Macchinario*>  (sala->getComponente(it));
        if (macc)
            if (macc->isCompressore()){
                portata_partziale = portata_partziale + sala->getComponente(it)->getPortata_capacita();
                sala->setPortataTot(portata_partziale);
            }
    }
    lineEditPortataEffettiva->setText(QString::number(portata_partziale));
    if (portata_partziale<portata_richiesta)
        lineEditPortataEffettiva->setPalette(paletteRosso);
    else
        lineEditPortataEffettiva->setPalette(paletteVerde);
}

void FinestraConfiguraSala::aggiornaPressioneEff(){
    float press_rich = lineEditPressioneRichiesta->text().toFloat();

    float media_pressione_tot=0;
    int num_comp = 0;
    for(unsigned int it=0;it<sala->getComponenti().size();++it){
        const Macchinario* macc = dynamic_cast <const Macchinario*>  (sala->getComponente(it));
        if (macc)
            if (macc->isCompressore()){
                num_comp++;
                media_pressione_tot = media_pressione_tot + sala->getComponente(it)->getPressione();
            }
    }
    media_pressione_tot = media_pressione_tot/num_comp;

    float cdp_tot = lineEditCadutaDiPressioneTot->text().toFloat();
    double press_eff = media_pressione_tot-cdp_tot;
    lineEditPressioneEffettiva->setText(QString::number(press_eff));
    if (press_eff>=press_rich)
        lineEditPressioneEffettiva->setPalette(paletteVerde);
    else
        lineEditPressioneEffettiva->setPalette(paletteRosso);
}

// metodo privato riempiTabellaComponenti
void FinestraConfiguraSala::riempiTabellaComponenti(){
    int row = tabellaComponenti->rowCount();

    for (unsigned int i=0; i<sala->getComponenti().size();++i){
        tabellaComponenti->setRowCount(row+1);

        QTableWidgetItem* itemIdComponente = new QTableWidgetItem (QString::number(sala->getComponente(i)->getIdComponente()));
        tabellaComponenti->setItem(row, 0, itemIdComponente);

        QTableWidgetItem* itemMarca= new QTableWidgetItem (QString::fromStdString(sala->getComponente(i)->getMarca()));
        tabellaComponenti->setItem(row, 1, itemMarca);
        itemMarca->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemModello= new QTableWidgetItem (QString::fromStdString(sala->getComponente(i)->getModello()));
        tabellaComponenti->setItem(row, 2, itemModello);
        itemModello->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemAnno= new QTableWidgetItem (QString::number(sala->getComponente(i)->getAnno()));
        tabellaComponenti->setItem(row, 3, itemAnno);
        itemAnno->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemPressione= new QTableWidgetItem (QString::number(sala->getComponente(i)->getPressione()));
        tabellaComponenti->setItem(row, 4, itemPressione);
        itemPressione->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemPortata_Capacita= new QTableWidgetItem (QString::number(sala->getComponente(i)->getPortata_capacita()));
        tabellaComponenti->setItem(row, 5, itemPortata_Capacita);
        itemPortata_Capacita->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* itemCadDiPress= new QTableWidgetItem (QString::number(sala->getComponente(i)->getCadutaDiPressione()));
        tabellaComponenti->setItem(row, 6, itemCadDiPress);
        itemCadDiPress->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        row++;
    }
}

void FinestraConfiguraSala::eliminaComponente(){
    if (tabellaComponenti->currentItem()!= 0){
        int riga=tabellaComponenti->currentRow();
        Componente* r=*(dbComp->cercaComponente(tabellaComponenti->item(riga,0)->text().toInt()));
        if(r){
            dbComp->rimuoviComponente(*r); //rimuove dal contenitore
            sala->rimuoviComponente(riga); //rimuove dal vector
        }
        tabellaComponenti->clearContents();
        tabellaComponenti->setRowCount(0);
        riempiTabellaComponenti();
    }
    aggiornaKwSala();
    aggiornaCDPTot();
    aggiornaPortataTot();
    aggiornaPressioneEff();
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
    FinestraInserisciComponente finInsComp(dbComp,cl,sala);
    finInsComp.exec();
    tabellaComponenti->clearContents();
    tabellaComponenti->setRowCount(0);
    riempiTabellaComponenti();
    aggiornaKwSala();
    aggiornaCDPTot();
    aggiornaPortataTot();
    aggiornaPressioneEff();
}

void FinestraConfiguraSala::apriFinestraVisualizzaComponente(){
    if(!(tabellaComponenti->selectedItems().isEmpty())){
        int riga=tabellaComponenti->currentRow();
        Componente* r;
        int i=0;
        bool trovato=false;
        vector<Componente*>::const_iterator it=sala->getComponenti().begin();
        for(;it!=sala->getComponenti().end() && !trovato;++it){
            if((QString::number(sala->getComponente(i)->getIdComponente()))==tabellaComponenti->item(riga,0)->text()){
                r=sala->getComponente(i);
                trovato=true;
            }
            i++;
        }
        FinestraVisualizzaComponente finVisComp(dbComp,r,this);
        finVisComp.exec();
        aggiornaKwSala();
        aggiornaCDPTot();
        aggiornaPortataTot();
        aggiornaPressioneEff();
    }
    tabellaComponenti->clearContents();
    tabellaComponenti->setRowCount(0);
    riempiTabellaComponenti();
}

void FinestraConfiguraSala::torna(){
    this->close();
}
