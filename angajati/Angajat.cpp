#include "Angajat.h"

Angajat :: Angajat(string nume, string prenume, string CNP, string dataAngajarii, string tipAngajat, int ID) : dataAngajarii(dataAngajarii), tipAngajat(tipAngajat), ID(ID){
    
    if(validateCNP(CNP))
        this->CNP = CNP;

    if(nume.length() < 3 || nume.length() > 30){
        throw invalid_argument("Numele nu are intre 3 si 30 de caractere.");
    }

    this->nume = nume;

    if(prenume.length() < 3 || prenume.length() > 30){
        throw invalid_argument("Numele nu are intre 3 si 30 de caractere.");
    }

    this->prenume = prenume;

}

Angajat& Angajat :: operator=(const Angajat &a) {
    if (this != &a) {
        ID = a.ID;
        nume = a.nume;
        prenume = a.prenume;
        CNP = a.CNP;
        dataAngajarii = a.dataAngajarii;
        tipAngajat = a.tipAngajat;
    }
    return *this;
}

void Angajat :: modifNume(string numeNou){
    nume = numeNou;
}

int Angajat :: getZiAngajare() const{
    return (dataAngajarii[0] - '0') * 10 + dataAngajarii[1] - '0';
}

int Angajat :: getLunaAngajare() const{
    return (dataAngajarii[3] - '0') * 10 + dataAngajarii[4] - '0';
}

int Angajat :: getAnAngajare() const{
    return (dataAngajarii[6] - '0') * 1000 + (dataAngajarii[7] - '0') * 100 + (dataAngajarii[8] - '0') * 10 + dataAngajarii[9] - '0';
}

string Angajat :: getTipAngajat(){
    return tipAngajat;
}

int Angajat :: getID() {
    return ID;
}

int Angajat :: getAniVechime() const{
    int zi, luna, an;
    int *data = getDataCurenta();
    zi = data[0];
    luna = data[1];
    an = data[2];

    int ziAngajare = this->getZiAngajare();
    int lunaAngajare = this->getLunaAngajare();
    int anAngajare = this->getAnAngajare();

    int maxAni = an - anAngajare;

    if(luna < lunaAngajare)
        maxAni -= 1;

    if(luna == lunaAngajare)
        if(zi < ziAngajare)
            maxAni -= 1;

    return maxAni;
}

float Angajat :: getSalariu() const{
    int aniVechime = this->getAniVechime();
    float salariu = 3500 + 100 * aniVechime;

    int lunaNastere = (CNP[3] - '0') * 10 + (CNP[4] - '0');
    int *data = getDataCurenta();
    bool isZiNastere = false;
    if(lunaNastere == data[1])
        isZiNastere = true;

    if(this->tipAngajat.compare("Manager") == 0){
        salariu += 1.25 * salariu;
    }

    if(this->tipAngajat.compare("Asistent") == 0){
        salariu += salariu * 0.75;
    }

    if(isZiNastere && this->tipAngajat.compare("Manager") != 0)
        salariu += 100;

    return salariu;
}

void Angajat :: afisare() const{
    
    cout << "ID-ul este: " << ID << endl;
    cout << "Functia angajatului este: " << tipAngajat << endl;
    cout << "Numele este: " << nume << endl;
    cout << "Prenumele este: " << prenume << endl;
    cout << "CNP-ul este: " << CNP << endl;
    cout << "Data angajarii este: " << dataAngajarii << endl;
    cout << "Salariu: " << this->getSalariu() << endl;

    
}

void Angajat :: afisareFisier(ostream &dev) const{

    dev << ID << ", ";
    dev << tipAngajat << ", ";
    dev << nume << ", ";
    dev << prenume << ", ";
    dev << CNP << ", ";
    dev << dataAngajarii << ", ";
    dev << this->getSalariu() << "\n";
}

string Angajat :: getNume(){
    return nume;
}

string Angajat :: getPrenume(){
    return prenume;
}

