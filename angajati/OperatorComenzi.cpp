#include "OperatorComenzi.h"

void OperatorComenzi :: afisare() const{
    Angajat::afisare();
    cout << "Nr comenzi totale: " << nrComenzi << endl;
    cout << "Cost comanda cea mai mare: " << costComandaCeaMaiMare << endl;
    cout << "Cost total comenzi: " << costTotalComenzi << endl;
}

int OperatorComenzi :: getNrComenzi(){
    return comenzi.size();
}

void OperatorComenzi :: adaugaComanda(Comanda &c){
    comenzi.push_back(c);
    nrComenzi++;
    if(costComandaCeaMaiMare < c.getValoareComanda()){
        costComandaCeaMaiMare = c.getValoareComanda();
    }

    costTotalComenzi += c.getValoareComanda();

}
void OperatorComenzi::eliminaComenzi() {
    for (int i = 0; i < comenzi.size(); ) {
        if (comenzi[i].isFinalizata()) {
            cout << "Comanda " << comenzi[i].getID() << " finalizata de operatorul " << this->getID() << endl;
            comenzi.erase(comenzi.begin() + i);
        } else {
            i++;
        }
    }

}
void OperatorComenzi::eliminaComenziFaraAfisare() {
    for (int i = 0; i < comenzi.size(); ) {
        if (comenzi[i].isFinalizata()) {
            comenzi.erase(comenzi.begin() + i);
        } else {
            i++;
        }
    }

}

int OperatorComenzi :: getCostComandaCeaMaiMare(){
    return costComandaCeaMaiMare;
}

int OperatorComenzi :: getNrComenziTotale(){
    return nrComenzi;
}


OperatorComenzi& OperatorComenzi :: operator=(const OperatorComenzi &a) {
    if (this != &a) {
        Angajat::operator=(a);
        nrComenzi = a.nrComenzi;
        comenzi = a.comenzi;
        costTotalComenzi = a.costTotalComenzi;
        costComandaCeaMaiMare = a.costComandaCeaMaiMare;
    }
    return *this;
}

float OperatorComenzi ::  getSalariu() const{
    int aniVechime = this->getAniVechime();
    float salariu = 3500 + 100 * aniVechime;

    int lunaNastere = (CNP[3] - '0') * 10 + (CNP[4] - '0');
    int *data = getDataCurenta();
    bool isZiNastere = false;
    if(lunaNastere == data[1])
        isZiNastere = true;

    if(this->tipAngajat.compare("OperatorComenzi") == 0){
        salariu += 0.5 / 100 * costTotalComenzi;
    }

    if(isZiNastere && this->tipAngajat.compare("Manager") != 0)
        salariu += 100;

    return salariu;
}

