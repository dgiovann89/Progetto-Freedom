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
#include<QListWidget>

class FinestraCercaCliente : public QDialog{
    Q_OBJECT
private:
    DatabaseClienti* db;
    void aggiornaLista();
public:
    explicit FinestraCercaCliente(DatabaseClienti* db, QDialog* parent=0);

    // Layout e groupBox
    QHBoxLayout* layoutSfondo;
//    QFormLayout* layoutCompilazione;
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
    QPushButton* bottoneEliminaCliente;
    QPushButton* bottoneIndietro;

    // tabella
    QTableWidget* tabellaClienti;

private slots:
    void inserisciCliente(QListWidgetItem*);
    void resetCampi(int);

public slots:
    void apriFinestraClienteSelezionato();
    void aggiornaListaS();
    // metodo per cercare il cliente
    // metodo per eliminare il cliente selezionato
    void torna();

};

#endif // FINESTRACERCACLIENTE_H
