#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <iostream>
#include "cliente.h"

using std::string;

class Componente{
private:
    string marca;
    string modello;
    int anno;
    float pressione;
    float portata;
    float cadutaDiPressione;
    Cliente* proprietario;
    SalaCompressori* sala;
    int idComponente;

public:
    Componente(string, string, int, float, float, float, Cliente* =0, SalaCompressori* =0, int =0);

    // distruttore virtuale
    virtual ~Componente();

    //get
    string getMarca() const;
    string getModello() const;
    int getAnno() const;
    float getPressione() const;
    float getPortata() const;
    float getCadutaDiPressione() const;
    Cliente* getCliente() const;
    SalaCompressori* getSala() const;
    int getIdComponente() const;

    //set
    void setMarca(string);
    void setModello(string);
    void setAnno(int);
    void setPressione(float);
    void setPortata(float);
    void setCadutaDiPressione(float);
    void setProprietario(Cliente*);
    void setSala(SalaCompressori*);

    virtual string getTypeInfo() const =0;
    virtual double calcolaPrezzo() const =0;
};

#endif // COMPONENTE_H
