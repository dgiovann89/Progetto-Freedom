#ifndef FINESTRAINFOSALA_H
#define FINESTRAINFOSALA_H

#include<finestrainseriscisala.h>

class FinestraInfoSala : public QDialog{
    Q_OBJECT
public:
    explicit FinestraInfoSala(QDialog* parent=0);

    QVBoxLayout* layout;
    QLabel* labelTitolo;
    QPushButton* bottoneIndietro;

public slots:
    void torna();
};

#endif // FINESTRAINFOSALA_H
