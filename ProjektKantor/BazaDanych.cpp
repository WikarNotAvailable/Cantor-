#include "BazaDanych.h"
using namespace std;
void BazaDanych::wczytajUzytkownikow(string& plikUzytkownicy)
{
    fstream f;
    f.open(plikUzytkownicy, ios::in);

    if (f.is_open())
    {

        int ID;
        string imie;
        string nazwisko;
        string login;
        string haslo;

        while (f >> ID >> imie >> nazwisko >> login >> haslo)
        {
            m_uzytkownicy.push_back(make_shared<Uzytkownik>(ID, imie, nazwisko, login, haslo));
        }
        f.close();
    }
}
void BazaDanych::wczytajKrypto(string& plikKrypto)
{
    fstream f;
    f.open(plikKrypto, ios::in);

    if (f.is_open())
    {
        string kod;
        string kurs;
        string nazwa;
        string cenaBid;
        string fluktuacja;
        string cenaAsk;

        while (f >> nazwa >> kod >> kurs >> fluktuacja >> cenaBid >> cenaAsk)
        {
            m_bazaKrypto.push_back(make_shared<KryptoWaluta>(kod, atof(kurs.c_str()), nazwa, atof(fluktuacja.c_str()), atof(cenaBid.c_str()), atof(cenaAsk.c_str())));
        }
        f.close();
    }
}
void BazaDanych::wczytajFizyczne(string& plikFizyczne)
{
    fstream f;
    f.open(plikFizyczne, ios::in);

    if (f.is_open())
    {
        string kod;
        string kurs;
        string nazwa;
        string kursSprzedazy;
        string ilosc;

        while (f >> kod >> nazwa >> kurs >> kursSprzedazy >> ilosc)
        {
            m_zasoby.push_back(make_shared<FizycznaWaluta>(kod, atof(kurs.c_str()), nazwa, atof(ilosc.c_str()), atof(kursSprzedazy.c_str())));
        }
        f.close();
    }
}
void BazaDanych::zapiszUzytkownikow(string& plikUzytkownicy)
{
    ofstream of(plikUzytkownicy);
    if (of.good())
    {
        for (int i = 0; i < m_uzytkownicy.size(); i++)
        {
            of << (*m_uzytkownicy[i]);
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku wyjsciowego z uzytkownikami!" << endl;

    of.close();
}
void BazaDanych::zapiszKrypto(string& plikKrypto)
{
    ofstream of(plikKrypto);
    if (of.good())
    {
        for (int i = 0; i < m_bazaKrypto.size(); i++)
        {
            of << (*m_bazaKrypto[i]);
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku wyjsciowego z kryptowalutami!" << endl;

    of.close();
}
void BazaDanych::zapiszFizyczne(string& plikFizyczne)
{
    ofstream of(plikFizyczne);
    if (of.good())
    {
        for (int i = 0; i < m_zasoby.size(); i++)
        {
            of << (*m_zasoby[i]);
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku wyjsciowego z walutami!" << endl;

    of.close();
}
BazaDanych::BazaDanych(string plikUzytkownicy, string plikKrypto, string plikFizyczne)
{
    wczytajUzytkownikow(plikUzytkownicy);
    wczytajKrypto(plikKrypto);
    wczytajFizyczne(plikFizyczne);
}
BazaDanych::~BazaDanych()
{
}
void BazaDanych::zapiszDane(string plikUzytkownicy, string plikKrypto, string plikFizyczne)
{
    zapiszUzytkownikow(plikUzytkownicy);
    zapiszKrypto(plikKrypto);
    zapiszFizyczne(plikFizyczne);
}
void BazaDanych::pokazNazwy()
{
    cout << endl;
    cout << "Kryptowaluty:" << endl;
    for (int i = 0; i < m_bazaKrypto.size(); i++)
    {
        cout << (*m_bazaKrypto[i]).zwrocNazwe() << ", ";
    }
    cout << endl;
    cout << endl;
    cout << "Waluty fizyczne:" << endl;

    for (int i = 0; i < m_zasoby.size(); i++)
    {
        cout << (*m_zasoby[i]).zwrocNazwe() << ", ";
    }
    cout << endl;
    cout << endl;
} 
vector<shared_ptr<Uzytkownik>> BazaDanych::zwrocUzytkownikow()
{
    return m_uzytkownicy;
}
void BazaDanych::dodajUzytkownika(Uzytkownik& uzytkownik)
{
    m_uzytkownicy.push_back(shared_ptr<Uzytkownik>((new Uzytkownik(uzytkownik))));
}
int BazaDanych::stworzNoweID()
{
    return m_uzytkownicy.size() + 1;
}
bool BazaDanych::porownajFizyczne(string& nazwa)
{
    for (int i = 0; i < m_zasoby.size(); i++)
    {
        if (nazwa == (*m_zasoby[i]).zwrocNazwe())
            return true;
    }
    return false;
}
bool BazaDanych::porownajKrypto(string& nazwa)
{
    for (int i = 0; i < m_bazaKrypto.size(); i++)
    {
        if (nazwa == (*m_bazaKrypto[i]).zwrocNazwe())
        {
            return true;
        }
    }
    return false;
}