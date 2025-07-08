#include "functions.h"


void getStocMagazin(vector<Produs*> &stoc){

    ifstream fisStoc("InfoMagazin/stoc.txt");
    if (!fisStoc.is_open()) {
        cout << "Eroare la deschiderea fisierului stoc.txt!" << endl;
        exit(1);
    }

    string linie;
        while (getline(fisStoc, linie)) {
            try{
                stringstream ss(linie);
                string tipObiect;
                ss >> tipObiect;

                if (tipObiect == "ArticolVestimentar") {
                    string culoare, marca, denumire;
                    int nrProduse, pretBaza;
                    ss >> culoare >> marca >> denumire >> nrProduse >> pretBaza;
                    stoc.push_back(new ArticolVestimentar(culoare, marca, denumire, nrProduse, pretBaza));
                } else if (tipObiect == "Disc") {
                    string tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire;
                    int nrProduse, pretBaza;
                    ss >> tip >> casaDiscuri >> dataVanzare >> trupa >> numeAlbum >> denumire >> nrProduse >> pretBaza;
                    stoc.push_back(new Disc(tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire, nrProduse, pretBaza));
                } else if (tipObiect == "DiscVintage") {
                    bool isMint;
                    int raritate;
                    string tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire;
                    int nrProduse, pretBaza;
                    ss >> isMint >> raritate >> tip >> casaDiscuri >> dataVanzare >> trupa >> numeAlbum >> denumire >> nrProduse >> pretBaza;
                    stoc.push_back(new DiscVintage(isMint, raritate, tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire, nrProduse, pretBaza));
                } else {
                    cout << "Tip de obiect necunoscut: " << tipObiect << endl;
                }
            }catch(const exception& e){
                cout << "Eroare la adaugarea produsului: " << linie << endl;
                cout << "Detalii: " << e.what() << endl;
            }
        }

}



void getAngajatiMagazin(vector<Angajat*> &angajati){
    ifstream fisAngajati("InfoMagazin/angajati.txt");
    if (!fisAngajati.is_open()) {
        cout << "Eroare la deschiderea fisierului angajati.txt!" << endl;
        exit(1);
    }

    string linie;
    while (getline(fisAngajati, linie)) {
        try{
            stringstream ss(linie);

            string nume, prenume, CNP, dataAngajarii, tipAngajat;

            ss >> nume >> prenume >> CNP >> dataAngajarii >> tipAngajat;

            if(tipAngajat.compare("OperatorComenzi") != 0){
                angajati.push_back(new Angajat(nume, prenume, CNP, dataAngajarii, tipAngajat));
            }else{
                angajati.push_back(new OperatorComenzi(nume, prenume, CNP, dataAngajarii, tipAngajat));
            }

        }catch(const exception& e){
            cout << "Eroare la adaugarea angajatului: " << linie << endl;
            cout << "Detalii: " << e.what() << endl;
        }
    }

}

bool verifStoc(vector<Produs*> stoc){

    int nrHaine = 0, nrDisc = 0, nrDiscVint = 0;

    for(int i = 0; i < stoc.size(); i++){
            
        if(typeid(*stoc[i]) == typeid(DiscVintage)){
            nrDiscVint += stoc[i]->getNrProduse();
        }
        if(typeid(*stoc[i]) == typeid(ArticolVestimentar)){
            nrHaine += stoc[i]->getNrProduse();
        }
        if(typeid(*stoc[i]) == typeid(Disc)){
            nrDisc += stoc[i]->getNrProduse();
        }
        
    }

    bool stocValid = true;

    if (nrHaine < 2) {
        cout << "In stoc nu exista macar 2 articole vestimentare." << endl;
        stocValid = false;
    }

    if (nrDiscVint < 2) {
        cout << "In stoc nu exista macar 2 discuri vintage." << endl;
        stocValid = false;
    }

    if (nrDisc < 2) {
        cout << "In stoc nu exista macar 2 discuri." << endl;
        stocValid = false;
    }

    return stocValid;
}

bool verifAngajati(vector<Angajat*> angajati){
    int nrManageri = 0, nrOp = 0, nrAsist = 0;

    for(int i = 0; i < angajati.size(); i++){
        if(angajati[i]->getTipAngajat().compare("Manager")  == 0){
            nrManageri++;
        }
        if(angajati[i]->getTipAngajat().compare("OperatorComenzi")  == 0){
            nrOp++;
        }
        if(angajati[i]->getTipAngajat().compare("Asistent")  == 0){
            nrAsist++;
        }
    }

    if(nrManageri < 1){
        cout << "Magazinul nu are manager." << endl;
        return false;
    }

    if(nrAsist < 1){
        cout << "Magazinul nu are un asistent." << endl;
        return false;
    }

    if(nrOp < 3){
        cout << "Magazinul are mai putin de 3 operatori de comenzi" << endl;
        return false;
    }

    return true;
}

void afisareAngajati(vector<Angajat*> angajati){
    for (int i = 0; i < angajati.size(); ++i) {
        cout << "Angajat #" << (i + 1) << ":" << endl;
        angajati[i]->afisare();
        cout << "------------------------" << endl;
    }
}

void adaugareAngajat(vector<Angajat*> &angajati){
    cout << "Ce tip de angajat doriti sa adaugati?" << endl;
    string tipAngajat;
    cin >> tipAngajat;
    if(tipAngajat.compare("Manager") == 0 || tipAngajat.compare("Asistent") == 0){
        string nume, prenume, CNP, dataAngajarii;
        cout << "Introduceti numele" << endl;
        cin >> nume;
        cout << "Introduceti prenumele" << endl;
        cin >> prenume;
        cout << "Introduceti CNP-ul" << endl;
        cin >> CNP;
        cout << "Introduceti data angajarii" << endl;     
        cin >> dataAngajarii;

        angajati.push_back(new Angajat(nume, prenume, CNP, dataAngajarii, tipAngajat));
    }else if(tipAngajat.compare("OperatorComenzi") == 0){
        string nume, prenume, CNP, dataAngajarii;
        cout << "Introduceti numele" << endl;
        cin >> nume;
        cout << "Introduceti prenumele" << endl;
        cin >> prenume;
        cout << "Introduceti CNP-ul" << endl;
        cin >> CNP;
        cout << "Introduceti data angajarii" << endl;     
        cin >> dataAngajarii;

        angajati.push_back(new OperatorComenzi(nume, prenume, CNP, dataAngajarii, tipAngajat));
    
    }else{
        cout << "Acest tip de angajat nu exista";
    }
}



void stergereAngajat(vector<Angajat*> &angajati, int idDeSters){

    for(int i = 0; i < angajati.size(); i++){
        if(angajati[i]->getID() == idDeSters){
            angajati.erase(angajati.begin() + i);
            return;
        }    
    }

    cout << "Angajatul nu a fost gasit";
    return;
}

void modificareAngajat(vector<Angajat*> &angajati, int idDeModificat){
    string nume;
    cout << "Introduceti noul nume al angajatului:" << endl;
    cin >> nume;

    for(int i = 0; i < angajati.size(); i++){
        if(angajati[i]->getID() == idDeModificat){
            angajati[i]->modifNume(nume);
            return;
        }    
    }

    cout << "Angajatul nu a fost gasit";
    return;
}

void afisareAngajat(vector<Angajat*> &angajati, int idDeAfisat){
    for(int i = 0; i < angajati.size(); i++){
        if(angajati[i]->getID() == idDeAfisat){
            angajati[i]->afisare();
            return;
        }    
    }

    cout << "Angajatul nu a fost gasit";
    return;
}

void afisareStoc(vector<Produs*> stoc){
    for (int i = 0; i < stoc.size(); i++) {
        cout << "Produs #" << (i + 1) << ":" << endl;
        stoc[i]->afisare();
        cout << "------------------------" << endl;
    }
}

void adaugaProdus(vector<Produs*> &stoc){
    cout << "Ce tip de produs doriti sa introduceti?" << endl;
    string tipObiect;
    cin >> tipObiect;

    if (tipObiect == "ArticolVestimentar") {
        string culoare, marca, denumire;
        int nrProduse, pretBaza;
        cout << "Introduceti culoarea: " << endl;
        cin >> culoare;

        cout << "Introduceti marca: " << endl;
        cin >> marca;

        cout << "Introduceti denumirea: " << endl;
        cin.ignore();
        getline(cin, denumire);

        cout << "Introduceti numarul de produse: " << endl;
        cin >> nrProduse;

        cout << "Introduceti pretul de baza: " << endl;
        cin >> pretBaza;

        stoc.push_back(new ArticolVestimentar(culoare, marca, denumire, nrProduse, pretBaza));

    } else if (tipObiect == "Disc") {
        string tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire;
        int nrProduse, pretBaza;
        cout << "Introduceti tipul: " << endl;
        cin >> tip;

        cout << "Introduceti casa de discuri: " << endl;
        cin >> casaDiscuri;

        cout << "Introduceti data cand au fost puse in vanzare: " << endl;
        cin >> dataVanzare;

        cout << "Introduceti trupa: " << endl;
        cin >> trupa;

        cout << "Introduceti numele albumului: " << endl;
        cin >> numeAlbum;

        cout << "Introduceti denumirea: " << endl;
        cin.ignore();
        getline(cin, denumire);

        cout << "Introduceti numarul de produse: " << endl;
        cin >> nrProduse;

        cout << "Introduceti pretul de baza: " << endl;
        cin >> pretBaza;

        stoc.push_back(new Disc(tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire, nrProduse, pretBaza));
    } else if (tipObiect == "DiscVintage") {
        bool isMint;
        int raritate;
        string mint;
        string tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire;
        int nrProduse, pretBaza;

        cout << "Introduceti tipul: " << endl;
        cin >> tip;

        cout << "Introduceti casa de discuri: " << endl;
        cin >> casaDiscuri;

        cout << "Introduceti data cand au fost puse in vanzare: " << endl;
        cin >> dataVanzare;

        cout << "Introduceti trupa: " << endl;
        cin >> trupa;

        cout << "Introduceti numele albumului: " << endl;
        cin >> numeAlbum;

        cout << "Introduceti denumirea: " << endl;
        cin.ignore();
        getline(cin, denumire);

        cout << "Este mint sau nu? (da/nu)" << endl;
        cin >> mint;

        while(mint.compare("da") != 0 || mint.compare("nu") != 0){
            cout << "Aceast camp este obligatoriu." << endl;
            cout << "Este mint sau nu? (da/nu)" << endl;
            cin >> mint;
        }

        if(mint.compare("da") == 0){
            isMint = true;
        }
        
        if(mint.compare("nu") == 0){
            isMint = false;
        }

        cout << "Introduceti raritatea (1-5):" << endl;
        cin >> raritate;

        while(raritate < 1 || raritate > 5){
            cout << "Aceast camp este obligatoriu." << endl;
            cout << "Introduceti raritatea (1-5):" << endl;
            cin >> raritate;
        }

        cout << "Introduceti numarul de produse: " << endl;
        cin >> nrProduse;

        cout << "Introduceti pretul de baza: " << endl;
        cin >> pretBaza;

        stoc.push_back(new DiscVintage(isMint, raritate, tip, casaDiscuri, dataVanzare, trupa, numeAlbum, denumire, nrProduse, pretBaza));
    } else {
        cout << "Tip de obiect necunoscut: " << tipObiect << endl;
    }
}


void stergeProdus(vector<Produs*> &stoc, int idDeSters){
    for (int i = 0; i < stoc.size(); i++) {
        if(idDeSters == stoc[i]->getID()){
            stoc.erase(stoc.begin() + i);
            return;
        }
    }

    cout << "Acest ID nu este asociat niciunui produs din stoc" << endl;
}

void modificareProdus(vector<Produs*> &stoc, int idDeModificat){

    cout << endl << idDeModificat << endl;
    bool gasit = false;
    for (int i = 0; i < stoc.size(); i++) {
        if(idDeModificat == stoc[i]->getID()){
            gasit = true;
            bool terminat = false;

            while(!terminat){
                cout << "Ce atribut doresti sa modifici?" << endl;

                if(typeid(*stoc[i]) == typeid(ArticolVestimentar)){
                    cout << "1. Culoare\n2. Marca\n3. Denumire\n4. Nr Produse\n5. Pret Baza\n6. Terminare\nAlege o optiune: " << endl;
                    int optiune;
                    cin >> optiune;
                    switch (optiune) {
                        case 1: {
                            string culoareNoua;
                            cout << "Introduceti culoarea noua: ";
                            cin >> culoareNoua;
                            dynamic_cast<ArticolVestimentar*>(stoc[i])->modifCuloare(culoareNoua);
                            break;
                        }
                        case 2: {
                            string marcaNoua;
                            cout << "Introduceti marca noua: ";
                            cin >> marcaNoua;
                            dynamic_cast<ArticolVestimentar*>(stoc[i])->modifMarca(marcaNoua);
                            break;
                        }
                        case 3: {
                            string denumireNoua;
                            cout << "Introduceti denumirea noua: ";
                            cin.ignore();
                            getline(cin, denumireNoua);
                            dynamic_cast<ArticolVestimentar*>(stoc[i])->modifDenumire(denumireNoua);
                            break;
                        }
                        case 4: {
                            int nrProduseNou;
                            cout << "Introduceti numarul de produse nou: ";
                            cin >> nrProduseNou;
                            dynamic_cast<ArticolVestimentar*>(stoc[i])->modifNrProd(nrProduseNou);
                            break;
                        }
                        case 5: {
                            int pretNou;
                            cout << "Introduceti pretul de baza nou: ";
                            cin >> pretNou;
                            dynamic_cast<ArticolVestimentar*>(stoc[i])->modifPretBaza(pretNou);
                            break;
                        }
                        case 6:
                            terminat = true;
                            break;
                        default:
                            cout << "Optiune invalida. Reincearca." << endl;
                    }
                }else if(typeid(*stoc[i]) == typeid(Disc)){
                    cout << "1. Tip\n2. Casa Discuri\n3. Data Vanzare\n4. Trupa\n5. Nume Album\n6. Nr Produse\n7. Pret Baza\n8. Terminare\nAlege o optiune: " << endl;
                    int optiune;
                    cin >> optiune;
                    switch (optiune) {
                        case 1: {
                            string tipNou;
                            cout << "Introduceti tipul nou: ";
                            cin >> tipNou;
                            dynamic_cast<Disc*>(stoc[i])->modifTip(tipNou);
                            break;
                        }
                        case 2: {
                            string casaNoua;
                            cout << "Introduceti casa discuri noua: ";
                            cin >> casaNoua;
                            dynamic_cast<Disc*>(stoc[i])->modifCasaDiscuri(casaNoua);
                            break;
                        }
                        case 3: {
                            string dataNoua;
                            cout << "Introduceti data noua: ";
                            cin >> dataNoua;
                            dynamic_cast<Disc*>(stoc[i])->modifDataVanzare(dataNoua);
                            break;
                        }
                        case 4: {
                            string trupaNoua;
                            cout << "Introduceti trupa noua: ";
                            cin >> trupaNoua;
                            dynamic_cast<Disc*>(stoc[i])->modifTrupa(trupaNoua);
                            break;
                        }
                        case 5: {
                            string numeNou;
                            cout << "Introduceti numele albumului nou: ";
                            cin.ignore();
                            getline(cin, numeNou);
                            dynamic_cast<Disc*>(stoc[i])->modifNumeAlbum(numeNou);
                            break;
                        }
                        case 6: {
                            int nrProduseNou;
                            cout << "Introduceti numarul de produse nou: ";
                            cin >> nrProduseNou;
                            dynamic_cast<Disc*>(stoc[i])->modifNrProd(nrProduseNou);
                            break;
                        }
                        case 7: {
                            int pretNou;
                            cout << "Introduceti pretul de baza nou: ";
                            cin >> pretNou;
                            dynamic_cast<Disc*>(stoc[i])->modifPretBaza(pretNou);
                            break;
                        }
                        case 8:
                            terminat = true;
                            break;
                        default:
                            cout << "Optiune invalida. Reincearca." << endl;
                    }
                }else if(typeid(*stoc[i]) == typeid(DiscVintage)){
                    cout << "1. Is Mint\n2. Raritate\n3. Tip\n4. Casa discuri\n5. Data vanzarii\n6. Trupa\n7. Nume album\n8. Numar produse\n9. Pret baza\n10. Terminare\nAlege o optiune: " << endl;
                    int optiune;
                    cin >> optiune;

                    switch (optiune) {
                        case 1: {
                            bool isMintNou;
                            cout << "Produsul este mint (0 = Nu, 1 = Da): ";
                            cin >> isMintNou;
                            dynamic_cast<DiscVintage*>(stoc[i])->modifMint(isMintNou);
                            break;
                        }
                        case 2: {
                            int raritateNoua;
                            cout << "Introduceti raritatea noua: ";
                            cin >> raritateNoua;
                            dynamic_cast<DiscVintage*>(stoc[i])->modifRaritate(raritateNoua);
                            break;
                        }
                        case 3: {
                            string tipNou;
                            cout << "Introduceti tipul nou: ";
                            cin >> tipNou;
                            dynamic_cast<DiscVintage*>(stoc[i])->modifTip(tipNou);
                            break;
                        }
                        case 4: {
                            string casaNoua;
                            cout << "Introduceti casa discuri noua: ";
                            cin >> casaNoua;
                            dynamic_cast<DiscVintage*>(stoc[i])->modifCasaDiscuri(casaNoua);
                            break;
                        }
                        case 5: {
                            string dataNoua;
                            cout << "Introduceti data noua (format DD-MM-YYYY): ";
                            cin >> dataNoua;
                            dynamic_cast<DiscVintage*>(stoc[i])->modifDataVanzare(dataNoua);
                            break;
                        }
                        case 6: {
                            string trupaNoua;
                            cout << "Introduceti trupa noua: ";
                            cin.ignore();
                            getline(cin, trupaNoua);
                            dynamic_cast<DiscVintage*>(stoc[i])->modifTrupa(trupaNoua);
                            break;
                        }
                        case 7: {
                            string numeNou;
                            cout << "Introduceti numele albumului nou: ";
                            cin.ignore();
                            getline(cin, numeNou);
                            dynamic_cast<DiscVintage*>(stoc[i])->modifNumeAlbum(numeNou);
                            break;
                        }
                        case 8: {
                            int nrProduseNou;
                            cout << "Introduceti numarul de produse nou: ";
                            cin >> nrProduseNou;
                            dynamic_cast<DiscVintage*>(stoc[i])->modifNrProd(nrProduseNou);
                            break;
                        }
                        case 9: {
                            int pretNou;
                            cout << "Introduceti pretul de baza nou: ";
                            cin >> pretNou;
                            dynamic_cast<DiscVintage*>(stoc[i])->modifPretBaza(pretNou);
                            break;
                        }
                        case 10:
                            cout << "Terminare modificari pentru DiscVintage." << endl;
                            terminat = true;
                            break;
                        default:
                            cout << "Optiune invalida. Reincearca." << endl;
                    }
                }
            }

            return;
        }
    }

    if(!gasit){
        cout << "ID-ul introdus nu exista in stoc." << endl;
        return;
    }
}


void afisareProdus(vector<Produs*> stoc, int idDeAfisat){
    bool gasit = false;
    for (int i = 0; i < stoc.size(); i++) {
        if(idDeAfisat == stoc[i]->getID()){
            stoc[i]->afisare();
            gasit = true;
            return;
        }
    }

    if(!gasit){
        cout << "ID-ul introdus nu exista in stoc." << endl;
    }
}

void citesteComenzi(vector<Comanda>& comenzi, vector<Produs*>& stoc) {
    ifstream fisComenzi("InfoMagazin/comenzi.txt");
    if (!fisComenzi.is_open()) {
        cout << "Eroare la deschiderea fișierului comenzi.txt!" << endl;
        exit(1);
    }

    string linie;
    while (getline(fisComenzi, linie)) {
        try {
            stringstream ss(linie);

            string data, ora;
            int durataSolutionare;
            ss >> data >> ora >> durataSolutionare;

            vector<ComandaInfo> produse;
            string denumireProdus;
            int nrProduse;

            while (ss >> denumireProdus >> nrProduse) {
                produse.push_back({denumireProdus, nrProduse});
            }

            bool comandaValida = true;
            for (int i = 0; i < produse.size(); i++) {
                bool produsGasit = false;
                for (int j = 0; j < stoc.size(); j++) {
                    if (produse[i].denumire == stoc[j]->getDenumire()) {
                        produsGasit = true;
                        if (stoc[j]->getNrProduse() < produse[i].nrProduse) {
                            throw invalid_argument("Nu sunt destule produse in stoc pentru produsul " + produse[i].denumire);
                        }
                    }
                }
                if (!produsGasit) {
                    throw invalid_argument("Produsul " + produse[i].denumire + " nu exista in stoc");
                }
            }

            for (int i = 0; i < produse.size(); i++) {
                for (int j = 0; j < stoc.size(); j++) {
                    if (produse[i].denumire == stoc[j]->getDenumire()) {
                        int stocModificat = stoc[j]->getNrProduse() - produse[i].nrProduse;
                        stoc[j]->modifNrProd(stocModificat);
                        break;
                    }
                }
            }

            comenzi.push_back(Comanda(produse, data, ora, durataSolutionare));
        } catch (const exception& e) {
            cout << "Eroare la procesarea comenzii: " << linie << endl;
            cout << "Detalii: " << e.what() << endl;
        }
    }

    fisComenzi.close();
}


void asignareComenzi(vector<Comanda> &comenzi, vector<Angajat*>& operatori) {
    
    int j = 0;
    bool operatoriiMaiAuComenzi = true;

    while (!comenzi.empty() || operatoriiMaiAuComenzi) {

        for(int k = 0; k < operatori.size(); k++){
            operatori[k]->eliminaComenzi();
        }

        int comenziInitiale = comenzi.size();
        for (int i = 0; i < comenziInitiale; ++i) {
            if (operatori[j]->getNrComenzi() < 3) {
                operatori[j]->adaugaComanda(comenzi.front());
                cout << "Comanda " << comenzi.front().getID() << " a fost asignata operatorului " << operatori[j]->getID() << endl;
                comenzi.erase(comenzi.begin());
            }

            j = (j + 1) % operatori.size();
        }


        cout << "Asteptare..." << endl << endl;
        this_thread::sleep_for(std::chrono::minutes(1));

        operatoriiMaiAuComenzi = false;
        for(int k = 0; k < operatori.size(); k++){
            if (operatori[k]->getNrComenzi() > 0) {
                operatoriiMaiAuComenzi = true;
                break;
            }
        }
    }

    cout << "Toate comenzile au fost procesate!" << endl;
}

void asignareComenziMinutCurent(vector<Comanda> &comenzi, vector<Angajat*>& operatori) {
    
    for (int k = 0; k < operatori.size(); k++) {
        operatori[k]->eliminaComenziFaraAfisare
        ();
    }

    int j = 0;
    int comenziInitiale = comenzi.size();

    for (int i = 0; i < comenziInitiale; i++) {
        if (operatori[j]->getNrComenzi() < 3) {
            operatori[j]->adaugaComanda(comenzi.front());
            comenzi.erase(comenzi.begin());
        }

        j = (j + 1) % operatori.size();
    }
}

void angajatComenziMaxime(vector <Angajat*> operatori){
    int *nrComenziOperatori = new int[operatori.size()];
    int nrComenziMax = 0;
    for(int i = 0; i < operatori.size(); i++){
        nrComenziOperatori[i] = operatori[i]->getNrComenziTotale();
        if(nrComenziMax < operatori[i]->getNrComenziTotale()){
            nrComenziMax = operatori[i]->getNrComenziTotale();
        }
    }

    // cout << "Angajatul/angajatii cu cele mai multe comenzi procesate este: " << endl;
    // for(int i = 0; i < operatori.size(); i++){
    //     if(nrComenziOperatori[i] == nrComenziMax){
    //         operatori[i]->afisare();
    //     }
    // }

    ofstream f("angajatiComenziMaxime.csv");
    f << "ID, Tip  Angajat, Nume, Prenume, CNP, Data angajarii, Salariu" << "\n";

    for(int i = 0; i < operatori.size(); i++){
        if(nrComenziOperatori[i] == nrComenziMax){
            operatori[i]->afisareFisier(f);
        }
    }
}

void top3AngajatiCeleMaiValoroaseComenzi(vector <Angajat*> operatori){
    for (int i = 0; i < operatori.size() - 1; i++) {
        for (int j = 0; j < operatori.size() - i - 1; ++j) {
            if (operatori[j]->getCostComandaCeaMaiMare() < operatori[j + 1]->getCostComandaCeaMaiMare()) {
                swap(operatori[j], operatori[j+1]);
            }
        }
    }

    // for(int i = 0; i < 3; i++){
    //     operatori[i]->afisare();
    // }

    ofstream f("top3AngajatiCeleMaiValoroaseComenzi.csv");
    f << "ID, Tip  Angajat, Nume, Prenume, CNP, Data angajarii, Salariu" << "\n";

    for(int i = 0; i < 3; i++){
        operatori[i]->afisareFisier(f);
    }
}

void top3AngajatiCelMaiMareSalariu(vector<Angajat*> angajati){
    for (int i = 0; i < angajati.size() - 1; ++i) {
        for (int j = 0; j < angajati.size() - i - 1; ++j) {
            if (angajati[j]->getSalariu() < angajati[j + 1]->getSalariu()) {
                swap(angajati[j], angajati[j + 1]);
            }
        }
    }

    cout << "Doriti sa afisati angajatii ordonati alfabetic dupa nume sau prenume? (1 - nume / 2 - prenume): " << endl;
    int optiune2;
    cin >> optiune2;
    if(optiune2 == 1){
        for (int i = 0; i < 3 - 1; ++i){
            for (int j = 0; j < 3 - i - 1; ++j) {
                if (angajati[j]->getNume() > angajati[j + 1]->getNume()) {
                    swap(angajati[j], angajati[j + 1]);
                }
            }
        }
    }else if(optiune2 == 2){
        for (int i = 0; i < 3 - 1; ++i){
            for (int j = 0; j < 3 - i - 1; ++j) {
                if (angajati[j]->getPrenume() > angajati[j + 1]->getPrenume()) {
                    swap(angajati[j], angajati[j + 1]);
                }
            }
        }
    }else{
        cout << "Aceasta optiune nu exista" << endl;
    }

    // for(int i = 0; i < 3; i++){
    //     angajati[i]->afisare();
    // }

    ofstream f("top3AngajatiCelMaiMareSalariu.csv");
    f << "ID, Tip  Angajat, Nume, Prenume, CNP, Data angajarii, Salariu" << "\n";

    for(int i = 0; i < 3; i++){
        angajati[i]->afisareFisier(f);
    }

}
