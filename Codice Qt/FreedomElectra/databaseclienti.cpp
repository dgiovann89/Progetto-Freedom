#include "databaseclienti.h"

DatabaseClienti::DatabaseClienti(){}

// add
void DatabaseClienti::aggiungiCliente(const Cliente & c){
    vettoreClienti.push_back(c);
}

vector<Cliente>& DatabaseClienti::getDatabase() const{
    return const_cast<vector<Cliente>&>(vettoreClienti);
}

Cliente& DatabaseClienti::getCliente(int i) const {
    return const_cast<Cliente&>(vettoreClienti[i]);
}

//lettura e scrittura da file
void DatabaseClienti::read(const QJsonObject &json){
    vettoreClienti.clear();
    QJsonArray cliArray=json["Archivio Clienti"].toArray();
    for(int i=0; i<cliArray.size();++i){
        QJsonObject clientiObject=cliArray[i].toObject();
        Cliente c;
        c.read(clientiObject);
        vettoreClienti.push_back(c);
    }
}

void DatabaseClienti::write(QJsonObject &json) const{
    QJsonArray cliArray;
    foreach(const Cliente cli, vettoreClienti){
        QJsonObject clientiObject;
        cli.write(clientiObject);
        cliArray.append(clientiObject);
    }
    json["Archivio Clienti"]=cliArray;
}

bool DatabaseClienti::loadClienti(DatabaseClienti::SaveFormat){
    QFile loadFile(QStringLiteral("save.json"));
    if(!loadFile.open(QIODevice::ReadOnly)){
        qWarning("Non posso aprire il file di salvataggio");
        return false;
    }

    QByteArray saveData=loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    read(loadDoc.object());
    return true;
}

bool DatabaseClienti::saveClienti(DatabaseClienti::SaveFormat) const{
    QFile saveFile(QStringLiteral("save.json"));
    if(!saveFile.open(QIODevice::WriteOnly)){
        qWarning("Non posso aprire il file di salvataggio");
        return false;
    }
    QJsonObject dbClientiObject;
    write(dbClientiObject);
    QJsonDocument saveDoc(dbClientiObject);
    saveFile.write(saveDoc.toJson());
    return true;
}
