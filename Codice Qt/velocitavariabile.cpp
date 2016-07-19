#include "velocitavariabile.h"

VelocitaVariabile::VelocitaVariabile(string ma, string mod, int a, float press, float port, float cdp, int k, int orec, bool c, Cliente* cl, SalaCompressori* s, int id):Macchinario(ma,mod,a,press,port,cdp,k,orec,c,cl,s,id){}

string VelocitaVariabile::getTypeInfo() const {
    return "Velocita Variabile";
}

double VelocitaVariabile::calcolaPrezzo() const {
    double prezzo;
    if (isCompressore()==true)
        prezzo = (300*getKw()*1.3);
    else
        prezzo = ((300*getKw()*0.8)*1.3); // essiccatore costa il 20% in meno rispetto a un compressore
    return prezzo; // prezzo maggiorato del 30% in piu rispetto ai macchinari OnOff
}
