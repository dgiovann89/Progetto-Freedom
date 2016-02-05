#include "salacompressori.h"

SalaCompressori::SalaCompressori(string n, Cliente* cl, int k, int p, int press, int port, string i):nome(n), proprietario(cl), kwTot(k), portataTot(p), pressioneRichiesta(press), portataRichiesta(port), impianto(i){}

SalaCompressori::~SalaCompressori(){
}

// get
string SalaCompressori::getNome() const{
    return nome;
}
Cliente* SalaCompressori::getProprietario() const{
    return proprietario;
}
int SalaCompressori::getKwTot() const{
    return kwTot;
}
int SalaCompressori::getPortataTot() const{
    return portataTot;
}
vector<Componente*>& SalaCompressori::getComponenti() const {
    return const_cast<vector<Componente*>&>(componenti);
}
Componente* SalaCompressori::getComponente(int i) const{
    return const_cast<Componente*>(componenti[i]);
}
int SalaCompressori::getPressioneRichiesta() const {
    return pressioneRichiesta;
}
int SalaCompressori::getPortataRichiesta() const {
    return portataRichiesta;
}
string SalaCompressori::getImpianto() const {
    return impianto;
}

// set
void SalaCompressori::setNome(string s){
    nome = s;
}
void SalaCompressori::setProprietario(Cliente * punt){
    proprietario = punt;
}
void SalaCompressori::setPressioneRichiesta(int p) {
    pressioneRichiesta = p;
}
void SalaCompressori::setPortataRichiesta(int p) {
    portataRichiesta = p;
}
void SalaCompressori::setImpianto(string i) {
    impianto = i;
}
void SalaCompressori::aggiungiComponente(Componente * c){
    componenti.push_back(c);
}
void SalaCompressori::rimuoviComponente(int i){
    vector<Componente*>::iterator it=componenti.begin()+i;
    componenti.erase(it);
}
void SalaCompressori::setKwTot(int i) {
    kwTot = i;
}
void SalaCompressori::setPortataTot(int i){
    portataTot=i;
}

//metodi per file
void SalaCompressori::readSala(const QJsonObject &json){
//    nome = (json["jNome"].toString().toStdString());
////    &proprietario = (json["jProprietario"].toString().toStdString());
//    kwTot = (json["jKwTot"].toInt());
//    portataTot = (json["jPortataTot"].toInt());
//    pressioneRichiesta = (json["jPressioneRichiesta"].toInt());
//    portataRichiesta = (json["jPortataRichiesta"].toInt());
//    impianto = (json["jImpianto"].toString().toStdString());
//    // mancherebbe il load dei componenti nel vector
}

void SalaCompressori::writeSala(QJsonObject &json) const{
//    json["jRagioneSociale"]=QString::fromStdString(getProprietario()->getRagioneSociale());
    json["jRagioneSociale"]=QString::fromStdString("getProprietario()->getRagioneSociale()");
//    json["jStabilimento"]=QString::fromStdString(getProprietario()->getStabilimento());
    json["jStabilimento"]=QString::fromStdString("getProprietario()->getStabilimento()");

//    Cliente* a = getProprietario();
//    std::cout << &a << std::endl;
//    string b = std::to_string(a);
//    getProprietario().getIdCliente;
//    json["jProprietario"] = QString::fromStdString(&a);
    json["jNome"] = QString::fromStdString(getNome());
    json["jKwTot"] = getKwTot();
    json["jPortataTot"] = getPortataTot();
    json["jPressioneRichiesta"]= getPressioneRichiesta();
    json["jPortataRichiesta"]= getPortataRichiesta();
    // mancherebbe il salvataggio del vector componenti che faccio a meno di farlo
    json["jImpianto"]=QString::fromStdString(impianto);

}
