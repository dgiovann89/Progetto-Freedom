#include "velocitavariabile.h"

VelocitaVariabile::VelocitaVariabile(string ma, string mod, int a, int press, int port, float cdp, int k, bool c, Cliente* cl, SalaCompressori* s):Macchinario(ma,mod,a,press,port,cdp,k,c,cl,s){}

string VelocitaVariabile::getTipo() const {
    return "Velocita Variabile";
}

bool VelocitaVariabile::isCompressore() const {
    return compressore;
}
