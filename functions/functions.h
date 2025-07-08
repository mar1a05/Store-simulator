#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
//#include "produse/Produs.h"
#include "../produse/ArticolVestimentar.h"
#include "../produse/DiscVintage.h"
#include "../produse/Disc.h"
#include "../angajati/Angajat.h"
#include "../angajati/OperatorComenzi.h"
#include <fstream>
#include <thread>

using namespace std;

void getStocMagazin(vector<Produs*> &stoc);
void getAngajatiMagazin(vector<Angajat*> &angajati);
bool verifStoc(vector<Produs*> stoc);
bool verifAngajati(vector<Angajat*> angajati);
void adaugareAngajat(vector<Angajat*> &angajati);
void afisareAngajati(vector<Angajat*> angajati);
void stergereAngajat(vector<Angajat*> &angajati, int idDeSters);
void modificareAngajat(vector<Angajat*> &angajati, int idDeModificat);
void afisareAngajat(vector<Angajat*> &angajati, int idDeAfisat);
void afisareStoc(vector<Produs*> stoc);
void adaugaProdus(vector<Produs*> &stoc);
void stergeProdus(vector<Produs*> &stoc, int idDeSters);
void modificareProdus(vector<Produs*> &stoc, int idDeModificat);
void afisareProdus(vector<Produs*> stoc, int idDeAfisat);
void citesteComenzi(vector<Comanda>& comenzi, vector<Produs*> &stoc);
void asignareComenzi(vector<Comanda>& comenzi, vector<Angajat*>& operatori);
void asignareComenziMinutCurent(vector<Comanda>& comenzi, vector<Angajat*>& operatori);
void angajatComenziMaxime(vector<Angajat*> operatori);
void top3AngajatiCeleMaiValoroaseComenzi(vector<Angajat*> operatori);
void top3AngajatiCelMaiMareSalariu(vector<Angajat*> angajati);