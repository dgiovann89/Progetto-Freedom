#ifndef MACCHINARIO_H
#define MACCHINARIO_H

#include<componente.h>

class Macchinario : public Componente{
private:
    int kw;
public:
    Macchinario(string, string, int, int, int, Cliente*, SalaCompressori*,int);
    string getTipo() const;
    // get
    int getKw() const;

    // set
    void setKw(int);
};

#endif // MACCHINARIO_H
