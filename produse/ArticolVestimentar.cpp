#include "ArticolVestimentar.h"

void ArticolVestimentar :: afisare(){
    Produs::afisare();
    cout << "culoare: " << culoare << endl;
    cout << "marca: " << marca << endl;
}

int ArticolVestimentar :: getPretTotal(){
    return pretBaza + 20;
}

int ArticolVestimentar :: getID(){
    return ID;
}

ArticolVestimentar& ArticolVestimentar::operator=(const ArticolVestimentar& aux) {
    if (this != &aux) {
        Produs::operator=(aux);
        culoare = aux.culoare;
        marca = aux.marca;
    }
    return *this;
}

void ArticolVestimentar :: modifCuloare(string culoareNoua){
    culoare = culoareNoua;
}
void ArticolVestimentar :: modifMarca(string marcaNoua){
    marca = marcaNoua;
}