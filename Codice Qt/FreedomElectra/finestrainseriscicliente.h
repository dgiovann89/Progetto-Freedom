#ifndef FINESTRAINSERISCICLIENTE_H
#define FINESTRAINSERISCICLIENTE_H

#include<finestraprincipale.h>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QLineEdit>

class FinestraInserisciCliente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraInserisciCliente(QDialog* parent=0);

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
    void torna();
};

#endif // FINESTRAINSERISCICLIENTE_H
