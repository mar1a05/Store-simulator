#include <iostream>
#include <string>
#include <chrono>
#include "Produs.h"
#include "../utils.h"
#pragma once
using namespace std;

class ArticolVestimentar : virtual public Produs{
protected:
    string culoare = "N/A";
    string marca = "N/A";
public:
    ArticolVestimentar() = default;
    ArticolVestimentar(string culoare, string marca, string denumire, int nrProduse, int pretBaza, int ID = genereazaIdUnicProdus()) : Produs(denumire, nrProduse, pretBaza, ID), culoare(culoare), marca(marca) {};
    ArticolVestimentar(const ArticolVestimentar &av) : Produs(av), culoare(av.culoare), marca(av.marca) {};
    ~ArticolVestimentar(){};

    void afisare() override;
    int getPretTotal() override;
    int getID() override;

    void modifCuloare(string);
    void modifMarca(string);

    ArticolVestimentar& operator=(const ArticolVestimentar& aux);


};