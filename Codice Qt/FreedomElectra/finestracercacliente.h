#ifndef FINESTRACERCACLIENTE_H
#define FINESTRACERCACLIENTE_H

#include<qdialog.h>
#include<QVBoxLayout>
#include<qpushbutton.h>
#include<qlabel.h>
#include<finestraprincipale.h>

class FinestraCercaCliente : public QDialog{
    Q_OBJECT
public:
    explicit FinestraCercaCliente(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneIndietro;
    QPushButton* bottoneEsci;

public slots:
    void torna();
    void esci();

};

#endif // FINESTRACERCACLIENTE_H
