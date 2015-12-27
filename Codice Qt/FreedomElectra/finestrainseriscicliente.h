#ifndef FINESTRAINSERISCICLIENTE_H
#define FINESTRAINSERISCICLIENTE_H

#include<qdialog.h>
#include<QVBoxLayout>
#include<qpushbutton.h>
#include<qlabel.h>
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
