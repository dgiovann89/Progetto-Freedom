#ifndef SERBATOIO_H
#define SERBATOIO_H

#include "componente.h"

class Serbatoio : public Componente{
private:
    int capacita;
public:
    Serbatoio(string, string, int, int, int, float, int, Cliente* =0, SalaCompressori* =0,int =0);
    string getTypeInfo() const;

    // get
    int getCapacita() const;

    // set
    void setCapacita(int);

    virtual double calcolaPrezzo() const;
};

#endif // SERBATOIO_H
