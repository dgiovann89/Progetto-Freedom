#ifndef FINESTRAINSERISCISALA_H
#define FINESTRAINSERISCISALA_H

#include "finestraclienteselezionato.h"
#include <QGroupBox>
#include <QLineEdit>

class FinestraInserisciSala : public QDialog{
    Q_OBJECT
private:
    DatabaseClienti* dbc;
    Cliente* cl;

public:
    explicit FinestraInserisciSala(DatabaseClienti*, Cliente*, QDialog* parent=0);

    QVBoxLayout* layoutSfondo;

    QGridLayout* layoutInfoSala;
    QGroupBox* boxInfoSala;

    QHBoxLayout* layoutBottoni;
    QGroupBox* boxBottoni;

    QLabel* labelNomeSala;
    QLineEdit* lineEditNomeSala;
    QLabel* labelCliente;
    QLineEdit* lineEditCliente;
    QLabel* labelStabilimento;
    QLineEdit* lineEditStabilimento;
    QLabel* labelPressioneRichiesta;
    QLineEdit* lineEditPressioneRichiesta;
    QLabel* labelPortataRichiesta;
    QLineEdit* lineEditPortataRichiesta;

    QPushButton* bottoneIndietro;
    QPushButton* bottoneSalva;

public slots:
    void salva();
    void torna();
};

#endif // FINESTRAINSERISCISALA_H
