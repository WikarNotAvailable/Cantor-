#include "Pieniadz.h"
using namespace std;
#ifndef PORTFEL_H
#define PORTFEL_H

/** Klasa sluzaca do przechowywania pieniedzy ktore posiada klient i na ktorych
* dziala klient w trakcie dzialania programu. */
class Portfel
{
    int m_iloscPieniedzy; /** Zmienna opisujaca ilosc roznych walut posiadanych przez klienta. */
    vector<shared_ptr<Pieniadz>> m_zawartosc; /** Pieniadze fizyczne. */
    vector<shared_ptr<Pieniadz>> m_krypto; /** Pieniadze krypto. (rozdzielilem zmienna wyzej i ta w ten sposob, ze wzgledu na to ze potrzebowalem tylko nazwe i ilosc, dlatego nie robilem osobnych klas, bo niczym by sie nie roznily. */ 

public:

    /** Konstruktor bezargumentowy. */

    Portfel();

    /** Destruktor. */

    ~Portfel();

    /** Funkcja sprawdzajaca czy w portfelu znajduje sie krypto pieniadz o podanej nazwie. */

    bool sprawdzCzyIstniejeKrypto(string& nazwa);

    /** Funkcja sprawdzajaca czy w portfelu zandjuje sie fizyczny pieniadz o podanej nazwie. */

    bool sprawdzCzyIstniejeFizyczna(string& nazwa);

    /** Funkcja sprawdzajaca ilosc rodzajow fizycznych pieniedzy w portfelu. */

    int zwrocRozmiarFizycznych();

    /** Funkcja sprawdzajaaca ilosc rodzajow krypto pieniedzy w portfelu. */

    int zwrocRozmiarKrypto();

    /** Funkcja zwracajaca ilosc pieniedzy danego fizycznego rodzaju znajdujacego sie w portfelu. */

    double zwrocIloscWaluty(string& nazwa);

    /** Funkcja zwracajaca ilosc pieniedzy danego krypto rodzaju znajdujacego sie w portfelu. */

    double zwrocIloscKrypto(string& nazwa);

    /** Funkcja zwracajaca wskaznik na pieniadz okreslony indeksem. */

    shared_ptr<Pieniadz> zwrocPieniadz(int& indeks);

    /** Funkcja zwracajaca wskaznik na krypto pieniadz okreslony indeksem. */

    shared_ptr<Pieniadz> zwrocJednaKrypto(int& indeks);

    /** Funkcja zwracajaca vector wskaznikow na pieniadze rodzaju fizycznego. */

    vector<shared_ptr<Pieniadz>> zwrocFizyczne();

    /** Funkcja zwracajaca vector wskaznikow na krypto pieniadze. */

    vector<shared_ptr<Pieniadz>> zwrocKrypto();

    /** Funkcja dodajaca do vectora wskaznik na nowy pieniadz o podanej przez argument nazwie i ilosci. */

    void uzupelnijFizyczna(string& nazwa, double& ilosc);

    /** Funkcja dodajaca do vectora wskaznik na nowy krypto pieniadz o podanej przez argument nazwie i ilosci. */

    void uzupelnijKrypto(string& nazwa, double& ilosc);

    /** Funkcja zwracajaca czy portfel jest pusty. */

    bool czyPusty();

    /** Funkcja wypisujaca zawartosc portfela. */

    void pokazPortfel();

}; 
#endif
