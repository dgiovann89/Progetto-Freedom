#ifndef VELOCITAVARIABILE_H
#define VELOCITAVARIABILE_H

#include<macchinario.h>

class VelocitaVariabile : public Macchinario{
public:
    VelocitaVariabile(string, string, int, int, int, Cliente*, SalaCompressori*,int);
};

#endif // VELOCITAVARIABILE_H
