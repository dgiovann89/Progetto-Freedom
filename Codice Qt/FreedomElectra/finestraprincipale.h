#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include<qdialog.h>
#include<QVBoxLayout>
#include<qpushbutton.h>
#include<qlabel.h>
#include<finestrainseriscicliente.h>
#include<finestracercacliente.h>

class FinestraPrincipale : public QDialog{
    Q_OBJECT
public:
    explicit FinestraPrincipale(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneInserisciCliente;
    QPushButton* bottoneCercaCliente;
    QPushButton* bottoneEsci;

public slots:
    void apriFinestraInserisciCliente();
    void apriFinestraCercaCliente();
    void esci();

};

#endif // FINESTRAPRINCIPALE_H
