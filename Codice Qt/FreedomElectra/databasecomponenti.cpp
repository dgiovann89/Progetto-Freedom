#include "databasecomponenti.h"

//Definizioni classe Nodo

//costruttore
DatabaseComponenti::Nodo::Nodo(Componente* r): info(r) {}

//costruttore
DatabaseComponenti::Nodo::Nodo(Componente* r, Nodo* s):info(r), next(s){}

//----------------------------------------------------
//definizioni classe Iteratore

//operatore di uguaglianza
bool DatabaseComponenti::Iteratore::operator==(const Iteratore& i) const{
    return iit==i.iit;
}

//operatore di disuguaglianza
bool DatabaseComponenti::Iteratore::operator!=(const Iteratore& i) const{
    return iit!=i.iit;}

//incremento prefisso
DatabaseComponenti::Iteratore& DatabaseComponenti::Iteratore::operator++(){
    if(iit)
        iit=iit->next;
    return *this;
}

//incremento postfisso
DatabaseComponenti::Iteratore& DatabaseComponenti::Iteratore::operator++(int){
    Iteratore aux=*this;
    if(iit)
        iit=iit->next;
    return aux;
}

//Operatore di dereferenziazione
Componente* DatabaseComponenti::Iteratore::operator *() const{
    return iit->info;
}


//----------------------------------------------------
//Definizioni classe DatabaseComponenti

//costruttore
DatabaseComponenti::DatabaseComponenti():primo(0){}

//costruttore di copia
DatabaseComponenti::DatabaseComponenti (const DatabaseComponenti& d):primo(d.primo){}

//distruttore
DatabaseComponenti::~DatabaseComponenti(){}

//begin
DatabaseComponenti::Iteratore DatabaseComponenti::begin() const{
    Iteratore temp;
    temp.iit=primo;
    return temp;
}

//end
DatabaseComponenti::Iteratore DatabaseComponenti::end() const{
    Iteratore temp;
    temp.iit=0;
    return temp;
}
//operatore  di indicizzazione
DatabaseComponenti::Nodo& DatabaseComponenti::operator[] (DatabaseComponenti::Iteratore it) const{
    return *(it.iit);
}

//isEmpty
bool DatabaseComponenti::isEmpty() const {
    return (primo == 0);
}

//inserimento
bool DatabaseComponenti::inserisciComponente(Componente* r){
    primo= new Nodo(r,primo);
    return true;
}

//cancellazione di un Componente
void DatabaseComponenti::rimuoviComponente(const Componente& r){
    Nodo* p=primo, *prec=0;
    while(p && !(p->info==&r)){
        prec=p;
        p=p->next;
    }
    if(p){
        if(!prec)
            primo=p->next;
        else
            prec->next=p->next;
        delete p;
    }
}

// cerca Componente (ritorna l'iteratore che punta al componente (se c'è)) e cerca per id
DatabaseComponenti::Iteratore DatabaseComponenti::cercaComponente(int idComp){
    Iteratore it= this->begin();
    while (it!= this->end()) {
        if (((*it)->getIdComponente()==idComp)){
            return it;
        }
        ++it;
    }
    return this->end();
}
