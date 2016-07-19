#ifndef MACCHINARIO_H
#define MACCHINARIO_H

#include "componente.h"

class Macchinario : public Componente{
private:
    int kw;
    int oreCarico;
    bool compressore;

public:
    Macchinario(string, string, int, float, float, float, int, int, bool, Cliente* =0, SalaCompressori* =0, int =0);

    // get
    int getKw() const;
    int getOreCarico() const;


    // set
    void setKw(int);
    void setOreCarico(int);

    bool isCompressore() const;
    virtual double calcolaPrezzo() const =0;
};

#endif // MACCHINARIO_H
