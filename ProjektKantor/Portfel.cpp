#include "Portfel.h"
using namespace std;
Portfel::Portfel() : m_iloscPieniedzy {}
{
}
Portfel::~Portfel()
{
}
bool Portfel::sprawdzCzyIstniejeKrypto(string& nazwa)
{
    for (int i = 0; i < m_krypto.size(); i++)
    {
        if (nazwa == (*m_krypto[i]).zwrocNazwe())
            return true;
    }
    return false;
}
bool Portfel::sprawdzCzyIstniejeFizyczna(string& nazwa)
{
    for (int i = 0; i < m_zawartosc.size(); i++)
    {
        if (nazwa == (*m_zawartosc[i]).zwrocNazwe())
            return true;
    }
    return false;
}
int Portfel::zwrocRozmiarFizycznych()
{
    return m_zawartosc.size();
}
int Portfel::zwrocRozmiarKrypto()
{
    return m_krypto.size();
}
double Portfel::zwrocIloscWaluty(string& nazwa)
{
    for (int i = 0; i < m_zawartosc.size(); i++)
    {
        if (nazwa == (*m_zawartosc[i]).zwrocNazwe())
            return (*m_zawartosc[i]).zwrocIloscPieniadza();
    }
    return -1;
}
double Portfel::zwrocIloscKrypto(string& nazwa)
{
    for (int i = 0; i < m_krypto.size(); i++)
    {
        if (nazwa == (*m_krypto[i]).zwrocNazwe())
            return (*m_krypto[i]).zwrocIloscPieniadza();
    }
    return -1;
}
shared_ptr<Pieniadz> Portfel::zwrocPieniadz(int& indeks)
{
    return m_zawartosc[indeks];
}
shared_ptr<Pieniadz> Portfel::zwrocJednaKrypto(int& indeks)
{
    return m_krypto[indeks];
}
vector<shared_ptr<Pieniadz>> Portfel::zwrocFizyczne()
{
    return m_zawartosc;
}
vector<shared_ptr<Pieniadz>> Portfel::zwrocKrypto()
{
    return m_krypto;
}
void Portfel::uzupelnijFizyczna(string& nazwa, double& ilosc)
{
    if (this->sprawdzCzyIstniejeFizyczna(nazwa))
    {
        for (int i = 0; i < m_zawartosc.size(); i++)
        {
            if (nazwa == (*m_zawartosc[i]).zwrocNazwe())
                (*m_zawartosc[i]) += ilosc;
        }
        return;
    }
    m_iloscPieniedzy++;
    m_zawartosc.push_back(shared_ptr<Pieniadz>(new Pieniadz{ nazwa,ilosc }));
}
void Portfel::uzupelnijKrypto(string& nazwa, double& ilosc)
{
    if (this->sprawdzCzyIstniejeKrypto(nazwa))
    {
        for (int i = 0; i < m_krypto.size(); i++)
        {
            if (nazwa == (*m_krypto[i]).zwrocNazwe())
                (*m_krypto[i]) += ilosc;
        }
        return;
    }
    m_iloscPieniedzy++;
    m_krypto.push_back(shared_ptr<Pieniadz>(new Pieniadz{ nazwa,ilosc }));
}
bool Portfel::czyPusty()
{
    if (m_iloscPieniedzy == 0)
        return true;
    else
        return false;
}
void Portfel::pokazPortfel()
{
    for (int i = 0; i < m_zawartosc.size(); i++)
    {
        (*m_zawartosc[i]).wypiszDetale();
    }
    for (int j = 0; j < m_krypto.size(); j++)
    {
        (*m_krypto[j]).wypiszDetale();
    }
}