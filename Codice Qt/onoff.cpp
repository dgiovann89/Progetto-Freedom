#include "onoff.h"

OnOff::OnOff(string ma, string mod, int a, float press, float port, float cdp, int k, int orec, int orev, bool c, Cliente* cl, SalaCompressori* s, int id):Macchinario(ma,mod,a,press,port,cdp,k,orec,c,cl,s,id),oreVuoto(orev){}

string OnOff::getTypeInfo() const {
    return "On-Off";
}

// get
int OnOff::getOreVuoto() const{
    return oreVuoto;
}

// set
void OnOff::setOreVuoto(int ov) {
    oreVuoto = ov;
}

double OnOff::calcolaPrezzo() const {
    double prezzo;
    if (isCompressore()==true)
        prezzo = 300*getKw();
    else
        prezzo = (300*getKw()*0.8); // essiccatore costa il 20% in meno rispetto a un compressore
    return prezzo;
}
