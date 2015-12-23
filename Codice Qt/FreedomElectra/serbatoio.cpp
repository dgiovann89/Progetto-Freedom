#include "serbatoio.h"

Serbatoio::Serbatoio(string ma, string mod, int a, int press, int port, Cliente* cl, SalaCompressori* s):Componente(ma,mod,a,press,port,cl,s){}

string Serbatoio::getTipo() const {
    return "Serbatoio";
}
