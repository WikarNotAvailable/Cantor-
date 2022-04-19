#include "KryptoWaluta.h"
using namespace std;

KryptoWaluta::KryptoWaluta(string kod, double kurs, string nazwa, double fluktuacja, double cenaBid, double cenaAsk, double ilosc) :
    Waluta{ kod, kurs, nazwa, ilosc }, m_fluktuacja{ fluktuacja }, m_cenaBid{ cenaBid }, m_cenaAsk{ cenaAsk }
{
}
KryptoWaluta::~KryptoWaluta()
{
}
double KryptoWaluta::zwrocFluktuacje()
{
    return m_fluktuacja;
}
double KryptoWaluta::zwrocCeneBid()
{
    return m_cenaBid;
}
double KryptoWaluta::zwrocCeneAsk()
{
    return m_cenaAsk;
}
void KryptoWaluta::wypiszDetale()
{
    cout << *this;
}
ostream& operator<< (ostream& out, KryptoWaluta& krypto)
{
    out << krypto.zwrocNazwe() << " " << krypto.zwrocKod() << " " << krypto.zwrocKurs() << " " << krypto.zwrocFluktuacje()
        << " " << krypto.zwrocCeneBid() << " " << krypto.zwrocCeneAsk() << endl;
    return out;
}

