#include "finestraclienteselezionato.h"

FinestraClienteSelezionato::FinestraClienteSelezionato(DatabaseClienti* d, QDialog *parent):QDialog(parent), dbc(d){
    this->setWindowTitle("Finestra Cliente Selezionato");
    this->setMinimumSize(720,440);

    // new layout e groupbox
    layoutSfondo=new QVBoxLayout(this);
    layoutCliente= new QGridLayout();
    layoutBottoni= new QHBoxLayout(this);
    layoutTabella = new QVBoxLayout(this);
    boxCliente = new QGroupBox(this);
    boxTabella = new QGroupBox(this);
    boxBottoni = new QGroupBox(this);

    // new label e lineEdit
    labelTitolo=new QLabel("Cliente Selezionato:");
    labelTitoloTabella= new QLabel("Sale Compressori:", this);
    labelRagioneSociale=new QLabel("Ragione Sociale:",this);
    lineEditRagioneSociale=new QLineEdit(this);
    lineEditRagioneSociale->setDisabled(true);
    labelPIva=new QLabel("Partita Iva:",this);
    lineEditPIva=new QLineEdit(this);
    lineEditPIva->setDisabled(true);
    labelTelefono=new QLabel("Telefono:",this);
    lineEditTelefono=new QLineEdit(this);
    lineEditTelefono->setDisabled(true);
    labelFax=new QLabel("Fax:",this);
    lineEditFax=new QLineEdit(this);
    lineEditFax->setDisabled(true);
    labelEmail=new QLabel("Email:",this);
    lineEditEmail=new QLineEdit(this);
    lineEditEmail->setDisabled(true);
    labelStabilimento=new QLabel("Stabilimento:",this);
    lineEditStabilimento=new QLineEdit(this);
    lineEditStabilimento->setDisabled(true);
    labelVia=new QLabel("Via:",this);
    lineEditVia=new QLineEdit(this);
    lineEditVia->setDisabled(true);
    labelCittà=new QLabel("Città:",this);
    lineEditCittà=new QLineEdit(this);
    lineEditCittà->setDisabled(true);
    labelCap=new QLabel("CAP:",this);
    lineEditCap=new QLineEdit(this);
    lineEditCap->setDisabled(true);
    labelProvincia=new QLabel("Provincia:",this);
    lineEditProvincia=new QLineEdit(this);
    lineEditProvincia->setDisabled(true);

    // new tabella
    tabellaSale=new QTableWidget(0,5);
    tabellaSale->setColumnWidth(0,150);
    QStringList header;
    header=QStringList() << "Nome" << "Stabilimento" << "Tipo Impianto" << "KW Totali" << "Lt/minuto";
    tabellaSale->setHorizontalHeaderLabels(header);

    // new bottoni
    bottoneModificaDatiCliente= new QPushButton("Modifica",this);
    bottoneInserisciNuovaSala=new QPushButton("Inserisci nuova Sala Compressori",this);
    bottoneConfiguraSala= new QPushButton("Visualizza",this);
    bottoneEliminaSala= new QPushButton("Elimina",this);
    bottoneIndietro=new QPushButton("Torna indietro",this);

    // associazioni box e layout
    boxCliente->setLayout(layoutCliente);
    boxBottoni->setLayout(layoutBottoni);
    boxTabella->setLayout(layoutTabella);
    layoutSfondo->addWidget(labelTitolo);
    layoutSfondo->addWidget(boxCliente);
    layoutSfondo->addWidget(boxTabella);
    layoutSfondo->addWidget(tabellaSale);
    layoutSfondo->addWidget(boxBottoni);

    // associazion label e linedit a layoutCliente
    layoutCliente->addWidget(labelRagioneSociale,0,0);
    layoutCliente->addWidget(labelStabilimento,1,0);
    layoutCliente->addWidget(labelPIva,2,0);
    layoutCliente->addWidget(lineEditRagioneSociale,0,1);
    layoutCliente->addWidget(lineEditStabilimento,1,1);
    layoutCliente->addWidget(lineEditPIva,2,1);

    layoutCliente->addWidget(labelTelefono,0,2);
    layoutCliente->addWidget(labelFax,1,2);
    layoutCliente->addWidget(labelEmail,2,2);
    layoutCliente->addWidget(lineEditTelefono,0,3);
    layoutCliente->addWidget(lineEditFax,1,3);
    layoutCliente->addWidget(lineEditEmail,2,3);

    layoutCliente->addWidget(labelVia,0,4);
    layoutCliente->addWidget(labelCittà,1,4);
    layoutCliente->addWidget(labelCap,2,4);
    layoutCliente->addWidget(lineEditVia,0,5);
    layoutCliente->addWidget(lineEditCittà,1,5);
    layoutCliente->addWidget(lineEditCap,2,5);

    layoutCliente->addWidget(labelProvincia,0,6);
    layoutCliente->addWidget(lineEditProvincia,0,7);
    layoutCliente->addWidget(bottoneModificaDatiCliente,1,6,1,2);

    // associazione tabella a layoutTabella
    layoutTabella->addWidget(labelTitoloTabella);
    layoutTabella->addWidget(tabellaSale);

    // associazioni sul layoutBottoni
    layoutBottoni->addWidget(bottoneConfiguraSala);
    layoutBottoni->addWidget(bottoneEliminaSala);
    layoutBottoni->addWidget(bottoneInserisciNuovaSala);
    layoutBottoni->addWidget(bottoneIndietro);

    this->setLayout(layoutSfondo);

    connect(bottoneInserisciNuovaSala,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciSala()));
    connect(bottoneConfiguraSala,SIGNAL(clicked()),this,SLOT(apriFinestraConfiguraSala()));
    connect(bottoneIndietro,SIGNAL(clicked()),this,SLOT(torna()));
    connect(bottoneModificaDatiCliente,SIGNAL(clicked()),this,SLOT(apriFinestraInserisciCliente()));
}

void FinestraClienteSelezionato::apriFinestraInserisciSala(){
    FinestraInserisciSala finInsSala;
    finInsSala.exec();
}

void FinestraClienteSelezionato::apriFinestraConfiguraSala() {
    FinestraConfiguraSala finConfSala;
    finConfSala.exec();
}

void FinestraClienteSelezionato::apriFinestraInserisciCliente() {
    FinestraInserisciCliente finInsCli(dbc);
    finInsCli.exec();
}

void FinestraClienteSelezionato::torna(){
    this->close();
}
