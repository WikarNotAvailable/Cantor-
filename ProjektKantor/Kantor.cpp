#include "Kantor.h"
using namespace std;

Kantor::~Kantor()
{
}
Kantor::Kantor()
{
}
double Kantor::sprawdzFluktuacje(string& nazwaKrypto, BazaDanych& baza)
{
    for (int i = 0; i < baza.m_bazaKrypto.size(); i++)
    {
        if ((*baza.m_bazaKrypto[i]).zwrocNazwe() == nazwaKrypto)
            return (*baza.m_bazaKrypto[i]).zwrocFluktuacje();
    }
    cout << "Wpisales nazwe kryptowaluty nieobslugiwanej przez Kantor!" << endl;
    return -1;
}
double Kantor::sprawdzCeneAsk(string& nazwaKrypto, BazaDanych& baza)
{
    for (int i = 0; i < baza.m_bazaKrypto.size(); i++)
    {
        if ((*baza.m_bazaKrypto[i]).zwrocNazwe() == nazwaKrypto)
            return (*baza.m_bazaKrypto[i]).zwrocCeneAsk();
    }
    cout << "Wpisales nazwe kryptowaluty nieobslugiwanej przez Kantor!" << endl;
    return -1;
}
double Kantor::sprawdzCeneBid(string& nazwaKrypto, BazaDanych& baza)
{
    for (int i = 0; i < baza.m_bazaKrypto.size(); i++)
    {
        if ((*baza.m_bazaKrypto[i]).zwrocNazwe() == nazwaKrypto)
            return (*baza.m_bazaKrypto[i]).zwrocCeneBid();
    }
    cout << "Wpisales nazwe kryptowaluty nieobslugiwanej przez Kantor!" << endl;
    return -1;
}
double Kantor::sprawdzKurs(string& nazwaWaluty, BazaDanych& baza)
{
    for (int i = 0; i < baza.m_zasoby.size(); i++)
    {
        if ((*baza.m_zasoby[i]).zwrocNazwe() == nazwaWaluty)
            return (*baza.m_zasoby[i]).zwrocKurs();
    }
    cout << "Wpisales nazwe waluty nieobslugiwanej przez Kantor!" << endl;
    return -1;
}
double Kantor::sprawdzKursSkupu(string& nazwaWaluty, BazaDanych& baza)
{
    for (int i = 0; i < baza.m_zasoby.size(); i++)
    {
        if ((*baza.m_zasoby[i]).zwrocNazwe() == nazwaWaluty)
            return (*baza.m_zasoby[i]).zwrocKursSprzedazy();
    }
    cout << "Wpisales nazwe waluty nieobslugiwanej przez Kantor!" << endl;
    return -1;
}
double Kantor::sprawdzKursKrypto(string& nazwaWaluty, BazaDanych& baza)
{
    for (int i = 0; i < baza.m_bazaKrypto.size(); i++)
    {
        if ((*baza.m_bazaKrypto[i]).zwrocNazwe() == nazwaWaluty)
            return (*baza.m_bazaKrypto[i]).zwrocKurs();
    }
    cout << "Wpisales nazwe kryptowaluty nieobslugiwanej przez Kantor!" << endl;
    return -1;
}
double Kantor::sprawdzDostepnosc(string& nazwaWaluty, BazaDanych& baza)
{
    for (int i = 0; i < baza.m_zasoby.size(); i++)
    {
        if ((*baza.m_zasoby[i]).zwrocNazwe() == nazwaWaluty)
            return (*baza.m_zasoby[i]).zwrocIloscPieniadza();
    }
    cout << "Wpisales nazwe waluty nieobslugiwanej przez Kantor!" << endl;
    return -1;
}
void Kantor::wezPozyczke(string& nazwaWaluty, double& pozyczka, BazaDanych& baza, Portfel& portfel, ofstream& of, Klient& klient)
{
    bool czyStworzyc = 1;
    if (this->sprawdzDostepnosc(nazwaWaluty, baza) < pozyczka)
    {
        cout << "Brak wystarczajacej ilosci waluty w kantorze, aby udzielic pozyczki!" << endl;
        return;
    }
    for (int i = 0; i < baza.m_zasoby.size(); i++)
    {
        if ((*baza.m_zasoby[i]).zwrocNazwe() == nazwaWaluty)
        {
            *baza.m_zasoby[i] -= pozyczka;
            for (int j = 0; j < portfel.zwrocFizyczne().size(); j++)
            {
                if ((*portfel.zwrocPieniadz(j)).zwrocNazwe() == nazwaWaluty)
                {
                    czyStworzyc = 0;
                    (*portfel.zwrocPieniadz(j)) += pozyczka;
                    break;
                }
            }
            if (czyStworzyc)
                portfel.uzupelnijFizyczna(nazwaWaluty, pozyczka);


            break;
        }
    }
    if (of.good())
    {
        of << klient.zwrocDaneOs() << " " << nazwaWaluty << " " << pozyczka << endl;
    }
    else
        cout << "Nie udalo sie otworzyc pliku z baza zamowien!" << endl;

}
void Kantor::wymienWalute(string& twojaWaluta, string& kantoruWaluta, double& ile, Portfel& portfel, BazaDanych& baza)
{
    bool porownanie1 = 0;
    bool porownanie2 = 0;
    bool czyStworzyc = 1;

    for (int i = 0; i < portfel.zwrocFizyczne().size(); i++)
    {
        if ((*portfel.zwrocPieniadz(i)).zwrocNazwe() == twojaWaluta)
        {
            porownanie1 = 1;
            break;
        }
    }
    for (int j = 0; j < baza.m_zasoby.size(); j++)
    {
        if ((*baza.m_zasoby[j]).zwrocNazwe() == kantoruWaluta)
        {
            porownanie2 = 1;
            break;
        }
    }
    if (porownanie1 != 1 || porownanie2 != 1)
    {
        cout << "Nie masz przy sobie wskazanej waluty lub nie posiadamy waluty, ktora chcesz otrzymac!" << endl;
        return;
    }
    if (ile > portfel.zwrocIloscWaluty(twojaWaluta))
    {
        cout << "Nie posiadasz tyle waluty ile bys chcial wymienic." << endl;
        return;
    }

    double iloscWalutyKantoru = (this->sprawdzKursSkupu(twojaWaluta, baza) * ile / this->sprawdzKurs(kantoruWaluta, baza));

    if (this->sprawdzDostepnosc(kantoruWaluta, baza) < iloscWalutyKantoru)
    {
        cout << "Nie ma wystarczajaco waluty w kantorze na wymiane!" << endl;
        return;
    }
    for (int i = 0; i < baza.m_zasoby.size(); i++)
    {
        if ((*baza.m_zasoby[i]).zwrocNazwe() == twojaWaluta)
        {
            *baza.m_zasoby[i] += ile;
        }
        if ((*baza.m_zasoby[i]).zwrocNazwe() == kantoruWaluta)
        {
            *baza.m_zasoby[i] -= iloscWalutyKantoru;
        }
    }
    for (int j = 0; j < portfel.zwrocFizyczne().size(); j++)
    {
        if ((*portfel.zwrocPieniadz(j)).zwrocNazwe() == kantoruWaluta)
        {
            czyStworzyc = 0;
            (*portfel.zwrocPieniadz(j)) += iloscWalutyKantoru;
        }
        if ((*portfel.zwrocPieniadz(j)).zwrocNazwe() == twojaWaluta)
        {
            (*portfel.zwrocPieniadz(j)) -= ile;
        }
    }
    if (czyStworzyc)
        portfel.uzupelnijFizyczna(kantoruWaluta, iloscWalutyKantoru);

}
void Kantor::wymienKrypto(string& twojaKrypto, string& kantoruKrypto, double& ile, Portfel& portfel, BazaDanych& baza)
{
    bool porownanie1 = 0;
    bool porownanie2 = 0;
    bool czyStworzyc = 1;

    for (int i = 0; i < portfel.zwrocKrypto().size(); i++)
    {
        if ((*portfel.zwrocJednaKrypto(i)).zwrocNazwe() == twojaKrypto)
        {
            porownanie1 = 1;
            break;
        }
    }
    for (int j = 0; j < baza.m_bazaKrypto.size(); j++)
    {
        if ((*baza.m_bazaKrypto[j]).zwrocNazwe() == kantoruKrypto)
        {
            porownanie2 = 1;
            break;
        }
    }
    if (porownanie1 != 1 || porownanie2 != 1)
    {
        cout << "Nie masz przy sobie wskazanej kryptowaluty lub nie posiadamy kryptowaluty, ktora chcesz otrzymac!" << endl;
        return;
    }
    if (ile > portfel.zwrocIloscKrypto(twojaKrypto))
    {
        cout << "Nie posiadasz tyle kryptowaluty ile bys chcial wymienic." << endl;
        return;
    }
    double iloscKrypto = (this->sprawdzKursKrypto(twojaKrypto, baza) * ile / this->sprawdzKursKrypto(kantoruKrypto, baza));

    for (int j = 0; j < portfel.zwrocKrypto().size(); j++)
    {
        if ((*portfel.zwrocJednaKrypto(j)).zwrocNazwe() == kantoruKrypto)
        {
            czyStworzyc = 0;
            (*portfel.zwrocJednaKrypto(j)) += iloscKrypto;
        }
        if ((*portfel.zwrocJednaKrypto(j)).zwrocNazwe() == twojaKrypto)
        {
            (*portfel.zwrocJednaKrypto(j)) -= ile;
        }
    }
    if (czyStworzyc)
        portfel.uzupelnijKrypto(kantoruKrypto, iloscKrypto);
}
void Kantor::zlozZamowienie(string& nazwaWaluty, double& ile, ofstream& of, BazaDanych& baza, Klient& klient)
{
    bool porownanie1 = 0;
    for (int j = 0; j < baza.m_zasoby.size(); j++)
    {
        if ((*baza.m_zasoby[j]).zwrocNazwe() == nazwaWaluty)
        {
            porownanie1 = 1;
            break;
        }
    }
    if (porownanie1 == 0)
    {
        cout << "Nie obslugujemy podanej przez ciebie waluty!" << endl;
        return;
    }
    if (this->sprawdzDostepnosc(nazwaWaluty, baza) > ile)
    {
        cout << "Posiadamy wystarczajaco waluty na wymiane, nie musisz skladac zamowienia!" << endl;
        return;
    }

    if (of.good())
    {
        of << klient.zwrocDaneOs() << " " << nazwaWaluty << " " << ile << endl;
    }
    else
        cout << "Nie udalo sie otworzyc pliku z baza zamowien!" << endl;
}
void Kantor::kupKrypto(string& nazwaKrypto, string& zlotowka, double& ile, BazaDanych& baza, Portfel& portfel)
{
    bool porownanie1 = 0;
    bool czyStworzyc = 1;

    for (int j = 0; j < baza.m_bazaKrypto.size(); j++)
    {
        if ((*baza.m_bazaKrypto[j]).zwrocNazwe() == nazwaKrypto)
        {
            porownanie1 = 1;
            break;
        }
    }
    if (porownanie1 == 0)
    {
        cout << "Nie obslugujemy wybranej przez ciebie Kryptowaluty" << endl;
        return;
    }
    if (ile > portfel.zwrocIloscWaluty(zlotowka))
    {
        cout << "Nie posiadasz tyle waluty ile bys chcial wymienic." << endl;
        return;
    }
    double iloscKrypto = (this->sprawdzKurs(zlotowka, baza) * ile / this->sprawdzCeneAsk(nazwaKrypto, baza));

    for (int j = 0; j < portfel.zwrocKrypto().size(); j++)
    {
        if ((*portfel.zwrocJednaKrypto(j)).zwrocNazwe() == nazwaKrypto)
        {
            czyStworzyc = 0;
            (*portfel.zwrocJednaKrypto(j)) += iloscKrypto;
        }
    }
    if (czyStworzyc)
        portfel.uzupelnijKrypto(nazwaKrypto, iloscKrypto);

    for (int j = 0; j < portfel.zwrocFizyczne().size(); j++)
    {
        if ((*portfel.zwrocPieniadz(j)).zwrocNazwe() == zlotowka)
        {
            (*portfel.zwrocPieniadz(j)) -= ile;
        }
    }
}
void Kantor::sprzedajKrypto(string& nazwaKrypto, string& zlotowka, double& ile, BazaDanych& baza, Portfel& portfel)
{
    bool porownanie1 = 0;
    bool czyStworzyc = 1;

    for (int i = 0; i < portfel.zwrocKrypto().size(); i++)
    {
        if ((*portfel.zwrocJednaKrypto(i)).zwrocNazwe() == nazwaKrypto)
        {
            porownanie1 = 1;
            break;
        }
    }
    if (porownanie1 == 0)
    {
        cout << "Nie obslugujemy wybranej przez ciebie Kryptowaluty" << endl;
        return;
    }
    if (ile > portfel.zwrocIloscKrypto(nazwaKrypto))
    {
        cout << "Nie posiadasz tyle kryptowaluty ile bys chcial wymienic." << endl;
        return;
    }
    double iloscZlotowek = (this->sprawdzCeneBid(nazwaKrypto, baza) * ile / this->sprawdzKurs(zlotowka, baza));

    for (int j = 0; j < portfel.zwrocKrypto().size(); j++)
    {
        if ((*portfel.zwrocJednaKrypto(j)).zwrocNazwe() == nazwaKrypto)
        {
            (*portfel.zwrocJednaKrypto(j)) -= ile;
        }
    }


    for (int j = 0; j < portfel.zwrocFizyczne().size(); j++)
    {
        if ((*portfel.zwrocPieniadz(j)).zwrocNazwe() == zlotowka)
        {
            czyStworzyc = 0;
            (*portfel.zwrocPieniadz(j)) += iloscZlotowek;
        }
    }
    if (czyStworzyc)
        portfel.uzupelnijFizyczna(zlotowka, iloscZlotowek);
}
void Kantor::wypiszKrypto(BazaDanych& baza)
{
    for (int i = 0; i < baza.m_bazaKrypto.size(); i++)
    {
        (*baza.m_bazaKrypto[i]).wypiszDetale();
    }
}
void Kantor::wypiszFizyczne(BazaDanych& baza)
{
    for (int i = 0; i < baza.m_zasoby.size(); i++)
    {
        (*baza.m_zasoby[i]).wypiszDetale();
    }
}
void Kantor::wypiszWszystko(BazaDanych& baza)
{
    vector<shared_ptr<Waluta>> wszystko;

    for (int i = 0; i < baza.m_zasoby.size(); i++)
    {
        wszystko.push_back(baza.m_zasoby[i]);
    }
    for (int i = 0; i < baza.m_bazaKrypto.size(); i++)
    {
        wszystko.push_back(baza.m_bazaKrypto[i]);
    }
    for (int i = 0; i < wszystko.size(); i++)
    {
        (*wszystko[i]).wypiszDetale();
    }
}