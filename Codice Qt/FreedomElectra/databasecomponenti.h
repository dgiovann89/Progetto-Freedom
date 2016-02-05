#ifndef DATABASECOMPONENTI_H
#define DATABASECOMPONENTI_H

#include <iostream>
#include "componente.h"
#include <QString>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

// Item == Nodo

class DatabaseComponenti{
    friend class Iteratore;
private:
    //Dichiarazione Nodo
    class Nodo{
    public:
        Componente* info;
        Nodo* next;


        Nodo(Componente*); //costruttore
        Nodo(Componente*,Nodo*); //costruttore
    };

    Nodo* primo;
public:
    DatabaseComponenti();
    DatabaseComponenti(const DatabaseComponenti&);
    ~DatabaseComponenti();

    //dichiarazione classe pubblica Iteratore
    class Iteratore{
        friend class DatabaseComponenti;
    private:
        Nodo* iit;
    public:
        bool operator==(const Iteratore&) const; //uguaglianza
        bool operator!=(const Iteratore&) const;//disuguaglianza
        Iteratore& operator++();//incremento prefisso
        Iteratore& operator++(int);//incremento postfisso
        Componente* operator*() const; //dereferenziazione
    };

    Iteratore begin() const;
    Iteratore end() const;
    Nodo & operator[] (Iteratore) const;

    bool isEmpty() const;

    bool inserisciComponente(Componente*);
    void rimuoviComponente(const Componente& );

    Iteratore cercaComponente(int);
};

#endif // DATABASECOMPONENTI_H
