#include "filtro.h"

Filtro::Filtro(string ma, string mod, int a, int press, int port, float cdp, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id){}

string Filtro::getTipo() const {
   return "Filtro";
}
