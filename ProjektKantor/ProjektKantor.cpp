#include "Funkcje.h"
#include "Kantor.h"
#include "Menu.h"
using namespace std;

int main()
{
    BazaDanych baza{ "bazaUzytkownikow.txt", "bazaKrypto.txt", "bazaWalut.txt" };
    Kantor kantor{};
    ofstream of("bazaZamowien.txt", ios_base::app);
    ofstream off("bazaPozyczek.txt", ios_base::app);
    Menu menu{};
    Klient uzytkownik{};
    shared_ptr<Portfel> portfel(make_shared<Portfel>());

    menu.obslugaKont(baza, uzytkownik, portfel);
    menu.uzupelnijPortfel(baza, uzytkownik);
    menu.obslugujKantor(baza, uzytkownik, kantor, of, off);

    baza.zapiszDane("bazaUzytkownikow.txt", "bazaKrypto.txt", "bazaWalut.txt");
    of.close();
    off.close();
    return 0;
}
