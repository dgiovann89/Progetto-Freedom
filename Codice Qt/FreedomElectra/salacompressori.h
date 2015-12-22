#ifndef SALACOMPRESSORI_H
#define SALACOMPRESSORI_H

#include<iostream>
#include<vector>
//#include<componente.h>
//#include<cliente.h>

using std::string;
using std::vector;

// AAA 2 classi incomplete dicharate..va bene?
class Cliente;
class Componente;

class SalaCompressori{
private:
    string nome;
    Cliente* proprietario;
    int kwTot;
    int portataTot;
    vector<Componente*> componenti; //tipo puntatore o classe??
public:
    SalaCompressori(string,Cliente*,int=0,int=0);
//    ~SalaCompressori(...)

    //get
    string getNome() const;
    Cliente* getProprietario() const;
    int getKwTot() const;
    int getPortataTot() const;

    //ritorna il vector intero di componenti
    vector<Componente*>& getComponenti() const;
    Componente* getComponente(int) const;

    //set
    void setNome(string);
    void setProprietario(Cliente*);

    // AAA nella rimuovi, rimouvo solo il componente puntato che sta in questo vector, o rimuovo anche quello nella classe DB_componenti
    void aggiungiComponente(Componente*);
    void rimuoviComponente(int);

//    void setKwTot(int);
//    void setPortataTot(int);
};

#endif // SALACOMPRESSORI_H
