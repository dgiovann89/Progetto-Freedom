#include "macchinario.h"

Macchinario::Macchinario(string ma, string mod, int a, float press, float port, float cdp, int k, int orec, bool c, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id),kw(k),oreCarico(orec),compressore(c){}

// get
int Macchinario::getKw() const {
    return kw;
}
int Macchinario::getOreCarico() const {
    return oreCarico;
}

// set
void Macchinario::setKw(int k) {
    kw = k;
}
void Macchinario::setOreCarico(int o) {
    oreCarico = o;
}

bool Macchinario::isCompressore() const {
    return compressore;
}
