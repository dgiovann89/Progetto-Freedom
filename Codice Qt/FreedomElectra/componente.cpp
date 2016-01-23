#include "componente.h"

Componente::Componente(string ma, string mod, int a, float press, float port, float cdp,Cliente* cl, SalaCompressori* s):marca(ma), modello(mod), anno(a), pressione(press), portata_capacita(port), cadutaDiPressione(cdp), proprietario(cl), sala(s){}
Componente::~Componente(){}

// get
string Componente::getMarca() const{
    return marca;
}
string Componente::getModello() const{
    return modello;
}
int Componente::getAnno() const {
    return anno;
}
float Componente::getPressione() const {
    return pressione;
}
float Componente::getPortata_capacita() const {
    return portata_capacita;
}
float Componente::getCadutaDiPressione() const {
    return cadutaDiPressione;
}
Cliente* Componente::getCliente() const{
    return proprietario;
}
SalaCompressori* Componente::getSala() const{
    return sala;
}

// set
void Componente::setMarca(string s) {
    marca = s;
}
void Componente::setModello(string s) {
    modello = s;
}
void Componente::setAnno(int i) {
    anno = i;
}
void Componente::setPressione(float i) {
    pressione = i;
}
void Componente::setPortata_capacita(float i) {
    portata_capacita = i;
}
void Componente::setCadutaDiPressione(float c) {
    cadutaDiPressione = c;
}

void Componente::setProprietario(Cliente * punt){
    proprietario = punt;
}
void Componente::setSala(SalaCompressori * punt){
    sala = punt;
}
//void Componente::setTipo(string s){
//    tipo = s;
//}
