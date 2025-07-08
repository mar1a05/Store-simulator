#include "Disc.h"

void Disc :: afisare() {
    Produs :: afisare();
    cout << "tip: " << tip << endl;
    cout << "casa discuri: " << casaDiscuri << endl;
    cout << "data vanzare: " << dataVanzare << endl;
    cout << "trupa: " << trupa << endl;
    cout << "nume album: " << numeAlbum << endl;

} 

int Disc :: getPretTotal(){
    return pretBaza + 5;
}

Disc& Disc::operator=(const Disc& aux) {
    if (this != &aux) {
        Produs::operator=(aux);
        tip = aux.tip;
        casaDiscuri = aux.casaDiscuri;
        dataVanzare = aux.dataVanzare;
        trupa = aux.trupa;
        numeAlbum = aux.numeAlbum;
    }
    return *this;
}

int Disc :: getID(){
    return ID;
}

void Disc :: modifTip(string tipNou){
    tip = tipNou;
}
void Disc :: modifCasaDiscuri(string casaDiscuriNoua){
    casaDiscuri = casaDiscuriNoua;
}
void Disc :: modifDataVanzare(string dataVanzareNoua){
    dataVanzare = dataVanzareNoua;
}
void Disc :: modifTrupa(string trupaNoua){
    trupa = trupaNoua;
}
void Disc :: modifNumeAlbum(string numeAlbumNou){
    numeAlbum = numeAlbumNou;
}