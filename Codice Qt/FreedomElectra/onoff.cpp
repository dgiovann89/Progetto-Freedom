#include "onoff.h"

OnOff::OnOff(string ma, string mod, int a, float press, float port, float cdp, int k, bool c, Cliente* cl, SalaCompressori* s, int id):Macchinario(ma,mod,a,press,port,cdp,k,c,cl,s,id){}

string OnOff::getTipo() const {
    return "On-Off";
}

bool OnOff::isCompressore() const {
    return compressore;
}
