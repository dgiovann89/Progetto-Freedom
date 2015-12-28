#ifndef FINESTRACLIENTESELEZIONATO_H
#define FINESTRACLIENTESELEZIONATO_H

#include<finestracercacliente.h>
#include<finestrainseriscisala.h>

class FinestraClienteSelezionato : public QDialog{
    Q_OBJECT
public:
    explicit FinestraClienteSelezionato(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneInserisciSala;
    QPushButton* bottoneIndietro;

public slots:
    void apriFinestraInserisciSala();
    void torna();
};

#endif // FINESTRACLIENTESELEZIONATO_H
