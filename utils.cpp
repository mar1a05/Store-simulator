#include "utils.h"

int genereazaIdUnicProdus() {
    static int counter = 0;
    time_t now = time(nullptr);
    int id = static_cast<int>((now % 1000) * 100 + counter);
    ++counter;
    return id;
}

int genereazaIdUnicAngajat(){
    static int counter = 0;
    time_t now = time(nullptr);
    int id = static_cast<int>((now % 100) * 10 + counter);
    ++counter;
    return id;
}

int genereazaIdUnicComanda(){
    static int counter = 0;
    time_t now = time(nullptr);
    int id = static_cast<int>((now % 1000) + counter);
    ++counter;
    return id;
}

bool isValidDate(int year, int month, int day) {
    if (month < 1 || month > 12) 
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    return day >= 1 && day <= daysInMonth[month - 1];
}

bool validateCNP(string& cnp) {
    if (cnp.length() != 13) {
        throw invalid_argument("CNP-ul trebuie sa aiba 13 caractere");
    }

    for (int i = 0; i < cnp.length(); i++) {
        if (!isdigit(cnp[i])) {
            throw invalid_argument("CNP-ul trebuie sa contina doar cifre");
        }
    }

    int sex = cnp[0] - '0';
    if (sex < 1 || sex > 8) {
        throw invalid_argument("Prima cifra invalida");
    }

    int anNastere = (cnp[1] - '0') * 10 + (cnp[2] - '0');
    int lunaNastere = (cnp[3] - '0') * 10 + (cnp[4] - '0');
    int ziNastere = (cnp[5] - '0') * 10 + (cnp[6] - '0');

    if (sex == 1 || sex == 2) 
        anNastere += 1900;
    else if (sex == 3 || sex == 4) 
        anNastere += 1800;
    else if (sex == 5 || sex == 6) 
        anNastere += 2000;

    if (!isValidDate(anNastere, lunaNastere, ziNastere)) {
        throw invalid_argument("Data nasterii invalida");
    }

    int *data = getDataCurenta();
    int varsta = data[2] - anNastere;

    if (data[1] < lunaNastere || (data[1] == lunaNastere && data[0] < ziNastere)) {
        varsta--;
    }

    if(varsta < 18){
        throw invalid_argument("Angajatul nu este major");
    }

    return true;
}

int *getDataCurenta(){
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);
	int day = datetime.tm_mday;
	int year = datetime.tm_year + 1900;
	int month = datetime.tm_mon + 1;

    int *data = new int[3];
    data[0] = day;
    data[1] = month;
    data[2] = year;

    return data;
}

int* getOraCurenta() {
    time_t timestamp = time(nullptr);
    struct tm datetime = *localtime(&timestamp);

    int* ceas = new int[2];
    ceas[0] = datetime.tm_hour;
    ceas[1] = datetime.tm_min;

    return ceas;
}


