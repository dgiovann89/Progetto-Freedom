#ifndef DATABASECLIENTI_H
#define DATABASECLIENTI_H

#include "cliente.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>


class DatabaseClienti{
private:
    vector<Cliente> vettoreClienti;

public:
    DatabaseClienti();

    void read(const QJsonObject& json);
    void write(QJsonObject &json) const;

    enum SaveFormat{
        Json
    };

    bool loadClienti(SaveFormat saveFormat);
    bool saveClienti(SaveFormat saveFormat) const;

    // add e remove dal vector
    void aggiungiCliente(const Cliente &);
    vector<Cliente>& getDatabase() const; // ritorno il vector per riferimento
    Cliente& getCliente(int) const;
};

#endif // DATABASECLIENTI_H
