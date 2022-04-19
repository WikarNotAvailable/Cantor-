#include "Pieniadz.h"
using namespace std;
#ifndef WALUTA_H
#define WALUTA_H

/** Klasa dziedziczaca z pieniadza, bedaca jego dokladniejszym opisem, dziedzicza
* z niej klasy kryptowaluta oraz fizyczna waluta. */
class Waluta : public Pieniadz
{
    string m_kod; /** Zmienna opisujaca kod waluty. */
    double m_kurs; /** Zmienna opisujaca kurs waluty. */
public:

    /** Konstruktor wieloargumentowy klasy. */

    Waluta(string kod, double kurs, string nazwa, double ilosc);

    /** Destruktor klasy. */

    ~Waluta();

    /** Funkcja zwracajaca kurs waluty. */

    double zwrocKurs();
     
    /** Funkcja zwarcajaca kod waluty. */

    string zwrocKod();

    /** Funkcja wirutalna wypisujaca wszystkie zmienne klasy waluta (rowniez te odziedziczone). */

    virtual void wypiszDetale();
}; 
#endif
