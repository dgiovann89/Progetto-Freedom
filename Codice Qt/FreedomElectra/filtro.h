#ifndef FILTRO_H
#define FILTRO_H

#include<componente.h>

class Filtro : public Componente{

public:
    Filtro(string, string, int, int, int, Cliente*, SalaCompressori*);
};

#endif // FILTRO_H
