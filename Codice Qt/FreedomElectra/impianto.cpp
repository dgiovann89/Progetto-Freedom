#include "impianto.h"

Impianto::Impianto(string ma, string mod, int a, int press, int port, Cliente* cl, SalaCompressori* s, int c):Componente(ma,mod,a,press,port,cl,s),cadDiPress(c){}

string Impianto::getTipo() const {
    return "Impianto";
}
