#ifndef MODIFICAINFOSALA_H
#define MODIFICAINFOSALA_H

#include<finestraclienteselezionato.h>
#include<QGroupBox>
#include<QLineEdit>

class ModificaInfoSala : public QDialog{
    Q_OBJECT
private:
    DatabaseClienti* dbc;
    Cliente* cl;
    SalaCompressori* sala;
public:
    explicit ModificaInfoSala(DatabaseClienti*, Cliente*, SalaCompressori*, QDialog* parent=0);

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
    void salva();
    void torna();
};

#endif // MODIFICAINFOSALA_H
