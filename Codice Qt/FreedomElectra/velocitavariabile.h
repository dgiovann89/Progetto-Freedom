#ifndef VELOCITAVARIABILE_H
#define VELOCITAVARIABILE_H

#include<macchinario.h>

class VelocitaVariabile : public Macchinario{
public:
    VelocitaVariabile(string, string, int, int, int, float, int, bool, Cliente* =0, SalaCompressori* =0, int =0);
    string getTipo() const;

    virtual bool isCompressore() const;
};

#endif // VELOCITAVARIABILE_H
