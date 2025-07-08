#include <iostream>
#include <string>
#include <chrono>
#include "Disc.h"
#include "../utils.h"

#pragma once


using namespace std;

class DiscVintage : virtual public Disc{
protected:
    bool isMint = false;
    int raritate = 0;
public:
    DiscVintage() = default;
    DiscVintage(bool isMint, int raritate, string tip, string casaDiscuri, string dataVanzare, string trupa, string numeAlbum, string denumire, int nrProduse, int pretBaza, int ID = genereazaIdUnicProdus());
    DiscVintage(const DiscVintage &d) : Produs(d), Disc(d), isMint(d.isMint), raritate(d.raritate) {};
    ~DiscVintage() {};

    void afisare() override;
    int getPretTotal() override;
    int getID() override;
    
    void modifRaritate(int);
    void modifMint(bool);

    DiscVintage& operator=(const DiscVintage& aux); 


};
