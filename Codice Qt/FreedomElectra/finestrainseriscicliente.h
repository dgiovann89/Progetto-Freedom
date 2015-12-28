#ifndef FINESTRAINSERISCICLIENTE_H
#define FINESTRAINSERISCICLIENTE_H

#include<finestraprincipale.h>

class FinestraInserisciCliente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraInserisciCliente(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneIndietro;

public slots:
    void torna();
};

#endif // FINESTRAINSERISCICLIENTE_H
