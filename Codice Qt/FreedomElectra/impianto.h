#ifndef IMPIANTO_H
#define IMPIANTO_H

#include<componente.h>

class Impianto : public Componente{
private:
    int cadDiPress;
public:
    Impianto(string, string, int, int, int, Cliente*, SalaCompressori*, int);
    string getTipo() const;
};

#endif // IMPIANTO_H
