#ifndef FINESTRAVISUALIZZACOMPONENTE_H
#define FINESTRAVISUALIZZACOMPONENTE_H

#include "finestrainseriscisala.h"
#include "finestrainseriscicomponente.h"
#include "modificadaticomponente.h"
#include "databasecomponenti.h"
#include <QComboBox>
#include <QString>

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
    QLabel* labelPortata;
    QLabel* labelKw;
    QLabel* labelCdP;
    QLabel* labelCapacita;
    QLabel* labelnCartucce;
    QLabel* labelMateriale;
    QLabel* labelOreCarico;
    QLabel* labelOreVuoto;

    // lineEdit
    QLineEdit* lineEditTipo;
    QLineEdit* lineEditMarca;
    QLineEdit* lineEditModello;
    QLineEdit* lineEditAnno;
    QLineEdit* lineEditPressione;
    QLineEdit* lineEditPortata;
    QLineEdit* lineEditKw;
    QLineEdit* lineEditCdP;
    QLineEdit* lineEditCapacita;
    QLineEdit* lineEditnCartucce;
    QLineEdit* lineeditMateriale;
    QLineEdit* lineEditOreCarico;
    QLineEdit* lineEditOreVuoto;

    // bottoni
    QPushButton* bottoneIndietro;
    QPushButton* bottoneModifica;

public slots:
    void apriModificaDatiComponente();
    void torna();
};

#endif // FINESTRAVISUALIZZACOMPONENTE_H
