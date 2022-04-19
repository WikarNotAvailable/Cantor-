#include "Waluta.h"
using namespace std;
#ifndef KRYPTOWALUTA_H
#define KRYPTOWALUTA_H

/**  Klasa KryptoWaluta opisuje wlasnosci kryptowaluty
* oraz dostarcza informacji o niej, dziedziczy z klasy Waluta. */

class KryptoWaluta : public Waluta
{
    double m_fluktuacja; /** Zmienna przechowujaca fluktuacje. */
    double m_cenaBid; /** Zmienna przechowujaca ceneBid. */
    double m_cenaAsk; /** Zmienna przechowujaca ceneAsk. */
public:

    /** Konstruktor wieloargumentowy klasy. */

    KryptoWaluta(string kod, double kurs, string nazwa, double fluktuacja, double cenaBid, double cenaAsk, double ilosc = 0);

    /** Destruktor klasy. */

    ~KryptoWaluta();

    /** Przeciazenie operatora << (deklaracja, definicja poza klasa) dla klasy KryptoWaluta. */

    friend ostream& operator<< (ostream& out, KryptoWaluta& krypto);

    /** Funkcja zwracajaca fluktuacje. */

    double zwrocFluktuacje();

    /** Funkcja zwracajaca ceneBid. */

    double zwrocCeneBid();

    /** Funkcja zwracajaca ceneAsk. */

    double zwrocCeneAsk();

    /** Wirtualna funkcja wypisujaca wszystkie dane obiektu. */

    virtual void wypiszDetale();
}; 

#endif
