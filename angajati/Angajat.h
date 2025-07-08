#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include <tuple>
#include "../utils.h"
#include "../comenzi/Comanda.h"
#pragma once

using namespace std;

class Angajat {
protected:
    int ID = 0;
    string nume = "N/A";
    string prenume = "N/A";
    string CNP = "N/A";
    string dataAngajarii = "N/A";
    string tipAngajat = "N/A";
public:
    Angajat() = default;
    Angajat(string nume, string prenume, string CNP, string dataAngajarii, string tipAngajat, int ID = genereazaIdUnicAngajat());
    Angajat(const Angajat &a) : ID(a.ID), nume(a.nume), prenume(a.prenume), CNP(a.CNP),dataAngajarii(a.dataAngajarii), tipAngajat(a.tipAngajat) {}
    virtual ~Angajat() {};

    Angajat& operator=(const Angajat &a);

    virtual void afisare() const;
    virtual void afisareFisier(ostream &dev) const;
    void modifNume(string numeNou);
    int getZiAngajare() const;
    int getLunaAngajare() const;
    int getAnAngajare() const;
    int getAniVechime() const;
    virtual float getSalariu() const;
    string getNume();
    string getPrenume();

    string getTipAngajat();
    int getID();

    virtual int getNrComenzi(){ return 0;};
    virtual int getCostComandaCeaMaiMare(){ return 0;};
    virtual int getNrComenziTotale(){ return 0;};

    virtual void adaugaComanda(Comanda &c){ };
    virtual void eliminaComenzi(){};
    virtual void eliminaComenziFaraAfisare(){ };
};



