#ifndef IMPIANTO_H
#define IMPIANTO_H

#include<componente.h>

class Impianto : public Componente{
public:
    Impianto(string, string, int, int, int, float, Cliente* =0, SalaCompressori* =0, int =0);
    string getTipo() const;
};

#endif // IMPIANTO_H
