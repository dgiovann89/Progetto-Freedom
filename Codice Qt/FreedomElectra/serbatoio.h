#ifndef SERBATOIO_H
#define SERBATOIO_H

#include "componente.h"

class Serbatoio : public Componente{
public:
    Serbatoio(string, string, int, int, int, float, Cliente* =0, SalaCompressori* =0,int =0);
    string getTipo() const;
};

#endif // SERBATOIO_H
