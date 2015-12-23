#include "macchinario.h"

Macchinario::Macchinario(string ma, string mod, int a, int press, int port, Cliente* cl, SalaCompressori* s, int k):Componente(ma,mod,a,press,port,cl,s),kw(k){}

string Macchinario::getTipo() const {
    return "Macchinario";
}

// get
int Macchinario::getKw() const {
    return kw;
}

// set
void Macchinario::setKw(int k) {
    kw = k;
}
