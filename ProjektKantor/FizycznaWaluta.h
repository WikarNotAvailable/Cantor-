#include "Waluta.h"
using namespace std;
#ifndef FIZYCZNAWALUTA_H
#define FIZYCZNAWALUTA_H

/** Klasa FizycznaWaluta opisuje wlasnosci fizycznej waluty
* oraz dostarcza informacji o niej, dziedziczy z klasy Waluta. */

class FizycznaWaluta : public Waluta
{
    double m_kursSkupu; /** Zmienna przechowujaca kurs skupu. */
public:
    /** Konstruktor wieloargumentowy klasy. */

    FizycznaWaluta(string kod, double kurs, string nazwa, double ilosc, double kursSkupu); 

    /** Destruktor. */

    ~FizycznaWaluta(); 

    /** Zaprzyjaznienie z nadpisanym operatorem <<. */

    friend ostream& operator<< (ostream& out, FizycznaWaluta& fizyk); 

    /** Zwraca kurs sprzedazy(skupu). */

    double zwrocKursSprzedazy(); 

    /** Funkcja wirtualna wypisujaca wszystkie dane przechowywane przez klase. */

    virtual void wypiszDetale(); 
}; 
#endif
