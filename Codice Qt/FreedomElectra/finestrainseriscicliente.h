#ifndef FINESTRAINSERISCICLIENTE_H
#define FINESTRAINSERISCICLIENTE_H

//#include <finestraprincipale.h>
#include <databaseclienti.h>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QLineEdit>
#include<QMessageBox>
#include<QLabel>
#include<QPushButton>

#include<iostream>

using std::cout;

class FinestraInserisciCliente : public QDialog{
    Q_OBJECT
private:
    DatabaseClienti* dbc;
public:
    explicit FinestraInserisciCliente(DatabaseClienti*, QDialog* parent=0);

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
    QLabel* labelCitta;
    QLineEdit* lineEditCitta;
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

#endif // FINESTRAINSERISCICLIENTE_H
