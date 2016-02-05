#ifndef MACCHINARIO_H
#define MACCHINARIO_H

#include "componente.h"

class Macchinario : public Componente{
private:
    int kw;

protected:
    bool compressore;

public:
    Macchinario(string, string, int, float, float, float, int, bool, Cliente* =0, SalaCompressori* =0, int =0);

    // get
    virtual int getKw() const;

    // set
    virtual void setKw(int);

    virtual bool isCompressore() const =0;
};

#endif // MACCHINARIO_H
