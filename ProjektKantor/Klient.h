#include "Portfel.h"
#include "Uzytkownik.h"
using namespace std;
#ifndef KLIENT_H
#define KLIENT_H

/** Klasa dziedziczaca po uzytkowniku, dodatkowo posiada wskaznik na portfel. */

class Klient : public Uzytkownik
{
    shared_ptr<Portfel> m_portfel; /** Wskaznik na portfel. */

public:
    /** Konstruktor bezargumentowy klasy. */

    Klient();
    
    /** Destruktor. */

    ~Klient();

    /** Funkcja przypisujaca nowy portfel do uzytkownika. */

    void przypiszPortfel(shared_ptr<Portfel> portfel);

    /** Funkcja zwracajca wskaznik na portfel. */

    shared_ptr<Portfel>zwrocPortfel();

    /** Przeciazenie operatora przypisania, przypisywane sa dane uzytkownika z racji, ze klient posiada tylko dodatkowy portfel, funkcja przydatna przy logowaniu. */

    Klient operator=(Uzytkownik& uzytkownik);
}; 
#endif
