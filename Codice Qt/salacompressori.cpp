#include "salacompressori.h"

SalaCompressori::SalaCompressori(string n, Cliente* cl, int k, int p, float press, int port, string i, double v):nome(n), proprietario(cl), kwTot(k), portataTot(p), pressioneRichiesta(press), portataRichiesta(port), impianto(i), valoreSala(v){}

SalaCompressori::~SalaCompressori(){}

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
float SalaCompressori::getPressioneRichiesta() const {
    return pressioneRichiesta;
}
int SalaCompressori::getPortataRichiesta() const {
    return portataRichiesta;
}
string SalaCompressori::getImpianto() const {
    return impianto;
}
double SalaCompressori::getValoreSala() const {
    return valoreSala;
}

// set
void SalaCompressori::setNome(string s){
    nome = s;
}
void SalaCompressori::setProprietario(Cliente * punt){
    proprietario = punt;
}
void SalaCompressori::setPressioneRichiesta(float p) {
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
void SalaCompressori::setValoreSala(double v){
    valoreSala = v;
}
