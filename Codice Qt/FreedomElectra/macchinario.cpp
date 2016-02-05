#include "macchinario.h"

Macchinario::Macchinario(string ma, string mod, int a, float press, float port, float cdp, int k, bool c, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id),kw(k),compressore(c){}

// get
int Macchinario::getKw() const {
    return kw;
}

// set
void Macchinario::setKw(int k) {
    kw = k;
}
