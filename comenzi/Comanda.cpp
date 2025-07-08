#include "Comanda.h"
#include "../functions/functions.h"

int Comanda :: getValoareComanda(){
    int valoare = 0;

    for(int i = 0; i < produse.size(); i++){
        valoare += produse[i]->getPretTotal();
    }

    return valoare;
}

Comanda :: Comanda(vector<ComandaInfo> info, string data, string ora, int durataSolutionare, int ID) : data(data), ora(ora), durataSolutionare(durataSolutionare), ID(ID){

    vector<Produs*> stoc;
    getStocMagazin(stoc);

    for(int i = 0; i < info.size(); i++){
        int ok = 0;
        for(int j = 0; j < stoc.size(); j++)
            if(info[i].denumire.compare(stoc[j]->getDenumire()) == 0){
                ok = 1;
                
                stoc[j]->modifNrProd(info[i].nrProduse);
                produse.push_back(stoc[j]);
                
            }
        if(!ok){
            throw invalid_argument("Unul dintre produsele introduse nu exista in stoc");
        }
        
    }

    int nrHaine = 0, nrDiscuri = 0;

    for(int i = 0; i < produse.size(); i++){
        if(typeid(*produse[i]) == typeid(ArticolVestimentar)){
            nrHaine++;
        }
        if(typeid(*produse[i]) == typeid(Disc) || typeid(*produse[i]) == typeid(DiscVintage)){
            nrDiscuri++;
        }
    }

    if(nrHaine > 3){
        throw invalid_argument("Nu puteti avea o comanda cu mai mult de 3 articole vestimentare");
    }

    if(nrDiscuri > 5){
        throw invalid_argument("Nu puteti avea o comanda cu mai mult de 5 discuri");
    }


    if(this->getValoareComanda() < 100){
        throw invalid_argument("Comanda nu are valoarea minima de 100 de lei");
    }
}


Comanda& Comanda :: operator=(const Comanda &c) {
    if (this != &c) {
        produse = c.produse;
        data = c.data;
        durataSolutionare = c.durataSolutionare;
        ID = c.ID;
    }
    return *this;
}

void Comanda :: afisare(){
    for(int i = 0; i < produse.size(); i++){
        produse[i]->afisare();
        cout << endl;
    }

    cout << "Data la care a fost introdusa comanda este: " << data << endl;
    cout << "Ora la care a fost introdusa comanda este: " << ora << endl;
    cout << "Durata estimata a solutionarii este " << durataSolutionare << " minute." << endl;
    cout << "ID-ul comenzii: " << ID << endl;
}

int Comanda :: getID(){
    return ID;
}

bool Comanda::isFinalizata() {
    int* dataCur = getDataCurenta();
    int* oraCur = getOraCurenta();

    int zi = stoi(data.substr(0, 2));
    int luna = stoi(data.substr(3, 2));
    int an = stoi(data.substr(6, 4));

    int orai = stoi(ora.substr(0, 2));
    int minut = stoi(ora.substr(3, 2));

    int ziFinalizare = zi;
    int lunaFinalizare = luna;
    int anFinalizare = an;
    int oraFinalizare = orai;
    int minutFinalizare = minut + durataSolutionare;

    if (minutFinalizare >= 60) {
        oraFinalizare += minutFinalizare / 60;
        minutFinalizare %= 60;
    }
    if (oraFinalizare >= 24) {
        ziFinalizare += oraFinalizare / 24;
        oraFinalizare %= 24;
    }

    int zileInLuna[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((anFinalizare % 4 == 0 && anFinalizare % 100 != 0) || (anFinalizare % 400 == 0)) {
        zileInLuna[1] = 29;
    }

    if (ziFinalizare > zileInLuna[lunaFinalizare - 1]) {
        ziFinalizare -= zileInLuna[lunaFinalizare - 1];
        lunaFinalizare++;
        if (lunaFinalizare > 12) {
            lunaFinalizare = 1;
            anFinalizare++;
        }
    }

    int ziCurenta = dataCur[0];
    int lunaCurenta = dataCur[1];
    int anCurent = dataCur[2];
    int oraCurenta = oraCur[0];
    int minutCurent = oraCur[1];

    if (anCurent > anFinalizare) return true;
    if (anCurent == anFinalizare && lunaCurenta > lunaFinalizare) return true;
    if (anCurent == anFinalizare && lunaCurenta == lunaFinalizare && ziCurenta > ziFinalizare) return true;
    if (anCurent == anFinalizare && lunaCurenta == lunaFinalizare && ziCurenta == ziFinalizare && oraCurenta > oraFinalizare) return true;
    if (anCurent == anFinalizare && lunaCurenta == lunaFinalizare && ziCurenta == ziFinalizare && oraCurenta == oraFinalizare && minutCurent >= minutFinalizare) return true;

    return false;
}
