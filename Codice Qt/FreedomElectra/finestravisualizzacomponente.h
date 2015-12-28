#ifndef FINESTRAVISUALIZZACOMPONENTE_H
#define FINESTRAVISUALIZZACOMPONENTE_H

#include<finestrainseriscisala.h>

class FinestraVisualizzaComponente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraVisualizzaComponente(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneIndietro;

public slots:
    void torna();
};

#endif // FINESTRAVISUALIZZACOMPONENTE_H
