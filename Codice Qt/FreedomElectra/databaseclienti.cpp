#include "databaseclienti.h"

DatabaseClienti::DatabaseClienti(){}

// add
void DatabaseClienti::aggiungiCliente(const Cliente & c){
    vettoreClienti.push_back(c);
}

// remove
void DatabaseClienti::rimuoviCliente(int i){
    vector<Cliente>::iterator it=vettoreClienti.begin()+i;
    vettoreClienti.erase(it);
}

vector<Cliente>& DatabaseClienti::getDatabase() const{
    return const_cast<vector<Cliente>&>(vettoreClienti);
}
