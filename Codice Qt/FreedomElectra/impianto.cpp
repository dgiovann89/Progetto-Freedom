#include "impianto.h"

Impianto::Impianto(string ma, string mod, int a, int press, int port, float cdp, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id){}

string Impianto::getTipo() const {
    return "Impianto";
}
