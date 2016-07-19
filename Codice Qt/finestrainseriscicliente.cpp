#include "finestrainseriscicliente.h"

FinestraInserisciCliente::FinestraInserisciCliente(DatabaseClienti* d, QDialog* parent): QDialog(parent), dbc(d){
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
    lineEditPIva=new QLineEdit("0000000000");
    lineEditPIva->setInputMask("9999999999"); //settare input di soli numeri 0-9
    labelTelefono=new QLabel("Telefono:",this);
    lineEditTelefono=new QLineEdit("0000000000");
    lineEditTelefono->setInputMask("9999999999");
    labelFax=new QLabel("Fax:",this);
    lineEditFax=new QLineEdit("0000000000");
    lineEditFax->setInputMask("9999999999");
    labelEmail=new QLabel("Email:",this);
    lineEditEmail=new QLineEdit(this);
    labelStabilimento=new QLabel("Stabilimento:",this);
    lineEditStabilimento=new QLineEdit(this);
    labelVia=new QLabel("Via:",this);
    lineEditVia=new QLineEdit(this);
    labelCitta=new QLabel("Citta:",this);
    lineEditCitta=new QLineEdit(this);
    labelCap=new QLabel("CAP:",this);
    lineEditCap=new QLineEdit("00000");
    lineEditCap->setInputMask("99999");
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
    layoutInfoCliente->addWidget(labelCitta,4,1);
    layoutInfoCliente->addWidget(lineEditCitta,5,1);
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

    //palette colori
    paletteRosso.setColor(QPalette::Base,Qt::red);
    paletteRosso.setColor(QPalette::Text,Qt::black);
    paletteVerde.setColor(QPalette::Base,Qt::green);
    paletteVerde.setColor(QPalette::Text,Qt::black);

    this->setLayout(layoutSfondo);

    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneSalva,SIGNAL(clicked()),this,SLOT(salva()));
}

void FinestraInserisciCliente::torna(){
    this->close();
}

void FinestraInserisciCliente::salva(){
    if(lineEditRagioneSociale->text()!="" && lineEditPIva->text()!="" &&
            lineEditTelefono->text()!="" && lineEditFax->text()!="" && lineEditEmail->text()!="" && lineEditStabilimento->text()!="" &&
            lineEditVia->text()!="" && lineEditCitta->text()!="" && lineEditCap->text()!="" && lineEditProvincia->text()!=""){

        Cliente cli(lineEditRagioneSociale->text().toStdString(),
                    lineEditTelefono->text().toStdString(),
                    lineEditEmail->text().toStdString(),
                    lineEditFax->text().toStdString(),
                    lineEditPIva->text().toStdString(),
                    lineEditStabilimento->text().toStdString());

        Indirizzo i(lineEditVia->text().toStdString(),
                    lineEditCitta->text().toStdString(),
                    lineEditProvincia->text().toStdString(),
                    lineEditCap->text().toStdString());

        cli.setInd(i);

        bool inseribile=true;
        for (unsigned int i=0;i<dbc->getDatabase().size() && inseribile;i++){
            if(cli.getRagioneSociale() == dbc->getCliente(i).getRagioneSociale() && cli.getStabilimento()==dbc->getCliente(i).getStabilimento()){
                QMessageBox messageBox(this);
                messageBox.setText("Cliente gia presente");
                messageBox.exec();
                inseribile=false;
            }
        }

        if (inseribile==true){
            dbc->aggiungiCliente(cli);
            dbc->saveClienti(DatabaseClienti::Json); // salva sul file
            QMessageBox messageBox(this);
            messageBox.setText("Dati inseriti correttamente");
            messageBox.exec();
            this->close();
        }
    }
    else{
        QMessageBox messageBox(this);
        messageBox.setText("Compilare tutti i campi");
        messageBox.exec();
        if(lineEditRagioneSociale->text()=="") lineEditRagioneSociale->setPalette(paletteRosso);
        else lineEditRagioneSociale->setPalette(paletteVerde);
        if (lineEditPIva->text()=="") lineEditPIva->setPalette(paletteRosso);
        else lineEditPIva->setPalette(paletteVerde);
        if (lineEditTelefono->text()=="") lineEditTelefono->setPalette(paletteRosso);
        else lineEditTelefono->setPalette(paletteVerde);
        if (lineEditFax->text()=="") lineEditFax->setPalette(paletteRosso);
        else lineEditFax->setPalette(paletteVerde);
        if (lineEditEmail->text()=="") lineEditEmail->setPalette(paletteRosso);
        else lineEditEmail->setPalette(paletteVerde);
        if (lineEditStabilimento->text()=="") lineEditStabilimento->setPalette(paletteRosso);
        else lineEditStabilimento->setPalette(paletteVerde);
        if (lineEditVia->text()=="") lineEditVia->setPalette(paletteRosso);
        else lineEditVia->setPalette(paletteVerde);
        if (lineEditCitta->text()=="") lineEditCitta->setPalette(paletteRosso);
        else lineEditCitta->setPalette(paletteVerde);
        if (lineEditCap->text()=="") lineEditCap->setPalette(paletteRosso);
        else lineEditCap->setPalette(paletteVerde);
        if (lineEditProvincia->text()=="") lineEditProvincia->setPalette(paletteRosso);
        else lineEditProvincia->setPalette(paletteVerde);
    }
}
