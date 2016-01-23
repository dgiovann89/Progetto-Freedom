#ifndef COMPONENTE_H
#define COMPONENTE_H

#include<iostream>
#include<cliente.h>

using std::string;

class Componente{
private:
    string marca;
    string modello;
    int anno;
    float pressione;
    float portata_capacita;
    float cadutaDiPressione;
    Cliente* proprietario;
    SalaCompressori* sala;
public:
    Componente(string, string, int, float, float, float, Cliente* =0, SalaCompressori* =0);
    // distruttore virtuale
    virtual ~Componente();

    //get
    string getMarca() const;
    string getModello() const;
    int getAnno() const;
    float getPressione() const;
    float getPortata_capacita() const;
    float getCadutaDiPressione() const;
    Cliente* getCliente() const;
    SalaCompressori* getSala() const;
    virtual string getTipo() const=0;

    //set
    void setMarca(string);
    void setModello(string);
    void setAnno(int);
    void setPressione(float);
    void setPortata_capacita(float);
    void setCadutaDiPressione(float);
    void setProprietario(Cliente*);
    void setSala(SalaCompressori*);
//    void setTipo(string);
//    void virtual setKw(int);
};

#endif // COMPONENTE_H
