#include "onoff.h"

OnOff::OnOff(string ma, string mod, int a, int press, int port, float cdp, int k, Cliente* cl, SalaCompressori* s):Macchinario(ma,mod,a,press,port,cdp,k,cl,s){}

string OnOff::getTipo() const {
    return "On-Off";
}
