#ifndef IMPIANTO_H
#define IMPIANTO_H

#include "componente.h"

class Impianto : public Componente{
private:
    string materiale;
public:
    Impianto(string, string, int, int, int, float, string, Cliente* =0, SalaCompressori* =0, int =0);
    string getTypeInfo() const;

    // get
    string getMateriale() const;

    // set
    void setMateriale(string);

    virtual double calcolaPrezzo() const;
};

#endif // IMPIANTO_H
