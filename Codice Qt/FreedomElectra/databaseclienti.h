#ifndef DATABASECLIENTI_H
#define DATABASECLIENTI_H

#include "cliente.h"

class DatabaseClienti{
private:
    vector<Cliente> vettoreClienti;
public:
    DatabaseClienti();

    // add e remove dal vector
    void aggiungiCliente(const Cliente &);
    void rimuoviCliente(int);
    vector<Cliente>& getDatabase() const; // ritorno vector per rif
    Cliente& getCliente(int) const;
};



#endif // DATABASECLIENTI_H
