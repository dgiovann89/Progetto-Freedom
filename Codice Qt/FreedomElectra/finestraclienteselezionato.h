#ifndef FINESTRACLIENTESELEZIONATO_H
#define FINESTRACLIENTESELEZIONATO_H

#include<finestracercacliente.h>
#include<finestrainseriscisala.h>
#include<finestraconfigurasala.h>
#include "modificaanagraficacliente.h"
#include<QTableWidget>
#include<QGroupBox>

class FinestraClienteSelezionato : public QDialog{
    Q_OBJECT
private:
    DatabaseClienti* dbc;
    DatabaseComponenti* dbComp;
    Cliente* cl;

    void riempiTabellaSale();
    void aggiornaKwStabilimento();
public:
    explicit FinestraClienteSelezionato(DatabaseClienti* ,DatabaseComponenti*, Cliente* , QDialog* parent=0);

    // Layout e groupbox
    QVBoxLayout* layoutSfondo;
    QGridLayout* layoutCliente;
    QHBoxLayout* layoutBottoni;
    QVBoxLayout* layoutTabella;
    QGroupBox* boxCliente;
    QGroupBox* boxTabella;
    QGroupBox* boxBottoni;

    // Label e lineEdit
    QLabel* labelTitolo;
    QLabel* labelTitoloTabella;
    QLabel* labelRagioneSociale;
    QLineEdit* lineEditRagioneSociale;
    QLabel* labelPIva;
    QLineEdit* lineEditPIva;
    QLabel* labelTelefono;
    QLineEdit* lineEditTelefono;
    QLabel* labelFax;
    QLineEdit* lineEditFax;
    QLabel* labelEmail;
    QLineEdit* lineEditEmail;
    QLabel* labelStabilimento;
    QLineEdit* lineEditStabilimento;
    QLabel* labelVia;
    QLineEdit* lineEditVia;
    QLabel* labelCitta;
    QLineEdit* lineEditCitta;
    QLabel* labelCap;
    QLineEdit* lineEditCap;
    QLabel* labelProvincia;
    QLineEdit* lineEditProvincia;
    QLabel* labelKwStabilimento;
    QLineEdit* lineEditKwStabilimento;

    // Bottoni
    QPushButton* bottoneModificaDatiCliente;
    QPushButton* bottoneInserisciNuovaSala;
    QPushButton* bottoneConfiguraSala;
    QPushButton* bottoneEliminaSala;
    QPushButton* bottoneIndietro;

    // Tabella
    QTableWidget* tabellaSale;

public slots:
    void apriFinestraInserisciSala();
    void apriFinestraConfiguraSala();
    void apriModificaAnagraficaCliente();
    void torna();
    void elimina();
};

#endif // FINESTRACLIENTESELEZIONATO_H
