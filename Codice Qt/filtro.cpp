#include "filtro.h"

Filtro::Filtro(string ma, string mod, int a, int press, int port, float cdp, int ncart, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id), nCartucce(ncart){}

string Filtro::getTypeInfo() const {
    return "Filtro";
}

// get
int Filtro::getnCartucce() const {
    return nCartucce;
}

// set
void Filtro::setnCartucce(int n) {
    nCartucce = n;
}

double Filtro::calcolaPrezzo() const {
    double prezzo;
    prezzo = ((getPortata()*3.5)*1.2)+nCartucce*100;
    return prezzo;
}
