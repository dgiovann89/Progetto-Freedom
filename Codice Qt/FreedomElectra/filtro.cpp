#include "filtro.h"

Filtro::Filtro(string ma, string mod, int a, int press, int port, float cdp, Cliente* cl, SalaCompressori* s):Componente(ma,mod,a,press,port,cdp,cl,s){}

string Filtro::getTipo() const {
   return "Filtro";
}
