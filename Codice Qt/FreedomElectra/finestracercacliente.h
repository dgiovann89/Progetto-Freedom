#ifndef FINESTRACERCACLIENTE_H
#define FINESTRACERCACLIENTE_H

#include<finestraprincipale.h>
#include<finestraclienteselezionato.h>
#include<QTableWidget>
#include<QStringList>
#include<QGroupBox>
#include<QLineEdit>
#include<QFormLayout>
#include<databaseclienti.h>
#include "QJsonDocument"
#include "QJsonObject"

class FinestraCercaCliente : public QDialog{
    Q_OBJECT
private:
    DatabaseClienti* dbc;
    void riempiTabellaClienti(); //+ eventualmente header
    DatabaseClienti fromJasonClienti;

public:
    explicit FinestraCercaCliente(DatabaseClienti*, QDialog* parent=0);

    // Layout e groupBox
    QHBoxLayout* layoutSfondo;
    // QFormLayout* layoutCompilazione;
    QGridLayout* layoutCompilazione;
    QVBoxLayout* layoutLista;
    QGroupBox* boxCompilazione;
    QGroupBox* boxLista;

    // Label e LineEdit
    QLabel* labelTitolo;
    QLabel* labelLista;
    QLabel* labelRagioneSociale;
    QLabel* labelPIva;
    QLineEdit* lineEditPIva;
    QLineEdit* lineEditRagioneSociale;

    // Bottoni
    QPushButton* bottoneCercaCliente;
    QPushButton* bottoneApriCliente;
    QPushButton* bottoneIndietro;

    // tabella
    QTableWidget* tabellaClienti;

public slots:
    void apriFinestraClienteSelezionato();
    void cercaCliente();
    void mostraBottoneVisualizza();
    void torna();
    void abilitaLineEditPIva();
    void abilitaLineEditRagioneSociale();

};

#endif // FINESTRACERCACLIENTE_H
