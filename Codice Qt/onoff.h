#ifndef ONOFF_H
#define ONOFF_H

#include "macchinario.h"

class OnOff : public Macchinario{
private:
    int oreVuoto;
public:
    OnOff(string, string, int, float, float, float, int, int, int, bool, Cliente* =0, SalaCompressori* =0, int =0);
    string getTypeInfo() const;

    // get
    int getOreVuoto() const;

    // set
    void setOreVuoto(int);

    virtual double calcolaPrezzo() const;
};

#endif // ONOFF_H
