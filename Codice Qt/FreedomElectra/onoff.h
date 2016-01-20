#ifndef ONOFF_H
#define ONOFF_H

#include<macchinario.h>

class OnOff : public Macchinario{
public:
    OnOff(string, string, int, int, int, float, int,Cliente* =0, SalaCompressori* =0);
    string getTipo() const;
};

#endif // ONOFF_H
