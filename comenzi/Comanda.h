#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include "../utils.h"
#include "../produse/Produs.h"
#include "../produse/ArticolVestimentar.h"
#include "../produse/Disc.h"
#include "../produse/DiscVintage.h"
#include "ComandaInfo.h"

#pragma once

using namespace std;

class Comanda {
protected:
    vector<Produs*> produse;
    string data;
    string ora;
    int durataSolutionare;
    int ID;
public:
    Comanda() = default;
    Comanda(vector<ComandaInfo> info, string data, string ora, int durataSolutionare, int ID = genereazaIdUnicComanda());
    Comanda(const Comanda &c) : produse(c.produse), data(c.data), ora(c.ora), durataSolutionare(c.durataSolutionare), ID(c.ID) {};
    
    Comanda& operator=(const Comanda &c);

    int getValoareComanda();
    void afisare();
    int getID();
    bool isFinalizata();

};