#ifndef ONOFF_H
#define ONOFF_H

#include<macchinario.h>

class OnOff : public Macchinario{
public:
    OnOff(string, string, int, int, int, Cliente*, SalaCompressori*,int);
};

#endif // ONOFF_H
