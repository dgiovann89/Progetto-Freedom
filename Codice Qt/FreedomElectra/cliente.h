#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include "indirizzo.h"
#include "salacompressori.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

using std::vector;
using std::string;
using namespace std;

class Cliente{
private:
    string ragioneSociale;
    string telefono;
    string email;
    string fax;
    string pIva;
    string stabilimento;
    Indirizzo ind;
    vector <SalaCompressori> sala;

public:
    Cliente(string="", string="", string="", string="", string="", string="", Indirizzo=Indirizzo());

    //get
    string getRagioneSociale() const;
    string getTelefono() const;
    string getEmail() const;
    string getFax() const;
    string getPIva() const;
    string getStabilimento() const;
    Indirizzo getIndirizzo() const;
    vector<SalaCompressori>& getSala() const; // ritorna il vector
    SalaCompressori& getSala(int) const; // ritorna l'oggetto di indice i

    //set
    void setRagioneSociale(string s);
    void setTelefono(string s);
    void setEmail(string s);
    void setFax(string s);
    void setPIva(string s);
    void setStabilimento(string s);
    void setInd(const Indirizzo& i);

    bool operator==(const Cliente&) const;

    //metodi per aggiungere/rimuovere una sala dal vector
    void aggiungiSala(const SalaCompressori&);
    void rimuoviSala(int);

    // metodi per i file
    void read(const QJsonObject& json);
    void write(QJsonObject &json) const;
};

#endif // CLIENTE_H
