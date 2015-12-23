#ifndef DATABASECOMPONENTI_H
#define DATABASECOMPONENTI_H

#include<iostream>
#include<componente.h>

using std::string;
// Item == Nodo

class DatabaseComponenti{
    friend class Iteratore;
private:
        class Nodo; //dichiarazione incompleta

        //dichiarazione Smartp
        class Smartp{
        public:
            Nodo* it;
            Smartp(Nodo* p = 0); //costruttore
            ~Smartp(); //distruttore
            Smartp(const Smartp&); //costruttore di copia

            Smartp& operator=(const Smartp&); //assegnazione
            Nodo& operator*() const; //dereferenziazione
            Nodo* operator->() const; //accesso a membro
            bool operator==(const Smartp&) const; //uguaglianza
            bool operator!=(const Smartp&) const; //disuguaglianza
        };

        //Dichiarazione Nodo
        class Nodo{
        public:
            Componente* info;
            Smartp next;
            int riferimenti;

            Nodo(Componente*); //costruttore
            Nodo(Componente*, const Smartp&); //costruttore
        };

    Smartp primo;

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
        bool rimuoviComponente(Componente*);
        Iteratore cercaComponente(string); //cerca per tipologia

};

#endif // DATABASECOMPONENTI_H
