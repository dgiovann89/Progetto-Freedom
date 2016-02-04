#ifndef ONOFF_H
#define ONOFF_H

#include<macchinario.h>

class OnOff : public Macchinario{
public:
    OnOff(string, string, int, int, int, float, int, bool, Cliente* =0, SalaCompressori* =0);
    string getTipo() const;
    virtual bool isCompressore() const;
};

#endif // ONOFF_H
