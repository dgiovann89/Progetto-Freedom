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

//void SalaCompressori::setKwTot() {
//    int kw_compr = 0;
//    intkw_essicc = 0;

//    vector<Componente>::const_iterator it=.begin();
//    int row = tabellaClienti->rowCount();
//    for(;it!=dbc->getDatabase().end();++it){

//    for (int i=0;i<compressori){
//        kw_compr = kw_compr+compressore.getKw();
//    }
//    for (int i=0;i<essiccatori){
//        kw_essicc = kw_essicc+essiccatore.getKw();
//    }
//    kwTot = kwTot + kw_compr + kw_essicc;
//}

//scorro il vector di componenti
// per ogni elemento del vector verifico se è compressore o essiccatore
//    aggiorno i kw_totali e porata totale
// esco

