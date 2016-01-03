#include "finestrainseriscicliente.h"

FinestraInserisciCliente::FinestraInserisciCliente(DatabaseClienti* d, QDialog* parent): QDialog(parent), db(d){
    this->setWindowTitle("Finestra Inserisci Cliente");
    this->setMinimumSize(420,340);

    layoutSfondo=new QVBoxLayout(this);
    boxInfoCliente=new QGroupBox("Info cliente",this);
    layoutInfoCliente=new QGridLayout();
    boxBottoni=new QGroupBox(this);
    layoutBottoni=new QHBoxLayout();

    labelRagioneSociale=new QLabel("Ragione Sociale:",this);
    lineEditRagioneSociale=new QLineEdit(this);
    labelPIva=new QLabel("Partita Iva:",this);
    lineEditPIva=new QLineEdit(this);
    labelTelefono=new QLabel("Telefono:",this);
    lineEditTelefono=new QLineEdit(this);
    labelFax=new QLabel("Fax:",this);
    lineEditFax=new QLineEdit(this);
    labelEmail=new QLabel("Email:",this);
    lineEditEmail=new QLineEdit(this);
    labelStabilimento=new QLabel("Stabilimento:",this);
    lineEditStabilimento=new QLineEdit(this);
    labelVia=new QLabel("Via:",this);
    lineEditVia=new QLineEdit(this);
    labelCittà=new QLabel("Città:",this);
    lineEditCittà=new QLineEdit(this);
    labelCap=new QLabel("CAP:",this);
    lineEditCap=new QLineEdit(this);
    labelProvincia=new QLabel("Provincia:",this);
    lineEditProvincia=new QLineEdit(this);

    bottoneIndietro=new QPushButton("Torna indietro",this);
    bottoneSalva=new QPushButton("Salva",this);

    // label e lineedit sinistra
    layoutInfoCliente->addWidget(labelRagioneSociale,0,0);
    layoutInfoCliente->addWidget(lineEditRagioneSociale,1,0);
    layoutInfoCliente->addWidget(labelPIva,2,0);
    layoutInfoCliente->addWidget(lineEditPIva,3,0);
    layoutInfoCliente->addWidget(labelTelefono,4,0);
    layoutInfoCliente->addWidget(lineEditTelefono,5,0);
    layoutInfoCliente->addWidget(labelFax,6,0);
    layoutInfoCliente->addWidget(lineEditFax,7,0);
    layoutInfoCliente->addWidget(labelEmail,8,0);
    layoutInfoCliente->addWidget(lineEditEmail,9,0);

    // label e lineedit destra
    layoutInfoCliente->addWidget(labelStabilimento,0,1);
    layoutInfoCliente->addWidget(lineEditStabilimento,1,1);
    layoutInfoCliente->addWidget(labelVia,2,1);
    layoutInfoCliente->addWidget(lineEditVia,3,1);
    layoutInfoCliente->addWidget(labelCittà,4,1);
    layoutInfoCliente->addWidget(lineEditCittà,5,1);
    layoutInfoCliente->addWidget(labelCap,6,1);
    layoutInfoCliente->addWidget(lineEditCap,7,1);
    layoutInfoCliente->addWidget(labelProvincia,8,1);
    layoutInfoCliente->addWidget(lineEditProvincia,9,1);

    boxInfoCliente->setLayout(layoutInfoCliente);
    boxBottoni->setLayout(layoutBottoni);
    layoutSfondo->addWidget(boxInfoCliente);
    layoutSfondo->addWidget(boxBottoni);
    layoutBottoni->addWidget(bottoneIndietro);
    layoutBottoni->addWidget(bottoneSalva);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
}


void FinestraInserisciCliente::salva(){
    Cliente c(lineEditRagioneSociale->text().toStdString(),lineEditPIva->text().toStdString(),
              lineEditTelefono->text().toStdString(),lineEditFax->text().toStdString(),
              lineEditEmail->text().toStdString(),lineEditStabilimento->text().toStdString());

    Indirizzo i(lineEditVia->text().toStdString(), lineEditCittà->text().toStdString(),
                lineEditCap->text().toStdString(), lineEditProvincia->text().toStdString());

    c.setInd(i);

    if(lineEditRagioneSociale->text()!="" && lineEditPIva->text()!="" &&
            lineEditTelefono->text()!="" && lineEditFax->text()!="" && lineEditEmail->text()!="" && lineEditStabilimento->text()!="" &&
            lineEditVia->text()!="" && lineEditCittà->text()!="" && lineEditCap->text()!="" && lineEditProvincia->text()!=""){

        db->aggiungiCliente(c);
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


void FinestraInserisciCliente::torna(){
    this->close();
}
