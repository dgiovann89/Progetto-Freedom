#include "indirizzo.h"

Indirizzo::Indirizzo(string v,string c,string p,string ca):via(v), citta(c), provincia(p), cap(ca){}

// get
string Indirizzo::getVia() const {
    return via;
}
string Indirizzo::getCitta() const {
    return citta;
}
string Indirizzo::getProvincia() const{
    return provincia;
}
string Indirizzo::getCap() const{
    return cap;
}

// set
void Indirizzo::setVia(string s) {
    via = s;
}
void Indirizzo::setCitta(string s) {
    citta = s;
}
void Indirizzo::setProvincia(string s){
    provincia = s;
}
void Indirizzo::setCap(string s){
    cap = s;
}

ostream& operator<<(ostream &os, const Indirizzo &i) {
    return os << "Via:" << i.getVia() << endl << "Citta: " << i.getCitta() << endl << "Provincia: " << i.getProvincia() << endl << "Cap:" << i.getCap() << endl;
}
bool Indirizzo::operator==(const Indirizzo& i) const {
    return via==i.via && citta==i.citta && provincia==i.provincia && cap==i.cap;
}
