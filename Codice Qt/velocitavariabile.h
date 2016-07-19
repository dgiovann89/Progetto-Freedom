#ifndef VELOCITAVARIABILE_H
#define VELOCITAVARIABILE_H

#include "macchinario.h"

class VelocitaVariabile : public Macchinario{
public:
    VelocitaVariabile(string, string, int, float, float, float, int, int, bool, Cliente* =0, SalaCompressori* =0, int =0);
    string getTypeInfo() const;

    virtual double calcolaPrezzo() const;

};

#endif // VELOCITAVARIABILE_H
