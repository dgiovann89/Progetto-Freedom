#ifndef FINESTRAINSERISCICOMPONENTE_H
#define FINESTRAINSERISCICOMPONENTE_H

#include "finestrainseriscisala.h"
#include <QComboBox>
#include <QString>
#include "databasecomponenti.h"
#include "componente.h"
#include "onoff.h"
#include "velocitavariabile.h"
#include "salacompressori.h"
#include "serbatoio.h"
#include "filtro.h"
#include "impianto.h"

class FinestraInserisciComponente : public QDialog{
    Q_OBJECT
private:
    DatabaseComponenti* db;
    Cliente* cl;
    SalaCompressori* sala;
    int calcolaIdComponente() const;

public:
    explicit FinestraInserisciComponente(DatabaseComponenti*, Cliente*, SalaCompressori* ,QDialog* parent=0);

    // box e layout
    QVBoxLayout* layoutSfondo;
    QGridLayout* layoutDatiComponente;
    QHBoxLayout* layoutBottoni;
    QGroupBox* boxBottoni;
    QGroupBox* boxDatiComponente;

    QString selezionato;

    // label
    QLabel* labelTipo;
    QLabel* labelMarca;
    QLabel* labelModello;
    QLabel* labelAnno;
    QLabel* labelPressione;
    QLabel* labelPortata_Capacita;
    QLabel* labelCadDiPress;
    QLabel* labelKw;

    // lineEdit
    QLineEdit* lineEditMarca;
    QLineEdit* lineEditModello;
    QLineEdit* lineEditAnno;
    QLineEdit* lineEditPressione;
    QLineEdit* lineEditPortata_Capacita;
    QLineEdit* lineEditCadDiPress;
    QLineEdit* lineEditKw;

    // bottoni
    QPushButton* bottoneIndietro;
    QPushButton* bottoneSalva;

    // combobox
    QComboBox* comboBoxTipo;

public slots:
    void salva();
    void torna();
    void sbloccaLineEdit();
};

#endif // FINESTRAINSERISCICOMPONENTE_H
