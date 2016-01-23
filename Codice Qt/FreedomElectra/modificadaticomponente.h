#ifndef MODIFICADATICOMPONENTE_H
#define MODIFICADATICOMPONENTE_H

#include<finestrainseriscisala.h>
#include<finestrainseriscicomponente.h>
//#include "modificadaticomponente.h"
#include<databasecomponenti.h>
#include<QComboBox>
#include<QString>

class ModificaDatiComponente : public QDialog{
    Q_OBJECT
private:
    DatabaseComponenti* db;
    Componente* c;
public:
    explicit ModificaDatiComponente(DatabaseComponenti*, Componente*, QDialog* parent=0);

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
    QLineEdit* lineeditCadDiPress;
    QLineEdit* lineEditKw;
    QLineEdit* lineEditTipo;

    // bottoni
    QPushButton* bottoneIndietro;
    QPushButton* bottoneSalva;

public slots:
    void salva();
    void torna();
};

#endif // MODIFICADATICOMPONENTE_H
