#ifndef SALACOMPRESSORI_H
#define SALACOMPRESSORI_H

#include<iostream>
#include<vector>
#include<componente.h>
//#include<cliente.h>

using std::string;
using std::vector;

class Cliente;

class SalaCompressori{
private:
    string nome;
    Cliente* proprietario;
    int kwTot;
    int portataTot;
    vector<Componente*> componente; //tipo puntatore o classe??
public:
    SalaCompressori(string,Cliente*,int=0,int=0);
//    ~SalaCompressori(...)

    //get
    string getNome() const;
    Cliente* getProprietario() const;
    int getKwTot() const;
    int getPortataTot() const;

    //set
    void setNome(string);
    void setProprietario(Cliente*);

//    void setKwTot(int);
//    void setPortataTot(int);
};

#endif // SALACOMPRESSORI_H
