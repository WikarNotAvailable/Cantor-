#include "BazaDanych.h"
#include "Klient.h"
using namespace std;
int logowanie(vector<shared_ptr<Uzytkownik>> Uzytkownicy)
{
    string login;
    string haslo;
    cout << "Podaj login" << endl;
    cin >> login;
    cout << "Podaj haslo" << endl;
    cin >> haslo;
    for (int i = 0; i < Uzytkownicy.size(); i++)
    {
        int wynik = (*Uzytkownicy[i]).zaloguj(login, haslo);
        if (wynik != -1)
            return wynik;

    }
    return -1;
}
void rejestracja(BazaDanych& baza)
{
    string imie, nazwisko, login, haslo;
    int ID = baza.stworzNoweID();
    cout << "Wpisz swoje imie." << endl;
    cin >> imie;
    cout << "Wpisz swoje nazwisko." << endl;
    cin >> nazwisko;
    cout << "Wpisz swoj login." << endl;
    cin >> login;
    cout << "Wpisz swoje haslo." << endl;
    cin >> haslo;

    Uzytkownik nowy{ ID, imie, nazwisko, login, haslo };
    baza.dodajUzytkownika(nowy);
}
void wypiszMenu()
{
    cout << "Wpisz numer odpowiadajacy akcji." << endl;
    cout << endl;
    cout << "1. Sprawdz kurs kupna waluty (Cena jednej jednostki danej waluty)." << endl;
    cout << "2. Sprawdz kurs sprzedazy waluty (Za ile kupimy jedna jednostke danej waluty)." << endl;
    cout << "3. Sprawdz kurs, cene Ask(za ile najmniej mozemy kupic kryptowalute) i cene Bid(za ile najwiecej mozemy sprzedac kryptowalute) kryptowaluty." << endl;
    cout << "4. Zloz zamowienie na walute." << endl;
    cout << "5. Wez pozyczke." << endl;
    cout << "6. Zobacz stan portfela." << endl;
    cout << "7. Wymien walute." << endl;
    cout << "8. Sprawdz dostepnosc waluty." << endl;
    cout << "9. Wypisz informacje o wszystkich walutach dostepnych w kantorze." << endl;
    cout << "10. Wypisz informacje o wszystkich kryptowalutach dostepnych w kantorze." << endl;
    cout << "11. Wymien kryptowalute." << endl;
    cout << "12. Kup kryptowalute za zlotowki." << endl;
    cout << "13. Sprzedaj kryptowalute za zlotowki." << endl;
    cout << "14. Sprawdz fluktuacje kryptowaluty." << endl;
    cout << "15. Wypisz informacje o wszystkich walutach." << endl;
    cout << "16. Opusc kantor." << endl;
}
int wybierzWaluteFiz(string& nazwa, double& ilosc, BazaDanych& baza)
{
    bool walidacja = 1;
    cout << "Wpisz nazwe waluty" << endl;
    cin >> nazwa;

    while (walidacja)
    {
        cout << "Wpisz ilosc waluty" << endl;
        walidacja = 0;
        cin >> ilosc;
        if (cin.fail())
        {
            walidacja = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Blednie wpisales ilosc!" << endl;
        }
    }
    if (ilosc < 0)
    {
        cout << "Blednie wpisales ilosc!" << endl;
        return -1;
    }
    if (baza.porownajFizyczne(nazwa))
        return 1;
    else
        return -1;
}
int wybierzWaluteKryp(string& nazwa, double& ilosc, BazaDanych& baza)
{
    bool walidacja = 1;
    cout << "Wpisz nazwe waluty" << endl;
    cin >> nazwa;

    while (walidacja)
    {
        cout << "Wpisz ilosc waluty" << endl;
        walidacja = 0;
        cin >> ilosc;
        if (cin.fail())
        {
            walidacja = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Blednie wpisales ilosc!" << endl;
        }
    }
    if (ilosc < 0)
    {
        cout << "Blednie wpisales ilosc!" << endl;
        return -1;
    }

    if (baza.porownajKrypto(nazwa))
        return 1;
    else
        return -1;

}
double wybierzIlosc()
{
    double ilosc;
    bool walidacja = 1;
    while (walidacja)
    {
        cin >> ilosc;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wpisales bledna ilosc!" << endl;
        }
        else
        {
            if (ilosc > 0)
                return ilosc;
            else
            {
                cout << "Wpisales bledna ilosc!" << endl;
                return -1;
            }
        }
    }
    return -1;
}
