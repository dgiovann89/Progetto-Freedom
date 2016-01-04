#include "impianto.h"

Impianto::Impianto(string ma, string mod, int a, int press, int port, float cdp, Cliente* cl, SalaCompressori* s):Componente(ma,mod,a,press,port,cdp,cl,s){}

string Impianto::getTipo() const {
    return "Impianto";
}
