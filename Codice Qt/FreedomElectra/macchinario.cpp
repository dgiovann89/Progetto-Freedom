#include "macchinario.h"

Macchinario::Macchinario(string ma, string mod, int a, int press, int port, float cdp, int k, bool c, Cliente* cl, SalaCompressori* s):Componente(ma,mod,a,press,port,cdp,cl,s),kw(k),compressore(c){}

//string Macchinario::getTipo() const {
//    return "Macchinario";
//}

// get
int Macchinario::getKw() const {
    return kw;
}

// set
void Macchinario::setKw(int k) {
    kw = k;
}

//bool Macchinario::isCompressore() const {
//    return compressore;
//}
