#include "Uzytkownik.h"
using namespace std;

Uzytkownik::Uzytkownik(int ID, string imie, string nazwisko, string login, string haslo) : m_ID{ ID }, m_imie{ imie }, m_nazwisko{ nazwisko },
m_login{ login }, m_haslo{ haslo }
{
}
Uzytkownik::Uzytkownik() : m_ID{}
{
}
Uzytkownik::Uzytkownik(Uzytkownik& uzytkownik) : m_imie{ uzytkownik.zwrocImie() }, m_nazwisko{ uzytkownik.zwrocNazwisko() }, m_login{ uzytkownik.zwrocLogin() },
m_haslo{ uzytkownik.zwrocHaslo() }, m_ID{ uzytkownik.zwrocID() }
{
}
Uzytkownik::~Uzytkownik()
{
}
int Uzytkownik::zaloguj(string login, string haslo)
{
    if (m_login == login && m_haslo == haslo)
        return m_ID;
    else
        return -1;
}
string Uzytkownik::zwrocDaneOs()
{
    return m_imie + " " + m_nazwisko;
}
int Uzytkownik::zwrocID()
{
    return m_ID;
}
string Uzytkownik::zwrocImie()
{
    return m_imie;
}
string Uzytkownik::zwrocNazwisko()
{
    return m_nazwisko;
}
string Uzytkownik::zwrocLogin()
{
    return m_login;
}
string Uzytkownik::zwrocHaslo()
{
    return m_haslo;
}
ostream& operator<< (ostream& out, Uzytkownik& uzytkownik)
{
    out << uzytkownik.zwrocID() << " " << uzytkownik.zwrocImie() << " " << uzytkownik.zwrocNazwisko() << " "
        << uzytkownik.zwrocLogin() << " " << uzytkownik.zwrocHaslo() << endl;
    return out;
}