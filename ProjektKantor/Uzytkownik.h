#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

/** Klasa przechowujaca dane uzytkownika oraz umozliwiajaca zalogowanie sie. */

class Uzytkownik
{
protected:
    string m_imie; /** Zmienna przechowujaca imie uzytkownika. */
    string m_nazwisko; /** Zmienna przechowujaca nazwisko uzytkownika. */
    int m_ID; /** Zmienna przechowujaca ID uzytkownika. */
    string m_login; /** Zmienna przechowujaca login uzytkownika. */
    string m_haslo; /** Zmienna przechowujaca haslo uzytkownika */
public:

    /** Konstruktor wieloargumentowy klasy. */

    Uzytkownik(int ID, string imie, string nazwisko, string login, string haslo);

    /** Konstruktor bezargumentowy klasy. */

    Uzytkownik();

    /** Konsturktor kopiujacy. */

    Uzytkownik(Uzytkownik& uzytkownik);

    /** Destruktor klasy. */

    ~Uzytkownik();

    /** Funkcja ktora sprawdza zgodnosc loginu i hasla z danymi uzytkownika. Jesli wystapi zgodnosc zwracane jest ID. */

    int zaloguj(string login, string haslo);

    /** Funkcja zwracajaca imie i nazwisko. */

    string zwrocDaneOs();

    /** Funkcja zwracajaca ID uzytkownika. */

    int zwrocID();
     
    /** Funkcja zwracajaca imie uzytkownika. */

    string zwrocImie();

    /** Funkcja zwracajaca nazwisko uzytkownika. */

    string zwrocNazwisko();

    /** Funkcja zwracajaca login uzytkownika. */

    string zwrocLogin();

    /** Funkcja zwracajaca haslo uzytkownika. */

    string zwrocHaslo();

    /** Przeciazenie operatora << (w zasadzie to deklaracja, definicja poza klasa), teraz wypisuje wszystkie dane uzytkownika. */
    
    friend ostream& operator<< (ostream& out, Uzytkownik& uzytkownik);
}; 
#endif
