#include <iostream>
#include <ctime>
#include <string>
#include <cctype> 
#include <vector>
#include <chrono>
#pragma once

using namespace std;

int genereazaIdUnicProdus();
int genereazaIdUnicAngajat();
int genereazaIdUnicComanda();
bool isValidDate(int year, int month, int day);
bool validateCNP(string& cnp);
int *getDataCurenta();
int *getOraCurenta();