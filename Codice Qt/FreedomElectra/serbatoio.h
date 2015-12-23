#ifndef SERBATOIO_H
#define SERBATOIO_H

#include<componente.h>

class Serbatoio : public Componente{
public:
    Serbatoio(string, string, int, int, int, Cliente*, SalaCompressori*);
    string getTipo() const;
};

#endif // SERBATOIO_H
