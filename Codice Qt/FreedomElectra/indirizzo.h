#ifndef INDIRIZZO_H
#define INDIRIZZO_H

#include<iostream>

using std::string;
using std::ostream;
using std::endl;

class Indirizzo{
private:
    string via;
    string città;
    string provincia;
    string cap;

public:
    Indirizzo(string="",string="",string="",string="");

    // get
    string getVia() const;
    string getCittà() const;
    string getProvincia() const;
    string getCap() const;

    // set
    void setVia(string);
    void setCittà(string);
    void setProvincia(string);
    void setCap(string);

    bool operator==(const Indirizzo&) const;
};

ostream& operator<< (const ostream&, const Indirizzo&);

#endif // INDIRIZZO_H
