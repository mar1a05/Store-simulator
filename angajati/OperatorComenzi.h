#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include "../utils.h"
#include "../comenzi/Comanda.h"
#include "Angajat.h"
#pragma once

using namespace std;

class OperatorComenzi : public Angajat {
protected:
    int nrComenzi = 0;
    vector<Comanda> comenzi;
    int costComandaCeaMaiMare = 0;
    int costTotalComenzi = 0;
public:
    OperatorComenzi() = default;
    OperatorComenzi(string nume, string prenume, string CNP, string dataAngajarii, string tipAngajat, int ID = genereazaIdUnicAngajat()) : Angajat(nume, prenume, CNP, dataAngajarii, tipAngajat, ID) {};
    OperatorComenzi(const OperatorComenzi &a) : Angajat(a), nrComenzi(a.nrComenzi), comenzi(a.comenzi), costComandaCeaMaiMare(a.costComandaCeaMaiMare), costTotalComenzi(a.costTotalComenzi) {}
    ~OperatorComenzi() {};

    OperatorComenzi& operator=(const OperatorComenzi &a);

    int getNrComenzi() override;
    int getCostComandaCeaMaiMare() override;
    int getNrComenziTotale() override;

    void adaugaComanda(Comanda &c) override;
    void eliminaComenzi() override;
    void eliminaComenziFaraAfisare() override;

    virtual void afisare() const override;
    virtual float getSalariu() const override;
};