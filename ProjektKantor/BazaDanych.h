#include "Uzytkownik.h"
#include "KryptoWaluta.h"
#include "FizycznaWaluta.h"
using namespace std;
#ifndef BAZADANYCH_H
#define BAZADANYCH_H
/** Klasa BazaDanych zawiera wszystkie dane wczytywane z zewnatrz,
* takie jak baza uzytkownikow, baza kryptowaluta oraz baza walut
* fizycznych, zawiera metody sluzace do wczytywania oraz
* nadpisywania tych danych z pliku zewnetrznego.
*/
class BazaDanych
{
    vector<shared_ptr<Uzytkownik>> m_uzytkownicy; /**vector wskaznikow na uzytkownikow wczytanych z pliku. */
    vector<shared_ptr<KryptoWaluta>> m_bazaKrypto; /** vector wskaznikow na kryptowaluty wczytane z pliku. */
    vector<shared_ptr<FizycznaWaluta>> m_zasoby; /** vector wskaznikow na fizyczne waluty wczytane z pliku. */

    /** Funkcja wczytajaca uzytkownikow z pliku zewnetrznego i tworzaca dynamicznie obiekty za pomoca wskaznikow w wektorze. */

    void wczytajUzytkownikow(string& plikUzytkownicy);

    /** Funkcja wczytajaca kryptowaluty z pliku zewnetrznego i tworzaca dynamicznie obiekty za pomoca wskaznikow w wektorze. */

    void wczytajKrypto(string& plikKrypto);

    /** Funkcja wczytajaca fizyczne waluty z pliku zewnetrznego i tworzaca dynamicznie obiekty za pomoca wskaznikow w wektorze. */

    void wczytajFizyczne(string& plikFizyczne);

    /** Funkcja nadpisujaca zmiany bazy Uzytkownikow na pliku zewnetrznym. */

    void zapiszUzytkownikow(string& plikUzytkownicy);

    /** Funkcja nadpisujaca zmiany bazy kryptowalut na pliku zewnetrznym. */

    void zapiszKrypto(string& plikKrypto);

    /** Funkcja nadpisujaca zmiany bazy walut fizycznych na pliku zewnetrznym. */

    void zapiszFizyczne(string& plikFizyczne);

public:
    /** Konstruktor przyjmuajcy za argumenty nazwy plikow zewnetrznych z ktorych
    * pobrane maja byc dane, konstruktor ten wywoluje trzy funkcje
    * zadeklarowane w private. */

    BazaDanych(string plikUzytkownicy, string plikKrypto, string plikFizyczne);

    /** Destuktor. */
    ~BazaDanych();

    /** Funkcja wywolujaca funkcje zapisujace dane na pliku zewnetrznym
    * za argumenty przyjmuje nazwy plikow zewnetrznych. */

    void zapiszDane(string plikUzytkownicy, string plikKrypto, string plikFizyczne);

    /** Funkcja wypisujaca nazwy walut i kryptowalut dostepnych w kantorze. */

    void pokazNazwy(); 

    /** Zwraca baze danych uzytkownikow. */

    vector<shared_ptr<Uzytkownik>> zwrocUzytkownikow();

    /** Dodanie nowego uzytkownika do bazy. */

    void dodajUzytkownika(Uzytkownik& uzytkownik);

    /** Generowanie nowego ID. */

    int stworzNoweID();

    /** Sprawdza czy podana waluta znajduje sie w bazie. */

    bool porownajFizyczne(string& nazwa);

    /** Sprawdza czy podana kryptowaluta znajduje sie w bazie. */

    bool porownajKrypto(string& nazwa);

    /** Zaprzyjaznienie z klasa Kantor. */

    friend class Kantor;
};
#endif