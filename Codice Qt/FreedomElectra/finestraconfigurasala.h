#ifndef FINESTRACONFIGURASALA_H
#define FINESTRACONFIGURASALA_H

#include<finestraclienteselezionato.h>
#include<finestrainseriscisala.h>
#include<finestravisualizzacomponente.h>
#include<finestrainseriscicomponente.h>
#include<modificainfosala.h>
#include<databasecomponenti.h>
#include<QTableWidget>
#include<QGroupBox>
#include<QString>
#include<iostream>
#include <QPalette>

using namespace std;


class FinestraConfiguraSala : public QDialog{
    Q_OBJECT
private:
    DatabaseComponenti* db;
    DatabaseClienti* dbc;
    Cliente* cl;
    SalaCompressori* sala;
    void riempiTabellaComponenti();
    void aggiornaKwSala();
    void aggiornaCDPTot();
    void aggiornaPortataTot();
    void aggiornaPressioneEff();
public:
    explicit FinestraConfiguraSala(DatabaseClienti*, Cliente*, SalaCompressori* , QDialog* parent=0);

    // layout e groupbox
    QGridLayout* layoutInfoSala;
    QVBoxLayout* layoutTabella;
    QVBoxLayout* layoutSinistra;
    QVBoxLayout* layoutDestra;
    QVBoxLayout* layoutBottoniFinestra;
    QHBoxLayout* layoutBottoniTabella;
    QHBoxLayout* layoutSfondo;
    QGridLayout* layoutParametriSala;
    QGroupBox* boxSinistra;
    QGroupBox* boxDestra;
    QGroupBox* boxInfoSala;
    QGroupBox* boxTabella;
    QGroupBox* boxBottoniTabella;
    QGroupBox* boxBottoniFinestra;
    QGroupBox* boxParametriSala;

    // label e lineEdit
    QLabel* labelInfoSala;
    QLabel* labelTabella;
    QLabel* labelPannelloDatiTot;
    QLabel* labelRagioneSociale;
    QLineEdit* lineEditRagioneSociale;
    QLabel* labelStabilimento;
    QLineEdit* lineEditStabilimento;
    QLabel* labelNomeSala;
    QLineEdit* lineEditNomeSala;
    QLabel* labelPressioneRichiesta;
    QLineEdit* lineEditPressioneRichiesta;
    QLabel* labelPortataRichiesta;
    QLineEdit* lineEditPortataRichiesta;
    QLabel* labelImpianto;
    QLineEdit* lineEditImpianto;
    QLabel* labelKwTot;
    QLineEdit* lineEditKwTot;
    QLabel* labelPortatEffettiva;
    QLineEdit* lineEditPortataEffettiva;
    QLabel* labelPressioneEffettiva;
    QLineEdit* lineEditPressioneEffettiva;
    QLabel* labelCadutaDiPressioneTot;
    QLineEdit* lineEditCadutaDiPressioneTot;

    // bottoni
    QPushButton* bottoneModificaSala;
    QPushButton* bottoneInserisciComponente;
    QPushButton* bottoneVisualizzaComponente;
    QPushButton* bottoneEliminaComponente;
    QPushButton* bottoneSalva;
    QPushButton* bottoneEsportaPDF;
    QPushButton* bottoneIndietro;

    // tabella
    QTableWidget* tabellaComponenti;

    //palette
    QPalette paletteRosso;
    QPalette paletteVerde;

public slots:
    void apriModificaInfoSala();
    void apriFinestraInserisciComponente();
    void apriFinestraVisualizzaComponente();
    void eliminaComponente();
    void torna();
};

#endif // FINESTRACONFIGURASALA_H
