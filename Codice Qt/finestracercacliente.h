#ifndef FINESTRACERCACLIENTE_H
#define FINESTRACERCACLIENTE_H

#include "finestraprincipale.h"
#include "finestraclienteselezionato.h"
#include <QTableWidget>
#include <QStringList>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>
#include "databaseclienti.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QHeaderView>

class FinestraCercaCliente : public QDialog{
    Q_OBJECT
private:
    DatabaseClienti* dbCli;
    DatabaseComponenti* dbComp;
    void riempiTabellaClienti();
    void aggiornaTabellaClienti();
    void intestazioneTabella();
    DatabaseClienti fromJasonClienti;

public:
    explicit FinestraCercaCliente(DatabaseClienti*, DatabaseComponenti*, QDialog* parent=0);

    // Layout e groupBox
    QVBoxLayout* layoutSfondo;

    // QFormLayout* layoutCompilazione;
    QHBoxLayout* layoutCompilazione;
    QVBoxLayout* layoutLista;
    QHBoxLayout* layoutBottoni;
    QGroupBox* boxCompilazione;
    QGroupBox* boxLista;
    QGroupBox* boxBottoni;

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
    QPushButton* bottoneReset;

    // tabella
    QTableWidget* tabellaClienti;

public slots:
    void apriFinestraClienteSelezionato();
    void cercaCliente();
    void mostraBottoneVisualizza();
    void torna();
    void abilitaLineEditPIva();
    void abilitaLineEditRagioneSociale();
    void resetCampi();
};

#endif // FINESTRACERCACLIENTE_H
