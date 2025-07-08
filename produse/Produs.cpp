#include "Produs.h"

Produs :: Produs(string denumire, int nrProduse, int pretBaza, int ID) : denumire(denumire), ID(ID) {
    if(nrProduse <= 0){
        throw invalid_argument("Numarul de produse nu poate fi negativ sau 0.");
    }

    this->nrProduse = nrProduse;

    if(pretBaza == 0){
        throw invalid_argument("Pretul de baza nu poate fi negativ sau 0.");
    }

    this->pretBaza = pretBaza;
}

void Produs:: modifNrProd(int nrProduseNou){
    nrProduse = nrProduseNou;
}

void Produs :: modifPretBaza(int pretBazaNou){
    pretBaza = pretBazaNou;
}

void Produs :: modifDenumire(string denumireNoua){
    denumire = denumireNoua;
}

int Produs :: getPretTotal(){
    return pretBaza;
}

void Produs :: afisare(){
    cout << "denumire: " << denumire << endl;
    cout << "nrPoduse: " << nrProduse << endl;
    cout << "pret baza: " << pretBaza << endl;
    cout << "pret total:" << this->getPretTotal() << endl;
    cout << "id: " << ID << endl;
}


int Produs :: getPretBaza(){
    return pretBaza;
}

int Produs :: getNrProduse(){
    return nrProduse;
}

int Produs :: getID(){
    return ID;
}

string Produs :: getDenumire(){
    return denumire;
}

Produs& Produs::operator=(const Produs& aux) {
    if (this != &aux) {
        denumire = aux.denumire;
        nrProduse = aux.nrProduse;
        pretBaza = aux.pretBaza;
        ID = aux.ID;
    }
    return *this;
}

