#ifndef FILTRO_H
#define FILTRO_H

#include<componente.h>

class Filtro : public Componente{

public:
    Filtro(string, string, int, int, int, Cliente*, SalaCompressori*);
    string getTipo() const;
};

#endif // FILTRO_H
