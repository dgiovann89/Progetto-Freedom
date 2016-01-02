#ifndef FINESTRAINSERISCISALA_H
#define FINESTRAINSERISCISALA_H

#include<finestraclienteselezionato.h>
#include<QGroupBox>
#include<QLineEdit>

class FinestraInserisciSala : public QDialog{
    Q_OBJECT
public:
    explicit FinestraInserisciSala(QDialog* parent=0);

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
    QLabel* labelImpianto;
    QLineEdit* lineEditImpianto;

    QPushButton* bottoneIndietro;
    QPushButton* bottoneSalva;

public slots:
    void torna();
};

#endif // FINESTRAINSERISCISALA_H
