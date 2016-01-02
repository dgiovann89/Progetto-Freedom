#ifndef FINESTRAVISUALIZZACOMPONENTE_H
#define FINESTRAVISUALIZZACOMPONENTE_H

#include<finestrainseriscisala.h>
#include<finestrainseriscicomponente.h>
#include<QComboBox>
#include<QString>

class FinestraVisualizzaComponente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraVisualizzaComponente(QDialog* parent=0);

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
    QPushButton* bottoneModifica;

    // combobox
    QComboBox* comboBoxTipo;

public slots:
    void apriFinestraInserisciComponente();
    void torna();
};

#endif // FINESTRAVISUALIZZACOMPONENTE_H
