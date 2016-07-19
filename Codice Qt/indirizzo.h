#ifndef INDIRIZZO_H
#define INDIRIZZO_H

#include<iostream>

using std::string;
using std::ostream;
using std::endl;

class Indirizzo{
private:
    string via;
    string citta;
    string provincia;
    string cap;

public:
    Indirizzo(string="",string="",string="",string="");

    // get
    string getVia() const;
    string getCitta() const;
    string getProvincia() const;
    string getCap() const;

    // set
    void setVia(string s);
    void setCitta(string s);
    void setProvincia(string s);
    void setCap(string s);

    bool operator==(const Indirizzo&) const;
};

ostream& operator<< (const ostream&, const Indirizzo&);

#endif // INDIRIZZO_H
