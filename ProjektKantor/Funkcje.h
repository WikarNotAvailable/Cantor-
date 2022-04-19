#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "Kantor.h"
#include "BazaDanych.h"
using namespace std;
#ifndef FUNKCJE_H
#define FUNKCJE_H

/** Funkcja odpowiadajaca za zalogowanie na konto. */

int logowanie(vector<shared_ptr<Uzytkownik>> Uzytkownicy);

/** Funkcja odpowiadajaca za rejestracje. */

void rejestracja(BazaDanych& baza);

/** Funkcja wypisujaca opcje programu. */

void wypiszMenu();

/** Funkcja sluzaca do wybrania waluty fizycznej, uzytkownik wpisuje nazwe oraz ilosc
* sprawdzana jest poprawnosc wprowadzonych danych. */

int wybierzWaluteFiz(string& nazwa, double& ilosc, BazaDanych& baza);

/** Funkcja sluzaca do wybrania kryptowaluty, uzytkownik wpisuje nazwe oraz ilosc
* sprawdzana jest poprawnosc wprowadzonych danych. */

int wybierzWaluteKryp(string& nazwa, double& ilosc, BazaDanych& baza);

/** Funkcja sluzaca do wybrania ilosci pieniedzy, uzytkownik ja wpisuje, sprawdzana
* jest poprawnosc wprowadzonych danych. */

double wybierzIlosc();
#endif
