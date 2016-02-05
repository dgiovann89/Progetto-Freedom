#include "serbatoio.h"

Serbatoio::Serbatoio(string ma, string mod, int a, int press, int port, float cdp, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id){}

string Serbatoio::getTipo() const {
    return "Serbatoio";
}
