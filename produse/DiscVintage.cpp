#include "DiscVintage.h"

DiscVintage :: DiscVintage(bool isMint, int raritate, string tip, string casaDiscuri, string dataVanzare, string trupa, string numeAlbum, string denumire, int nrProduse, int pretBaza, int ID) : Disc(tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire, nrProduse, pretBaza, ID), Produs(denumire, nrProduse, pretBaza, ID), isMint(isMint) {
    if(raritate < 1 || raritate > 5){
        throw invalid_argument("Raritatea trebuie sa fie intre 1-5");
    }

    this->raritate = raritate;
};


void DiscVintage :: afisare(){
    Disc :: afisare();
    if(isMint){
        cout << "Este mint: da" << endl;
    }else{
        cout << "Este mint: nu" << endl;
    }
    
    cout << "Raritate: " << raritate << endl;
}

int DiscVintage :: getPretTotal(){
    return pretBaza + 5 + 15 * raritate;
}

DiscVintage& DiscVintage::operator=(const DiscVintage& aux) {
    if (this != &aux) {
        Disc::operator=(aux);
        isMint = aux.isMint;
        raritate = aux.raritate;
    }
    return *this;
}

int DiscVintage :: getID(){
    return ID;
}

void DiscVintage :: modifRaritate(int raritateNoua){
    raritate = raritateNoua;
}
void DiscVintage :: modifMint(bool isMintNou){
    isMint = isMintNou;
}