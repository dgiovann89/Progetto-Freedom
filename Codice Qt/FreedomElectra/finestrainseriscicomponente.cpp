#include "finestrainseriscicomponente.h"

FinestraInserisciComponente::FinestraInserisciComponente(DatabaseComponenti* d, Cliente* c, SalaCompressori* s ,QDialog *parent):QDialog(parent), db(d), cl(c), sala(s){
    this->setWindowTitle("Finestra Inserisci Componenti");
    this->setMinimumSize(340,340);

    // new
    layoutSfondo=new QVBoxLayout(this);
    layoutDatiComponente = new QGridLayout();
    layoutBottoni = new QHBoxLayout(this);
    boxDatiComponente = new QGroupBox(this);
    boxBottoni = new QGroupBox(this);
    labelTipo = new QLabel("Tipo:");
    labelMarca=new QLabel("Marca:");
    labelModello = new QLabel("Modello:");
    labelAnno = new QLabel("Anno:");
    labelPressione = new QLabel("Pressione:");
    labelPortata_Capacità = new QLabel("Portata o Capacità:");
    labelCadDiPress = new QLabel("Caduta di pressione:");
    lineEditCadDiPress = new QLineEdit(this);
    labelKw = new QLabel("Kw:");
    lineEditMarca = new QLineEdit(this);
    lineEditModello = new QLineEdit(this);
    lineEditAnno = new QLineEdit(this);
    lineEditPressione = new QLineEdit(this);
    lineEditPortata_Capacità = new QLineEdit(this);
    lineEditKw = new QLineEdit(this);
    lineEditKw->setDisabled(true);
    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneSalva = new QPushButton("Salva",this);
    comboBoxTipo = new QComboBox();


    // set comboBox
    QStringList list= (QStringList()<< "Seleziona il tipo" << "Compressore On-Off"<< "Compressorie Vel variable"<< "Essiccatore On-Off" << "Essiccatore Vel variabile" << "Impianto" << "Filtro" << "Serbatoio");
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
    layoutDatiComponente->addWidget(labelCadDiPress,6,0);
    layoutDatiComponente->addWidget(lineEditCadDiPress,6,1);
    layoutDatiComponente->addWidget(labelKw,7,0);
    layoutDatiComponente->addWidget(lineEditKw,7,1);

    // associazione a layoutBottoni
    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneSalva);


    this->setLayout(layoutSfondo);

    lineEditMarca->setDisabled(true);
    lineEditModello->setDisabled(true);
    lineEditAnno->setDisabled(true);
    lineEditCadDiPress->setDisabled(true);
    lineEditPortata_Capacità->setDisabled(true);
    lineEditKw->setDisabled(true);
    lineEditPressione->setDisabled(true);

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
        lineEditPortata_Capacità->setDisabled(true);
        lineEditKw->setDisabled(true);
        lineEditPressione->setDisabled(true);
    }
    else
        if (comboBoxTipo->currentIndex()!=5 && comboBoxTipo->currentIndex()!=6 && comboBoxTipo->currentIndex()!=7){
            lineEditMarca->setDisabled(false);
            lineEditModello->setDisabled(false);
            lineEditAnno->setDisabled(false);
            lineEditCadDiPress->setDisabled(false);
            lineEditPortata_Capacità->setDisabled(false);
            lineEditKw->setDisabled(false);
            lineEditPressione->setDisabled(false);
        }
        else{
            lineEditMarca->setDisabled(false);
            lineEditModello->setDisabled(false);
            lineEditAnno->setDisabled(false);
            lineEditCadDiPress->setDisabled(false);
            lineEditPortata_Capacità->setDisabled(false);
            lineEditKw->setDisabled(true);
            lineEditPressione->setDisabled(false);
        }

}

void FinestraInserisciComponente::salva(){

    string marca = lineEditMarca->text().toStdString();
    string modello = lineEditModello->text().toStdString();
    int anno = lineEditAnno->text().toInt();
    int pressione = lineEditPressione->text().toInt();
    int portataCapacità = lineEditPortata_Capacità->text().toInt();
    float cdp = lineEditCadDiPress->text().toFloat();
    int kw = lineEditKw->text().toInt();

     bool inserito;

    FinestraInserisciComponente::sbloccaLineEdit();

     if (lineEditMarca->text()!=""){
        if (comboBoxTipo->currentIndex()==1 || comboBoxTipo->currentIndex()==2){
            OnOff* a = new OnOff(marca, modello, anno, pressione, portataCapacità, cdp, kw,cl,sala);
            inserito = db->inserisciComponente(a);
            sala->aggiungiComponente(a);
        }
        else if (comboBoxTipo->currentIndex()==3 || comboBoxTipo->currentIndex()==4){
            VelocitaVariabile* a = new VelocitaVariabile(marca, modello, anno, pressione, portataCapacità, cdp ,kw,cl,sala);
            inserito = db->inserisciComponente(a);
            sala->aggiungiComponente(a);
        }
        else if (comboBoxTipo->currentIndex()==5){
            Impianto* a = new Impianto(marca, modello, anno, pressione, portataCapacità,cdp,cl,sala);
            inserito = db->inserisciComponente(a);
            sala->aggiungiComponente(a);
        }
        else if (comboBoxTipo->currentIndex()==6){
            Filtro* a = new Filtro(marca, modello, anno, pressione, portataCapacità,cdp,cl,sala);
            inserito = db->inserisciComponente(a);
            sala->aggiungiComponente(a);
        }
        else if (comboBoxTipo->currentIndex()==7){
            Serbatoio* a = new Serbatoio(marca, modello, anno, pressione, portataCapacità,cdp,cl,sala);
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
