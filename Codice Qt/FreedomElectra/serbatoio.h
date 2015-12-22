#ifndef SERBATOIO_H
#define SERBATOIO_H

#include<componente.h>

class Serbatoio : public Componente{
public:
    Serbatoio(string, string, int, int, int, Cliente*, SalaCompressori*);
};

#endif // SERBATOIO_H
