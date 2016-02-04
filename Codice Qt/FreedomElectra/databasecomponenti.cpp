#include "databasecomponenti.h"

//Definizione classe Smartp

//costruttore
DatabaseComponenti::Smartp::Smartp(Nodo* p): it(p){
    if(it)
        it->riferimenti++;
}

//distruttore
DatabaseComponenti::Smartp::~Smartp(){
   if(it){
       it->riferimenti--;
       if(it->riferimenti==0)
             delete it;
      }
}

//costruttore di copia
DatabaseComponenti::Smartp::Smartp(const Smartp & s):it(s.it){
    if(it)
        it->riferimenti--;
}

//assegnazione
DatabaseComponenti::Smartp& DatabaseComponenti::Smartp::operator= (const Smartp &s){
    if(*this!=s){
        Nodo* t=it;
        it=s.it;
        if(it)
            it->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti == 0)
                delete t;
        }
    }
    return *this;
}

//dereferenziazione
DatabaseComponenti::Nodo& DatabaseComponenti::Smartp::operator*() const{
    return const_cast <Nodo&>(*it);
}

//Operatore di accesso a membro
 DatabaseComponenti::Nodo* DatabaseComponenti::Smartp::operator->() const{
     return it;
 }
//operatore di uguaglianza
bool DatabaseComponenti::Smartp::operator==(const Smartp& s) const{
    return it==s.it;
}

//operatore di disuguaglianza
bool DatabaseComponenti::Smartp::operator !=(const Smartp& s) const{
    return it!=s.it;
}

//----------------------------------------------------
//Definizioni classe Nodo

//costruttore
DatabaseComponenti::Nodo::Nodo(Componente* r): info(r), riferimenti(0) {}

//costruttore
DatabaseComponenti::Nodo::Nodo(Componente* r, const Smartp & s):info(r), next(s), riferimenti(0){}



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
        iit=iit->next.it;
    return *this;
}

//incremento postfisso
DatabaseComponenti::Iteratore& DatabaseComponenti::Iteratore::operator++(int){
    Iteratore aux=*this;
    if(iit)
        iit=iit->next.it;
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
    temp.iit=primo.it;
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
bool DatabaseComponenti::rimuoviComponente(Componente* r){
    Iteratore it=this->begin(), itPrec=this->begin();
    if(it.iit->info== r){ // se è il primo elemento
        primo=primo->next;
        return true;
    }
    ++it;
    while (it!=this->end()) { // scorro gli elementi successivi
       if(it.iit->info==r){
           itPrec.iit->next= it.iit->next;
           return true;
       }
       ++it;
       ++itPrec;
    }
    return false;
}

// cerca Componente (ritorna l'iteratore che punta al Componente (se c'è))
//DatabaseComponenti::Iteratore DatabaseComponenti::cercaComponente(string q) {
//   Iteratore it= this->begin();
//   while (it!= this->end()) {
//      if ((*it)->getMarca() == q)
//         return it;
//      ++it;
//   }
//   return this->end();
//}

// cerca Riparazione (ritorna l'iteratore che punta al componente (se c'è))
DatabaseComponenti::Iteratore DatabaseComponenti::cercaComponente(const string& marca,const string& modello){
   Iteratore it= this->begin();
   while (it!= this->end()) {
      if (((*it)->getMarca()== marca) && ((*it)->getModello()== modello)){
          return it;
      }
      ++it;
   }
   return this->end();
}
