#include "BazaDanych.h"
#include "Portfel.h"
#include "Klient.h"
using namespace std;
#ifndef KANTOR_H
#define KANTOR_H

/** Klasa sluzaca do obslugi najwazniejszych funkcji programu,
* operuje ona na bazie danych. */
class Kantor
{

public:
    /** Destuktor. */

    ~Kantor();

    /** Konstruktor bezargumentowy. */

    Kantor();

    /** Funkcja zwracajaca fluktuacje wybranej przez uzytkownika kryptowaluty. */

    double sprawdzFluktuacje(string& nazwaKrypto, BazaDanych& baza);

    /** Funkcja zwracajaca cene ask wybranej przez uzytkownika kryptowaluty. */

    double sprawdzCeneAsk(string& nazwaKrypto, BazaDanych& baza);

    /** Funkcja zwracajaca cene bid wybranej przez uzytkownika kryptowaluty. */

    double sprawdzCeneBid(string& nazwaKrypto, BazaDanych& baza);

    /** Funkcja zwracajaca kurs wybranej przez uzytkownika fizycznej waluty. */

    double sprawdzKurs(string& nazwaWaluty, BazaDanych& baza);

    /** Funkcja zwracajaca kurs skupu wybranej przez uzytkownika fizycznej waluty. */

    double sprawdzKursSkupu(string& nazwaWaluty, BazaDanych& baza);

    /** Funkcja zwracajaca kurs wybranej przez uzytkownika kryptowaluty. */

    double sprawdzKursKrypto(string& nazwaWaluty, BazaDanych& baza);

    /** Funkcja zwracajaca ilosc wybranej przez uzytkownika waluty w kantorze. */

    double sprawdzDostepnosc(string& nazwaWaluty, BazaDanych& baza);

    /** Funkcja odpowiadajaca za przydzielanie wybranej przez uzytkownika ilosci pieniedzy do portfela, do usuniecia jej z 
    * kantoru oraz zapisania danych w pliku tekstowym. */

    void wezPozyczke(string& nazwaWaluty, double& pozyczka, BazaDanych& baza, Portfel& portfel, ofstream& of, Klient& klient);

    /** Funkcja przeprowadzajaca wymiane waluty, usuwa dana ilosc jednej waluty z kantoru, dodaje druga i analogicznie obslugiwany jest portfel klienta. */

    void wymienWalute(string& twojaWaluta, string& kantoruWaluta, double& ile, Portfel& portfel, BazaDanych& baza);

    /** Funkcja przeprowadzajaca wymiane kryptowaluty, obliczany jest przelicznik za pomoca cen ask i bid i wymieniana jest zawartosc portfelu uzytkownika. */

    void wymienKrypto(string& twojaKrypto, string& kantoruKrypto, double& ile, Portfel& portfel, BazaDanych& baza);

    /** Funkcja zapisujaca do pliku zewnetrznego nazwe i ilosc zamowionej waluty oraz dane klienta. */

    void zlozZamowienie(string& nazwaWaluty, double& ile, ofstream& of, BazaDanych& baza, Klient& klient);

    /** Funkcja za pomoca ktorej mozemy kupic kryptowalute za zlotowki. */

    void kupKrypto(string& nazwaKrypto, string& zlotowka, double& ile, BazaDanych& baza, Portfel& portfel);

    /** Funkcja za pomoca ktorej mozemy sprzedac kryptowalute za zlotowki. */

    void sprzedajKrypto(string& nazwaKrypto, string& zlotowka, double& ile, BazaDanych& baza, Portfel& portfel);

    /** Funkcja wypisujaca informacje o wszystkich kryptowalutach. */

    void wypiszKrypto(BazaDanych& baza);

    /** Funkcja wypisujaca informacje o wszystkich walutach fizycznych. */

    void wypiszFizyczne(BazaDanych& baza);

    /** Funkcja wypisujaca informacje o wszystkich walutach. */

    void wypiszWszystko(BazaDanych& baza);
};
#endif
