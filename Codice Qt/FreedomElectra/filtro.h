#ifndef FILTRO_H
#define FILTRO_H

#include "componente.h"

class Filtro : public Componente{

public:
    Filtro(string, string, int, int, int, float, Cliente* =0, SalaCompressori* =0, int =0);
    string getTipo() const;
};

#endif // FILTRO_H
