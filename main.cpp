#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "produse/Produs.h"
#include "produse/ArticolVestimentar.h"
#include "angajati/Angajat.h"
#include "angajati/OperatorComenzi.h"
#include "produse/DiscVintage.h"
#include "produse/Disc.h"
#include "functions/functions.h"
#include "comenzi/ComandaInfo.h"

using namespace std;

int main(){

    
    cout << "Magazinul lucreaza cu un set de date preconfigurate, pe care le puteti edita si afisa conform cu functia angajatului al carui ID a fost folosit pentru autentificare." << endl;
    vector<Produs*> stoc;
    vector<Angajat*> angajati;
    vector<Comanda> comenzi;

    getStocMagazin(stoc);

    try{
        getAngajatiMagazin(angajati);
    }catch(const exception& e){
        cout << e.what() << endl;
    }

    try{
        citesteComenzi(comenzi, stoc);

    }catch(const exception& e){
        cout << e.what() << endl;
    }


    //verif stoc minim 2 produse
    if(!verifStoc(stoc)){
        cout << "Magazinul nu poate functiona cu stocul curent." << endl;
        return 0;
    }

    //verif nr angajati
    if(!verifAngajati(angajati)){
        cout << "Magazinul nu are destui angajati pentru a functiona." << endl;
        return 0;
    }

    vector<Angajat*> operatori;

    for (int i = 0; i < angajati.size(); i++) {
        if (angajati[i]->getTipAngajat().compare("OperatorComenzi") == 0) {
            operatori.push_back(angajati[i]);      
        }
    }

    afisareAngajati(angajati);

    int id;

    cout << "Introduceti ID-ul cu care doriti sa va autentificati:" << endl;
    cin >> id;

    string tipAngajat;
    bool idGasit = false;
    for(int i = 0; i < angajati.size(); i++){
        if(id == angajati[i]->getID()){
            tipAngajat = angajati[i]->getTipAngajat();
            idGasit = true;
        }
    }

    if(!idGasit){
        cout << "Acest ID nu este asociat unui angajat existent.";
        return 0;
    }

    if(tipAngajat.compare("Manager") == 0){
        int optiune = 1;
        
        cout << "V-ati autentificat pe contul de MANAGER." << endl;
        while(optiune != 0){
            cout << "1 - Adaugare angajat." << endl;
            cout << "2 - Stergere angajat." << endl;
            cout << "3 - Modificare nume angajat." << endl;
            cout << "4 - Afisare date angajat." << endl;
            cout << "5 - Afisarea tuturor angajatilor." << endl;
            cout << "6 - Adaugare produs." << endl;
            cout << "7 - Stergere produs." << endl;
            cout << "8 - Modificare date produs." << endl;
            cout << "9 - Afisare date produs." << endl;
            cout << "10 - Afisare toate produsele." << endl;
            cout << "11 - Angajatul cu cele mai multe comenzi procesate" << endl;
            cout << "12 - Primii 3 angajati cu cele mai valoroase comenzi, ordonati descrescator in functie de valoarea comenzii." << endl;
            cout << "13 - Top 3 angajati cu cel mai mare salariu in luna curenta." << endl; 
            cout << "Introduceti ce actiune vreti sa efectuati: (0 pt a opri)" << endl;
            cin >> optiune;
        
            if(optiune == 1){
                adaugareAngajat(angajati);
                afisareAngajati(angajati);
            }

            if(optiune == 2){
                cout << "Introduceti ID-ul angajatului pe care doriti sa il stergeti:" << endl;
                int idAngajat;
                cin >> idAngajat;

                stergereAngajat(angajati, idAngajat);
                if(!verifAngajati(angajati)){
                    cout << "Magazinul nu mai are destui angajati pentru a functiona." << endl;
                    return 0;
                }   
                
            }

            if(optiune == 3){
                cout << "Introduceti ID-ul angajatului pe care doriti sa il modificati:" << endl;
                int idAngajat;
                cin >> idAngajat;

                modificareAngajat(angajati, idAngajat);
            }

            if(optiune == 4){
                cout << "Introduceti ID-ul angajatului pe care doriti sa il afisati:" << endl;
                int idAngajat;
                cin >> idAngajat;

                afisareAngajat(angajati, idAngajat);
            }

            if(optiune == 5){
                afisareAngajati(angajati);
            }

            if(optiune == 6){
                adaugaProdus(stoc);
            }

            if(optiune == 7){
                cout << "Introduceti ID-ul produsului pe care doriti sa il stergeti:" << endl;
                int idProdus;
                cin >> idProdus;
                stergeProdus(stoc, idProdus);
            }

            if(optiune == 8){
                cout << "Introduceti ID-ul produsului pe care doriti sa il modificati:" << endl;
                int idProdus;
                cin >> idProdus;
                modificareProdus(stoc, idProdus);
            }

            if(optiune == 9){
                cout << "Introduceti ID-ul produsului pe care doriti sa il afisati:" << endl;
                int idProdus;
                cin >> idProdus;
                afisareProdus(stoc, idProdus);
            }

            if(optiune == 10){
                afisareStoc(stoc);
            }

            if(optiune == 11){
                asignareComenziMinutCurent(comenzi, operatori);
                angajatComenziMaxime(operatori);
            }

            if(optiune == 12){
                asignareComenziMinutCurent(comenzi, operatori);
                top3AngajatiCeleMaiValoroaseComenzi(operatori);
            }

            if(optiune == 13){
                asignareComenziMinutCurent(comenzi, operatori);
                top3AngajatiCelMaiMareSalariu(angajati);
            }
        }

    }else if(tipAngajat.compare("Asistent") == 0){

        cout << "V-ati autentificat pe contul de ASISTENT." << endl;
        asignareComenzi(comenzi, operatori);

    }else if(tipAngajat.compare("OperatorComenzi") == 0){
        cout << "V-ati autentificat pe contul de OPERATOR COMENZI." << endl;
        int optiune = 1;
        while(optiune != 0){
            cout << "1 - Stergere produs." << endl;
            cout << "2 - Modificare date produs." << endl;
            cout << "3 - Afisare date produs." << endl;
            cout << "4 - Afisare toate produsele." << endl;
            cout << "Introduceti ce actiune vreti sa efectuati: (0 pt a opri)" << endl;
            cin >> optiune;

            if(optiune == 1){
                cout << "Introduceti ID-ul produsului pe care doriti sa il stergeti:" << endl;
                int idProdus;
                cin >> idProdus;
                stergeProdus(stoc, idProdus);
            }

            if(optiune == 2){
                cout << "Introduceti ID-ul produsului pe care doriti sa il modificati:" << endl;
                int idProdus;
                cin >> idProdus;
                modificareProdus(stoc, idProdus);
            }

            if(optiune == 3){
                cout << "Introduceti ID-ul produsului pe care doriti sa il afisati:" << endl;
                int idProdus;
                cin >> idProdus;
                afisareProdus(stoc, idProdus);
            }

            if(optiune == 4){
                afisareStoc(stoc);
            }
        }


    }


    return 0;
}