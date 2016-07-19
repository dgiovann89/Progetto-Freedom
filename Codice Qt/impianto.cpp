#include "impianto.h"

Impianto::Impianto(string ma, string mod, int a, int press, int port, float cdp, string mat, Cliente* cl, SalaCompressori* s, int id):Componente(ma,mod,a,press,port,cdp,cl,s,id), materiale(mat){}

string Impianto::getTypeInfo() const {
    return "Impianto";
}

// get
string Impianto::getMateriale() const {
    return materiale;
}

// set
void Impianto::setMateriale(string m){
    materiale = m;
}

double Impianto::calcolaPrezzo() const {
    double prezzo = 0;
    if (materiale=="alluminio" || materiale=="Alluminio")
        prezzo = (getPortata()*60)*0.7;
    else
        prezzo = (getPortata()*60)*0.5;
    return prezzo;
}
