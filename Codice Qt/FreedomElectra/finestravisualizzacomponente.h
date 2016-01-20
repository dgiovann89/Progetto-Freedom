#ifndef FINESTRAVISUALIZZACOMPONENTE_H
#define FINESTRAVISUALIZZACOMPONENTE_H

#include<finestrainseriscisala.h>
#include<finestrainseriscicomponente.h>
#include "modificadaticomponente.h"
#include<databasecomponenti.h>
#include<QComboBox>
#include<QString>

class FinestraVisualizzaComponente : public QDialog{
    Q_OBJECT
private:
    DatabaseComponenti* db;
    Componente* c;
public:
    explicit FinestraVisualizzaComponente(DatabaseComponenti*, Componente*, QDialog* parent=0);

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
    QLabel* labelKw;

    // lineEdit
    QLineEdit* lineEditTipo;
    QLineEdit* lineEditMarca;
    QLineEdit* lineEditModello;
    QLineEdit* lineEditAnno;
    QLineEdit* lineEditPressione;
    QLineEdit* lineEditPortata_Capacita;
    QLineEdit* lineEditKw;

    // bottoni
    QPushButton* bottoneIndietro;
    QPushButton* bottoneModifica;

    // combobox
//    QComboBox* comboBoxTipo;

public slots:
    void apriModificaDatiComponente();
    void torna();
};

#endif // FINESTRAVISUALIZZACOMPONENTE_H
