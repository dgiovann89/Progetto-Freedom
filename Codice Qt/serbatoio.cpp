#include "serbatoio.h"

Serbatoio::Serbatoio(string ma, string mod, int a, int press, int port, float cdp, int capac, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id), capacita(capac){}

string Serbatoio::getTypeInfo() const {
    return "Serbatoio";
}

// get
int Serbatoio::getCapacita() const {
    return capacita;
}

// set
void Serbatoio::setCapacita(int c){
    capacita = c;
}

double Serbatoio::calcolaPrezzo() const {
    double prezzo;
    prezzo = 0.5*capacita;
    return prezzo;
}
