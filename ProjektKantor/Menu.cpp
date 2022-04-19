#include "Menu.h"
#include "Portfel.h"
Menu::Menu()
{}

Menu::~Menu()
{}

void Menu::obslugaKont(BazaDanych& baza, Klient& uzytkownik, shared_ptr<Portfel> &portfel)
{
    int ID;
    int wybor;
    bool kontynuuj = true;

    while (kontynuuj)
    {
        cout << "Wpisz numer odpowiadajacy akcji." << endl;
        cout << endl;
        cout << "1. Zaloguj sie" << endl;
        cout << "2. Zaloz konto" << endl;
        cin >> wybor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
        }

        if (wybor == 1)
        {
            while (true)
            {
                ID = logowanie(baza.zwrocUzytkownikow());
                if (ID != -1)
                {
                    system("cls");
                    break;
                }
                else
                {
                    cout << "Wpisano niepoprawne dane." << endl;
                    system("pause");
                    system("cls");
                }
            }

            for (int i = 0; i < baza.zwrocUzytkownikow().size(); i++)
            {
                if ((*baza.zwrocUzytkownikow()[i]).zwrocID() == ID)
                {
                    uzytkownik = *baza.zwrocUzytkownikow()[i];
                    kontynuuj = false;
                    uzytkownik.przypiszPortfel(portfel);
                    break;
                }
            }
        }
        else if (wybor == 2)
        {
            rejestracja(baza);
            system("cls");
        }
        else
        {
            cout << "Wybrano nieprawidlowa opcje!" << endl;
            system("pause");
            system("cls");
        }
    }
}
void Menu::uzupelnijPortfel(BazaDanych& baza, Klient& uzytkownik)
{
    bool kontynuuj = 1;
    string nazwa;
    double ilosc;
    int wybor;

    cout << "Witaj w kantorze! " << uzytkownik.zwrocDaneOs() << endl;
    cout << "Okresl posiadany przez siebie portfel." << endl;
    while (kontynuuj)
    {
        system("pause");
        system("cls");
        cout << "Waluty obslugiwane przez kantor:" << endl;
        baza.pokazNazwy();

        cout << "Wpisz numer odpowiadajacy akcji." << endl;
        cout << endl;
        cout << "1.Wpisz jaka kryptowalute posiadasz." << endl;
        cout << "2.Wpisz jaka fizyczna walute posiadasz." << endl;
        cout << "3.Przejdz dalej." << endl;
        cin >> wybor;

        if (wybor == 1)
        {
            if (wybierzWaluteKryp(nazwa, ilosc, baza) == 1)
                uzytkownik.zwrocPortfel()->uzupelnijKrypto(nazwa, ilosc);
            else
                cout << "Nie obslugujemy wymiany wybranej przez ciebie kryptowaluty lub wprowadziles bledna ilosc!" << endl;
        }
        else if (wybor == 2)
        {
            if (wybierzWaluteFiz(nazwa, ilosc, baza) == 1)
                uzytkownik.zwrocPortfel()->uzupelnijFizyczna(nazwa, ilosc);
            else
                cout << "Nie obslugujemy wymiany wybranej przez ciebie waluty lub wprowadziles bledna ilosc!" << endl;
        }
        else if (wybor == 3)
        {
            if (uzytkownik.zwrocPortfel()->czyPusty() == true)
            {
                cout << "Twoj portfel jest pusty! Uzupelnij go!" << endl;
            }
            else
                kontynuuj = false;
        }
        else
        {
            cout << "Bledny wybor!" << endl;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
            }
        }
    }
    system("cls");
}
void Menu::obslugujKantor(BazaDanych& baza, Klient& uzytkownik, Kantor& kantor, ofstream &of, ofstream &off)
{
    int wybor;
    bool kontynuuj = true;
    bool walidacja = true;
    string nazwaWaluty;
    string nazwaWaluty2;
    double ilosc;

    while (kontynuuj)
    {
        system("pause");
        system("cls");
        wypiszMenu();

        cin >> wybor;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            wybor = -1;
        }

        switch (wybor)
        {
        case 1:
            cout << "Wpisz nazwe waluty, ktorej kurs kupna chcesz zobaczyc." << endl;
            cin >> nazwaWaluty;
            if (kantor.sprawdzKurs(nazwaWaluty, baza) != -1)
                cout << "Kurs " << nazwaWaluty << " to " << kantor.sprawdzKurs(nazwaWaluty, baza) << "zl" << endl;
            break;
        case 2:
            cout << "Wpisz nazwe waluty, ktorej kurs skupu chcesz zobaczyc." << endl;
            cin >> nazwaWaluty;
            cout << "Kurs skupu " << nazwaWaluty << " to " << kantor.sprawdzKursSkupu(nazwaWaluty, baza) << "zl" << endl;
            break;
        case 3:
            cout << "Wpisz nazwe kryptowaluty, ktorej kurs, cene Ask oraz cene Bid chcesz zobaczyc." << endl;
            cin >> nazwaWaluty;
            if (kantor.sprawdzKursKrypto(nazwaWaluty, baza) != -1)
            {
                cout << "Kurs " << nazwaWaluty << " to " << kantor.sprawdzKursKrypto(nazwaWaluty, baza) << "zl" << endl;
                cout << "Cena Ask " << nazwaWaluty << " to " << kantor.sprawdzCeneAsk(nazwaWaluty, baza) << "zl" << endl;
                cout << "Cena Bid " << nazwaWaluty << " to " << kantor.sprawdzCeneBid(nazwaWaluty, baza) << "zl" << endl;
            }
            break;
        case 4:
            cout << "Wpisz nazwe waluty, na ktora chcesz zlozyc zamowienie." << endl;
            cin >> nazwaWaluty;
            cout << "Wpisz ilosc waluty, na ktora chcesz zlozyc zamowienie." << endl;
            ilosc = wybierzIlosc();
            if (ilosc != -1)
                kantor.zlozZamowienie(nazwaWaluty, ilosc, of, baza, uzytkownik);
            break;
        case 5:
            cout << "Wpisz nazwe waluty, ktora chcesz pozyczyc." << endl;
            cin >> nazwaWaluty;
            cout << "Wpisz ilosc waluty, ktora chcesz pozyczyc." << endl;
            ilosc = wybierzIlosc();
            if (ilosc != -1)
                kantor.wezPozyczke(nazwaWaluty, ilosc, baza, (*uzytkownik.zwrocPortfel()), off, uzytkownik);
            break;
        case 6:
            uzytkownik.zwrocPortfel()->pokazPortfel();
            break;
        case 7:
            cout << "Wpisz nazwe waluty ktora chcesz wymienic." << endl;
            cin >> nazwaWaluty;
            cout << "Wpisz nazwe waluty na ktora chcesz wymienic." << endl;
            cin >> nazwaWaluty2;
            cout << "Wpisz ile swojej waluty chcesz wymienic." << endl;
            ilosc = wybierzIlosc();
            if (ilosc != -1)
                kantor.wymienWalute(nazwaWaluty, nazwaWaluty2, ilosc, (*uzytkownik.zwrocPortfel()), baza);
            break;
        case 8:
            cout << "Wpisz nazwe waluty, ktorej dostepnosc chcesz sprawdzic." << endl;
            cin >> nazwaWaluty;
            if (kantor.sprawdzDostepnosc(nazwaWaluty, baza) != -1)
                cout << "Dostepnosc " << nazwaWaluty << " wynosi " << kantor.sprawdzDostepnosc(nazwaWaluty, baza) << endl;
            break;
        case 9:
            cout << "Kod Nazwa KursSkupu Kurs Ilosc" << endl;
            kantor.wypiszFizyczne(baza);
            break;
        case 10:
            cout << "Nazwa Kod Kurs Fluktuacja CenaBid CenaAsk" << endl;
            kantor.wypiszKrypto(baza);
            break;
        case 11:
            cout << "Wpisz nazwe kryptowaluty ktora chcesz wymienic." << endl;
            cin >> nazwaWaluty;
            cout << "Wpisz nazwe kryptowaluty na ktora chcesz wymienic." << endl;
            cin >> nazwaWaluty2;
            cout << "Wpisz ile swojej kryptowaluty chcesz wymienic." << endl;
            ilosc = wybierzIlosc();
            if (ilosc != -1)
                kantor.wymienKrypto(nazwaWaluty, nazwaWaluty2, ilosc, (*uzytkownik.zwrocPortfel()), baza);
            break;
        case 12:
            cout << "Wpisz nazwe kryptowaluty, ktora chcesz kupic." << endl;
            cin >> nazwaWaluty;
            nazwaWaluty2 = "Zloty";
            cout << "Wpisz ile zlotowek chcesz przeznaczyc na te kryptowalute." << endl;
            ilosc = wybierzIlosc();
            if (ilosc != -1)
                kantor.kupKrypto(nazwaWaluty, nazwaWaluty2, ilosc, baza, (*uzytkownik.zwrocPortfel()));
            break;
        case 13:
            cout << "Wpisz nazwe kryptowaluty, ktora chcesz sprzedac." << endl;
            cin >> nazwaWaluty;
            nazwaWaluty2 = "Zloty";
            cout << "Wpisz ile kryptowaluty chcesz sprzedac." << endl;
            ilosc = wybierzIlosc();
            if (ilosc != -1)
                kantor.sprzedajKrypto(nazwaWaluty, nazwaWaluty2, ilosc, baza, (*uzytkownik.zwrocPortfel()));
            break;
        case 14:
            cout << "Wpisz nazwe kryptowaluty, ktorej fluktuacje chcesz sprawdzic." << endl;
            cin >> nazwaWaluty;
            if (kantor.sprawdzFluktuacje(nazwaWaluty, baza) != -1)
                cout << "Fluktuacja " << nazwaWaluty << " to " << kantor.sprawdzFluktuacje(nazwaWaluty, baza) << "%" << endl;
            break;
        case 15:
            kantor.wypiszWszystko(baza);
                break;
        case 16:
            cout << "Do widzenia! Zapraszamy ponownie!" << endl;
            kontynuuj = false;
            break;
        default:
            cout << "Wybrano nieprawidlowa opcje!";
            break;
        }
    }
}

