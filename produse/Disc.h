#include <iostream>
#include <string>
#include <chrono>
#include "Produs.h"
#include "../utils.h"
#pragma once


using namespace std;

class Disc : virtual public Produs {
protected:
    string tip = "N/A";
    string casaDiscuri = "N/A";
    string dataVanzare = "N/A";
    string trupa = "N/A";
    string numeAlbum = "N/A";
public:
    Disc() = default;
    Disc(string tip, string casaDiscuri, string dataVanzare, string trupa, string numeAlbum, string denumire, int nrProduse, int pretBaza, int ID = genereazaIdUnicProdus()) : Produs(denumire, nrProduse, pretBaza, ID), tip(tip), casaDiscuri(casaDiscuri), dataVanzare(dataVanzare), trupa(trupa), numeAlbum(numeAlbum) {};

    Disc(const Disc &d) : Produs(d), tip(d.tip), casaDiscuri(d.casaDiscuri), dataVanzare(d.dataVanzare), trupa(d.trupa), numeAlbum(d.numeAlbum) {};
    ~Disc() {};

    void afisare() override;
    int getPretTotal() override;
    int getID() override;

    void modifTip(string);
    void modifCasaDiscuri(string);
    void modifDataVanzare(string);
    void modifTrupa(string);
    void modifNumeAlbum(string);

    Disc& operator=(const Disc& aux);



};