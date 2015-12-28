#ifndef FINESTRAINSERISCICOMPONENTE_H
#define FINESTRAINSERISCICOMPONENTE_H

#include<finestrainseriscisala.h>

class FinestraInserisciComponente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraInserisciComponente(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneIndietro;

public slots:
    void torna();
};

#endif // FINESTRAINSERISCICOMPONENTE_H
