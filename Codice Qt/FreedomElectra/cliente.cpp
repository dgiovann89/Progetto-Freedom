#include "cliente.h"

Cliente::Cliente(string r, string t, string e, string f, string p, Indirizzo i):ragioneSociale(r), telefono(t), email(e), fax(f), pIva(p), ind(i){}

// get
string Cliente::getRagioneSociale() const {
    return ragioneSociale;
}
string Cliente::getTelefono() const {
    return telefono;
}
string Cliente::getEmail() const{
    return email;
}
string Cliente::getFax() const{
    return fax;
}
string Cliente::getPIva() const {
    return pIva;
}
Indirizzo Cliente::getIndirizzo() const {
    return ind;
}

// set
void Cliente::setRagioneSociale(string s){
    ragioneSociale = s;
}
void Cliente::setTelefono(string s){
    telefono = s;
}
void Cliente::setEmail(string s){
    email = s;
}
void Cliente::setFax(string s){
    fax = s;
}
void Cliente::setPIva(string s){
    pIva = s;
}
void Cliente::setInd(Indirizzo i){
    ind = i;
}

bool Cliente::operator==(const Cliente& c) const {
    return ragioneSociale==c.ragioneSociale && ind==c.ind;
}

void Cliente::aggiungiSala(const SalaCompressori & s) {
    sala.push_back(s);
}
void Cliente::rimuoviSala(int i) {
    vector<SalaCompressori>::iterator it=sala.begin()+i;
    sala.erase(it);
}
