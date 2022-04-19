#include "Klient.h"
using namespace std;

Klient::Klient() : m_portfel{ NULL }
{

}
Klient::~Klient()
{
}
void Klient::przypiszPortfel(shared_ptr<Portfel> portfel)
{
    m_portfel = move(portfel);
}
shared_ptr<Portfel> Klient::zwrocPortfel()
{
    return m_portfel;
}
Klient Klient::operator=(Uzytkownik& uzytkownik)
{
    m_imie = uzytkownik.zwrocImie();
    m_nazwisko = uzytkownik.zwrocNazwisko();
    m_ID = uzytkownik.zwrocID();
    m_login = uzytkownik.zwrocLogin();
    m_haslo = uzytkownik.zwrocHaslo();
    return *this;
}