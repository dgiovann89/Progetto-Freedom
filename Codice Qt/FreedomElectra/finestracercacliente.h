#ifndef FINESTRACERCACLIENTE_H
#define FINESTRACERCACLIENTE_H

#include<finestraprincipale.h>
#include<finestraclienteselezionato.h>

class FinestraCercaCliente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraCercaCliente(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneVisualizzaCliente;
    QPushButton* bottoneIndietro;

public slots:
    void apriFinestraClienteSelezionato();
    void torna();

};

#endif // FINESTRACERCACLIENTE_H
