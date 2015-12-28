#ifndef FINESTRAINSERISCISALA_H
#define FINESTRAINSERISCISALA_H

#include<finestraclienteselezionato.h>
#include<finestrainseriscicomponente.h>
#include<finestravisualizzacomponente.h>
#include<finestrainfosala.h>

class FinestraInserisciSala : public QDialog{
    Q_OBJECT
public:
    explicit FinestraInserisciSala(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneModificaInfoSala;
    QPushButton* bottoneInserisciComponente;
    QPushButton* bottoneVisualizzaComponente;
    QPushButton* bottoneIndietro;

public slots:
    void apriFinestraModificaInfoSala();
    void apriFinestraInserisciComponente();
    void apriFinestraVisualizzaComponente();
    void torna();
};

#endif // FINESTRAINSERISCISALA_H
