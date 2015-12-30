#ifndef FINESTRACLIENTESELEZIONATO_H
#define FINESTRACLIENTESELEZIONATO_H

#include<finestracercacliente.h>
#include<finestrainseriscisala.h>
#include<QTableWidget>
#include<QGroupBox>

class FinestraClienteSelezionato : public QDialog{
    Q_OBJECT
public:
    explicit FinestraClienteSelezionato(QDialog* parent=0);

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
    QLabel* labelCittà;
    QLineEdit* lineEditCittà;
    QLabel* labelCap;
    QLineEdit* lineEditCap;
    QLabel* labelProvincia;
    QLineEdit* lineEditProvincia;

    // Bottoni
    QPushButton* bottoneModificaDatiCliente;
    QPushButton* bottoneInserisciNuovaSala;
    QPushButton* bottoneVisualizzaSala;
    QPushButton* bottoneEliminaSala;
    QPushButton* bottoneIndietro;

    // Tabella
    QTableWidget* tabellaSale;

public slots:
    void apriFinestraInserisciSala();
    void torna();
};

#endif // FINESTRACLIENTESELEZIONATO_H
