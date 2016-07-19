#include "finestrainseriscicomponente.h"

FinestraInserisciComponente::FinestraInserisciComponente(DatabaseComponenti* d, Cliente* c, SalaCompressori* s ,QDialog *parent):QDialog(parent), db(d), cl(c), sala(s){
    this->setWindowTitle("Finestra Inserisci Componenti");
    this->setMinimumSize(340,340);

    // new
    layoutSfondo=new QVBoxLayout(this);
    layoutDatiComponente = new QGridLayout();
    layoutBottoni = new QHBoxLayout();
    boxDatiComponente = new QGroupBox(this);
    boxBottoni = new QGroupBox(this);
    comboBoxTipo = new QComboBox();
    labelTipo = new QLabel("Tipo:");
    labelMarca=new QLabel("Marca:");
    labelModello = new QLabel("Modello:");
    labelAnno = new QLabel("Anno:");
    labelPressione = new QLabel("Pressione (Bar):");
    labelPortata = new QLabel("Portata (Lt/s):");
    labelCadDiPress = new QLabel("Caduta di pressione (Bar):");
    labelKw = new QLabel("Kw:");
    labelCapacita = new QLabel("Capacità (Lt):");
    labelnCartucce = new QLabel("Num Cartucce:");
    labelMateriale = new QLabel("Materiale:");
    labelOreCarico = new QLabel("Ore a carico:");
    labelOreVuoto = new QLabel("Ore a vuoto:");
    lineEditMarca = new QLineEdit(this);
    lineEditModello = new QLineEdit(this);
    lineEditAnno = new QLineEdit("2000");
    lineEditAnno->setInputMask("9999");
    lineEditPressione = new QLineEdit("07.0");
    lineEditPressione->setInputMask("xx.x");
    lineEditPortata = new QLineEdit("0");
    lineEditCadDiPress = new QLineEdit("0");
    lineEditKw = new QLineEdit("0");
    lineEditKw->setDisabled(true);
    lineEditCapacita = new QLineEdit("0");
    lineEditnCartucce = new QLineEdit("1");
    lineeditMateriale = new QLineEdit("Materiale");
    lineEditOreCarico = new QLineEdit("0");
    lineEditOreVuoto = new QLineEdit("0");
    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneSalva = new QPushButton("Salva",this);
    bottoneSalva->setDefault(true);

    comboBoxTipo->insertItem(0,"Seleziona il tipo");
    comboBoxTipo->insertItem(1,"Compressore On-Off");
    comboBoxTipo->insertItem(2,"Essiccatore On-Off");
    comboBoxTipo->insertItem(3,"Compressorie Vel variable");
    comboBoxTipo->insertItem(4,"Essiccatore Vel variabile");
    comboBoxTipo->insertItem(5,"Impianto");
    comboBoxTipo->insertItem(6,"Filtro");
    comboBoxTipo->insertItem(7,"Serbatoio");

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
    layoutDatiComponente->addWidget(labelPortata,5,0);
    layoutDatiComponente->addWidget(lineEditPortata,5,1);
    layoutDatiComponente->addWidget(labelCadDiPress,6,0);
    layoutDatiComponente->addWidget(lineEditCadDiPress,6,1);
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

    this->setLayout(layoutSfondo);

    lineEditMarca->setDisabled(true);
    lineEditModello->setDisabled(true);
    lineEditAnno->setDisabled(true);
    lineEditCadDiPress->setDisabled(true);
    lineEditPortata->setDisabled(true);
    lineEditPressione->setDisabled(true);
    lineEditKw->setDisabled(true);
    //
    lineEditCapacita->setDisabled(true);
    lineEditnCartucce->setDisabled(true);
    lineeditMateriale->setDisabled(true);
    lineEditOreCarico->setDisabled(true);
    lineEditOreVuoto->setDisabled(true);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
    connect(comboBoxTipo,SIGNAL(currentIndexChanged(int)),this,SLOT(sbloccaLineEdit()));
}

void FinestraInserisciComponente::sbloccaLineEdit(){
    if (comboBoxTipo->currentIndex()==0){
        lineEditMarca->setDisabled(true);
        lineEditModello->setDisabled(true);
        lineEditAnno->setDisabled(true);
        lineEditCadDiPress->setDisabled(true);
        lineEditPortata->setDisabled(true);
        lineEditPressione->setDisabled(true);
        lineEditKw->setDisabled(true);
        lineEditCapacita->setDisabled(true);
        lineEditnCartucce->setDisabled(true);
        lineeditMateriale->setDisabled(true);
        lineEditOreCarico->setDisabled(true);
        lineEditOreVuoto->setDisabled(true);
    }
    else
        if (comboBoxTipo->currentIndex()==1 || comboBoxTipo->currentIndex()==2) { //ONOFF
            lineEditMarca->setDisabled(false);
            lineEditModello->setDisabled(false);
            lineEditAnno->setDisabled(false);
            lineEditCadDiPress->setDisabled(false);
            lineEditPortata->setDisabled(false);
            lineEditPressione->setDisabled(false);
            lineEditKw->setDisabled(false);
            lineEditCapacita->setDisabled(true);
            labelCapacita->setDisabled(true);
            lineEditnCartucce->setDisabled(true);
            labelnCartucce->setDisabled(true);
            lineeditMateriale->setDisabled(true);
            labelMateriale->setDisabled(true);
            lineEditOreCarico->setDisabled(false);
            lineEditOreVuoto->setDisabled(false);
        }
        else
            if (comboBoxTipo->currentIndex()==3 || comboBoxTipo->currentIndex()==4) { //VELVAR
                lineEditMarca->setDisabled(false);
                lineEditModello->setDisabled(false);
                lineEditAnno->setDisabled(false);
                lineEditCadDiPress->setDisabled(false);
                lineEditPortata->setDisabled(false);
                lineEditPressione->setDisabled(false);
                lineEditKw->setDisabled(false);
                lineEditCapacita->setDisabled(true);
                labelCapacita->setDisabled(true);
                lineEditnCartucce->setDisabled(true);
                labelnCartucce->setDisabled(true);
                lineeditMateriale->setDisabled(true);
                labelMateriale->setDisabled(true);
                lineEditOreCarico->setDisabled(false);
                lineEditOreVuoto->setDisabled(true);
                labelOreVuoto->setDisabled(true);
            }
            else
                if (comboBoxTipo->currentIndex()==5) { //IMPIANTO
                    lineEditMarca->setDisabled(false);
                    lineEditModello->setDisabled(false);
                    lineEditAnno->setDisabled(false);
                    lineEditCadDiPress->setDisabled(false);
                    lineEditPortata->setDisabled(false);
                    lineEditPressione->setDisabled(false);
                    lineEditKw->setDisabled(true);
                    labelKw->setDisabled(true);
                    lineEditCapacita->setDisabled(true);
                    labelCapacita->setDisabled(true);
                    lineEditnCartucce->setDisabled(true);
                    labelnCartucce->setDisabled(true);
                    lineeditMateriale->setDisabled(false);
                    lineEditOreCarico->setDisabled(true);
                    labelOreCarico->setDisabled(true);
                    lineEditOreVuoto->setDisabled(true);
                    labelOreVuoto->setDisabled(true);
                }
                else
                    if (comboBoxTipo->currentIndex()==6) { //FILTRO
                        lineEditMarca->setDisabled(false);
                        lineEditModello->setDisabled(false);
                        lineEditAnno->setDisabled(false);
                        lineEditCadDiPress->setDisabled(false);
                        lineEditPortata->setDisabled(false);
                        lineEditPressione->setDisabled(false);
                        lineEditKw->setDisabled(true);
                        labelKw->setDisabled(true);
                        lineEditCapacita->setDisabled(true);
                        labelCapacita->setDisabled(true);
                        lineEditnCartucce->setDisabled(false);
                        lineeditMateriale->setDisabled(true);
                        labelMateriale->setDisabled(true);
                        lineEditOreCarico->setDisabled(true);
                        labelOreCarico->setDisabled(true);
                        lineEditOreVuoto->setDisabled(true);
                        labelOreVuoto->setDisabled(true);
                    }
                    else{
                        lineEditMarca->setDisabled(false);
                        lineEditModello->setDisabled(false);
                        lineEditAnno->setDisabled(false);
                        lineEditCadDiPress->setDisabled(false);
                        lineEditPortata->setDisabled(false);
                        lineEditPressione->setDisabled(false);
                        labelKw->setDisabled(true);
                        lineEditKw->setDisabled(true);
                        lineEditCapacita->setDisabled(false);
                        lineEditnCartucce->setDisabled(true);
                        labelnCartucce->setDisabled(true);
                        lineeditMateriale->setDisabled(true);
                        labelMateriale->setDisabled(true);
                        lineEditOreCarico->setDisabled(true);
                        labelOreCarico->setDisabled(true);
                        lineEditOreVuoto->setDisabled(true);
                        labelOreVuoto->setDisabled(true);
                    }
}

int FinestraInserisciComponente::calcolaIdComponente() const{
    if (db->isEmpty()==true)
        return 1;
    else{
        int idesatto;
        bool trovato=false;
        for (DatabaseComponenti::Iteratore cit=db->begin(); !trovato && cit!=db->end(); cit++){
            trovato=true;
            idesatto = (*cit)->getIdComponente();
        }
        return (idesatto+1);
    }
}

void FinestraInserisciComponente::salva(){

    string marca = lineEditMarca->text().toStdString();
    string modello = lineEditModello->text().toStdString();
    int anno = lineEditAnno->text().toInt();
    float pressione = lineEditPressione->text().toFloat();
    float portata = lineEditPortata->text().toFloat();
    float cdp = lineEditCadDiPress->text().toFloat();
    int kw = lineEditKw->text().toInt();
    int idComponente = calcolaIdComponente();
    int capac = lineEditCapacita->text().toInt();
    int ncart = lineEditnCartucce->text().toInt();
    string materiale = lineeditMateriale->text().toStdString();
    int orec = lineEditOreCarico->text().toInt();
    int orev = lineEditOreVuoto->text().toInt();

    bool inserito;

    FinestraInserisciComponente::sbloccaLineEdit();

    if (lineEditMarca->text()!=""){
        if (comboBoxTipo->currentIndex()==1 || comboBoxTipo->currentIndex()==2){
            if (comboBoxTipo->currentIndex()==1){
                Componente* a = new OnOff(marca, modello, anno, pressione, portata, cdp, kw,orec,orev,true,cl,sala,idComponente);
                inserito = db->inserisciComponente(a);
                sala->aggiungiComponente(a);
            }
            else{
                Componente* a = new OnOff(marca, modello, anno, pressione, portata, cdp, kw,orec,orev,false,cl,sala,idComponente);
                inserito = db->inserisciComponente(a);
                sala->aggiungiComponente(a);}
        }
        else if (comboBoxTipo->currentIndex()==3 || comboBoxTipo->currentIndex()==4){
            if (comboBoxTipo->currentIndex()==3){
                Componente* a = new VelocitaVariabile(marca, modello, anno, pressione, portata, cdp ,kw,orec,true,cl,sala,idComponente);
                inserito = db->inserisciComponente(a);
                sala->aggiungiComponente(a);}
            else{
                Componente* a = new VelocitaVariabile(marca, modello, anno, pressione, portata, cdp ,kw,orec,false,cl,sala,idComponente);
                inserito = db->inserisciComponente(a);
                sala->aggiungiComponente(a);}
        }
        else if (comboBoxTipo->currentIndex()==5){
            Impianto* a = new Impianto(marca, modello, anno, pressione, portata,cdp,materiale,cl,sala,idComponente);
            inserito = db->inserisciComponente(a);
            sala->aggiungiComponente(a);
            sala->setImpianto(a->getMateriale());
        }
        else if (comboBoxTipo->currentIndex()==6){
            Componente* a = new Filtro(marca, modello, anno, pressione, portata,cdp,ncart,cl,sala,idComponente);
            inserito = db->inserisciComponente(a);
            sala->aggiungiComponente(a);
        }
        else if (comboBoxTipo->currentIndex()==7){
            Componente* a = new Serbatoio(marca, modello, anno, pressione, portata,cdp,capac,cl,sala,idComponente);
            inserito = db->inserisciComponente(a);
            sala->aggiungiComponente(a);
        }
        else
            inserito=false;
        QMessageBox messageBox(this);
        if (inserito) {
            messageBox.setText("Componente inserito con successo!");
            messageBox.exec();
            this->close();
        }
        else {
            messageBox.setText("Compilare i campi.");
            messageBox.exec();
        }
    }
    else {
        QMessageBox messageBox(this);
        messageBox.setText("Inserire una marca non vuota.");
        messageBox.exec();
    }
}

void FinestraInserisciComponente::torna(){
    this->close();
}
