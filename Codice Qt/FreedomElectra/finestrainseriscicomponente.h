#ifndef FINESTRAINSERISCICOMPONENTE_H
#define FINESTRAINSERISCICOMPONENTE_H

#include<finestrainseriscisala.h>
#include<QComboBox>
#include<QString>

class FinestraInserisciComponente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraInserisciComponente(QDialog* parent=0);

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
    QLabel* labelPortata_Capacità;
    QLabel* labelKw;

    // lineEdit
    QLineEdit* lineEditMarca;
    QLineEdit* lineEditModello;
    QLineEdit* lineEditAnno;
    QLineEdit* lineEditPressione;
    QLineEdit* lineEditPortata_Capacità;
    QLineEdit* lineEditKw;

    // bottoni
    QPushButton* bottoneIndietro;
    QPushButton* bottoneSalva;

    // combobox
    QComboBox* comboBoxTipo;

public slots:
    void torna();
};

#endif // FINESTRAINSERISCICOMPONENTE_H
