#include "Waluta.h"
using namespace std;

Waluta::Waluta(string kod, double kurs, string nazwa, double ilosc) : Pieniadz{ nazwa,ilosc }, m_kurs{ kurs }, m_kod{ kod }
{
}

Waluta::~Waluta()
{
}

double Waluta::zwrocKurs()
{
    return m_kurs;
}

string Waluta::zwrocKod()
{
    return m_kod;
}

void Waluta::wypiszDetale()
{
	cout << this->zwrocNazwe() << " " << m_kod << " " << m_kurs << this->zwrocIloscPieniadza() << endl;
}