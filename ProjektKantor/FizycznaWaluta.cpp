#include "FizycznaWaluta.h"
using namespace std;


    FizycznaWaluta::FizycznaWaluta(string kod, double kurs, string nazwa, double ilosc, double kursSkupu) :
        Waluta{ kod, kurs, nazwa, ilosc }, m_kursSkupu{ kursSkupu }
    {
    }
    FizycznaWaluta::~FizycznaWaluta()
    {
    }

    double FizycznaWaluta::zwrocKursSprzedazy()
    {
        return m_kursSkupu;
    }
    void FizycznaWaluta::wypiszDetale()
    {
        cout << *this;
    }
    ostream& operator<< (ostream& out, FizycznaWaluta& fizyk)
    {
        out << fizyk.zwrocKod() << " " << fizyk.zwrocNazwe() << " " << fizyk.zwrocKursSprzedazy() << " " << fizyk.zwrocKurs()
            << " " << fizyk.zwrocIloscPieniadza() << endl;
        return out;
    }
