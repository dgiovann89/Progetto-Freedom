#ifndef FILTRO_H
#define FILTRO_H

#include "componente.h"

class Filtro : public Componente{
private:
    int nCartucce;
public:
    Filtro(string, string, int, int, int, float, int, Cliente* =0, SalaCompressori* =0, int =0);
    string getTypeInfo() const;

    // get
    int getnCartucce() const;

    // set
    void setnCartucce(int);

    virtual double calcolaPrezzo() const;
};

#endif // FILTRO_H
