#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;
#ifndef PIENIADZ_H
#define PIENIADZ_H

/** Klasa bazowa wykorzystana do dziedziczenia dla waluty i jej pochodnych. Klasa ta rowniez 
wykorzystana jest do opisu zawartosci portfela. */

class Pieniadz
{
    string m_nazwa; /** Zmienna przechowujaca nazwe pieniadza. */
    double m_iloscPieniadza; /** Zmienna przechowujaca ilosc danego pieniadza. */
public:
    /** Konstruktor wieloargumentowy. */

    Pieniadz(string nazwa, double ilosc);

    /** Destruktor. */

    ~Pieniadz();

    /** Funkcja zwracajaca nazwe pieniadza. */

    string zwrocNazwe();

    /** Funkcja zwracajaca ilosc pieniadza. */

    double zwrocIloscPieniadza();

    /** Funkcja wirtualna wypisujaca wszystkie informacje o danym obiekcie. */

    virtual void wypiszDetale();

    /** Przeciazenie operatora +=. */

    Pieniadz operator+=(double wartosc);

    /** Przeciazanie operatora -=. */

    Pieniadz operator-=(double wartosc);
}; 
#endif
