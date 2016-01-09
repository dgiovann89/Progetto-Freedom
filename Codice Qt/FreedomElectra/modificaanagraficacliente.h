#ifndef MODIFICAANAGRAFICACLIENTE_H
#define MODIFICAANAGRAFICACLIENTE_H

#include "finestraclienteselezionato.h"
#include "finestracercacliente.h"
#include<QGroupBox>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>

class ModificaAnagraficaCliente : public QDialog {
    Q_OBJECT
private:
    DatabaseClienti* dbc;
    Cliente* cl;
public:
    explicit ModificaAnagraficaCliente(DatabaseClienti*, Cliente* ,QDialog* parent=0);

    QVBoxLayout* layoutSfondo;

    QGridLayout* layoutInfoCliente;
    QGroupBox* boxInfoCliente;

    QHBoxLayout* layoutBottoni;
    QGroupBox* boxBottoni;

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
    QLabel* labelCittà;
    QLineEdit* lineEditCittà;
    QLabel* labelCap;
    QLineEdit* lineEditCap;
    QLabel* labelProvincia;
    QLineEdit* lineEditProvincia;

    QPushButton* bottoneIndietro;
    QPushButton* bottoneSalva;


public slots:
    void salva();
    void torna();
};

#endif // MODIFICAANAGRAFICACLIENTE_H
