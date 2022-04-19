#include "Pieniadz.h"
using namespace std;

Pieniadz::Pieniadz(string nazwa, double ilosc) : m_nazwa{ nazwa }, m_iloscPieniadza{ ilosc }
{
}

Pieniadz::~Pieniadz()
{
}
string Pieniadz::zwrocNazwe()
{
    return m_nazwa;
}
double Pieniadz::zwrocIloscPieniadza()
{
    return m_iloscPieniadza;
}
void Pieniadz::wypiszDetale()
{
    cout << m_nazwa << ": " << m_iloscPieniadza << endl;
}

Pieniadz Pieniadz::operator+=(double wartosc)
{
    m_iloscPieniadza += wartosc;
    return *this;
}

Pieniadz Pieniadz::operator-=(double wartosc)
{
    m_iloscPieniadza -= wartosc;
    return *this;
}