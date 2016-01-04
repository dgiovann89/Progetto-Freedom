#ifndef VELOCITAVARIABILE_H
#define VELOCITAVARIABILE_H

#include<macchinario.h>

class VelocitaVariabile : public Macchinario{
public:
    VelocitaVariabile(string, string, int, int, int, float, int, Cliente* =0, SalaCompressori* =0);
};

#endif // VELOCITAVARIABILE_H
