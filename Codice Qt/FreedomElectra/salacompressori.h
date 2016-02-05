#ifndef SALACOMPRESSORI_H
#define SALACOMPRESSORI_H

#include <iostream>
#include <vector>
//#include<componente.h>
//#include<cliente.h> // quando funzionava era commentato
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

using std::string;
using std::vector;

class Cliente;
class Componente;

class SalaCompressori{
private:
    string nome;
    Cliente* proprietario;
    int kwTot;
    int portataTot;
    int pressioneRichiesta;
    int portataRichiesta;
    string impianto;
    vector<Componente*> componenti;
public:
    SalaCompressori(string,Cliente*,int=0,int=0,int=0,int=0,string="");
    ~SalaCompressori();

    //get
    string getNome() const;
    Cliente* getProprietario() const;
    int getKwTot() const;
    int getPortataTot() const;
    int getPressioneRichiesta() const;
    int getPortataRichiesta() const;
    string getImpianto() const;

    //ritorna il vector intero di componenti
    vector<Componente*>& getComponenti() const;
    Componente* getComponente(int) const;

    //set
    void setNome(string);
    void setProprietario(Cliente*);
    void setPressioneRichiesta(int);
    void setPortataRichiesta(int);
    void setImpianto(string);
    void setKwTot(int);
    void setPortataTot(int);

    void aggiungiComponente(Componente*);
    void rimuoviComponente(int);
};

#endif // SALACOMPRESSORI_H
