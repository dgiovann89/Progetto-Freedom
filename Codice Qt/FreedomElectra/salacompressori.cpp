#include "salacompressori.h"

SalaCompressori::SalaCompressori(string n, Cliente* cl, int k, int p):nome(n), proprietario(cl), kwTot(k), portataTot(p){}

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

// set
void SalaCompressori::setNome(string s){
    nome = s;
}
void SalaCompressori::setProprietario(Cliente * punt){
    proprietario = punt;
}
//void SalaCompressori::setKwTot(...) {
//    int kw_compr, kw_essicc = 0;
//    for (int i=0;i<compressori){
//        kw_compr = kw_compr+compressore.getKw();
//    }
//    for (int i=0;i<essiccatori){
//        kw_essicc = kw_essicc+essiccatore.getKw();
//    }
//    kwTot = kwTot + kw_compr + kw_essicc;
//}
