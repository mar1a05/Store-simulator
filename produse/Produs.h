#include <iostream>
#include <string>
#include <chrono>
#include "../utils.h"

#pragma once

using namespace std;

class Produs {
protected:
    string denumire = "N/A";
    int nrProduse = 0;
    int pretBaza = 0;
    int ID = 0;
public:
    Produs() = default;
    Produs(string denumire, int nrProduse, int pretBaza, int ID = genereazaIdUnicProdus());
    Produs(const Produs &p) : Produs(p.denumire, p.nrProduse, p.pretBaza, p.ID){};
    ~Produs(){};

    void modifNrProd(int);
    void modifPretBaza(int);
    void modifDenumire(string);
    virtual void afisare();
    virtual int getPretTotal();
    int getNrProduse();
    virtual int getID();
    
    int getPretBaza();
    string getDenumire();
    Produs& operator=(const Produs& aux);
};

