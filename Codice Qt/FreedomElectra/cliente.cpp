#include "cliente.h"

Cliente::Cliente(string r, string t, string e, string f, string p, string s, Indirizzo i) : ragioneSociale(r), telefono(t), email(e), fax(f), pIva(p), stabilimento(s), ind(i){}

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
string Cliente::getStabilimento() const {
    return stabilimento;
}
Indirizzo Cliente::getIndirizzo() const {
    return ind;
}
vector<SalaCompressori> & Cliente::getSala() const {
    return const_cast<vector<SalaCompressori>&>(sala);
}
SalaCompressori& Cliente::getSala(int i) const{
    return const_cast<SalaCompressori&>(sala[i]);
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
void Cliente::setStabilimento(string s){
    stabilimento = s;
}
void Cliente::setInd(const Indirizzo& i){
    ind = i;
}
bool Cliente::operator==(const Cliente& c) const {
    return ragioneSociale==c.ragioneSociale && ind==c.ind;
}
void Cliente::aggiungiSala(const SalaCompressori& s) {
    sala.push_back(s);
}
void Cliente::rimuoviSala(int i) {
    vector<SalaCompressori>::iterator it=sala.begin()+i;
    sala.erase(it);
}

//metodi per leggere da file
void Cliente::read(const QJsonObject &json){
    ragioneSociale=(json["jRagioneSociale"].toString()).toStdString();
    telefono=(json["jTelefono"].toString()).toStdString();
    email=(json["jEmail"].toString()).toStdString();
    fax=(json["jFax"].toString()).toStdString();
    pIva=(json["jPIva"].toString()).toStdString();
    stabilimento=(json["jStabilimento"].toString()).toStdString();

    ind.setVia(json["jVia"].toString().toStdString());
    ind.setCap(json["jCAP"].toString().toStdString());
    ind.setCitta(json["jCitta"].toString().toStdString());
    ind.setProvincia(json["jProvincia"].toString().toStdString());
}

//metodi per scrivere su file
void Cliente::write(QJsonObject &json) const{
    json["jRagioneSociale"]=QString::fromStdString(ragioneSociale);
    json["jTelefono"]=QString::fromStdString(telefono);
    json["jEmail"]=QString::fromStdString(email);
    json["jFax"]=QString::fromStdString(fax);
    json["jPIva"]=QString::fromStdString(pIva);
    json["jStabilimento"]=QString::fromStdString(stabilimento);

    json["jVia"]=QString::fromStdString(ind.getVia());
    json["jCAP"]=QString::fromStdString(ind.getCap());
    json["jCitta"]=QString::fromStdString(ind.getCitta());
    json["jProvincia"]=QString::fromStdString(ind.getProvincia());
}
