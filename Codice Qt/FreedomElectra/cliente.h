#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<vector>
#include<indirizzo.h>
#include<salacompressori.h>

using std::vector;
using std::string;

class Cliente{
private:
    string ragioneSociale;
    string telefono;
    string email;
    string fax;
    string pIva;
    vector <SalaCompressori> sala;
    Indirizzo ind;
    string stabilimento;
public:
    Cliente(string,string,string,string="",string="",Indirizzo=Indirizzo(),string="");
//    ~Cliente() pensare

    //get
    string getRagioneSociale() const;
    string getTelefono() const;
    string getEmail() const;
    string getFax() const;
    string getPIva() const;
    Indirizzo getIndirizzo() const;
    string getStabilimento() const;
    vector<SalaCompressori>& getSala() const; // ritorna il vector
    SalaCompressori& getSala(int) const; // ritorna l'oggetto di indice i

    //set
    void setRagioneSociale(string);
    void setTelefono(string);
    void setEmail(string);
    void setFax(string);
    void setPIva(string);
    void setInd(Indirizzo);
    void setStabilimento(string);

    bool operator==(const Cliente&) const;

    //metodi per aggiungere/rimuovere una sala dal vector
    void aggiungiSala(const SalaCompressori&);
    void rimuoviSala(int);
};

#endif // CLIENTE_H
