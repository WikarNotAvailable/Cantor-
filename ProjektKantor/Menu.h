#include "Klient.h"
#include "Kantor.h"
#include "Funkcje.h"
#ifndef MENU_H
#define MENU_H
/** Klasa menu wywoluje glowne opcje programu,
* obsluguje konta uzytkownikow, przeprowadza
* uzupelnianie portfela oraz wywoluje panel
* wyboru odpowiednich opcji kantoru. */
class Menu
{
public:
	/** Konstruktor bezargumentowy klasy. */

	Menu();

	/** Destruktor klasy. */

	~Menu();

	/** Funkcja zajmujaca sie panelem rejestracji i logowania, przeprowadza obydwa procesy. */

	void obslugaKont(BazaDanych& baza, Klient& uzytkownik, shared_ptr<Portfel> &portfel);

	/** Funkcja zajmujaca sie opisywaniem przez uzytkownika posiadanych pieniedzy. */

	void uzupelnijPortfel(BazaDanych& baza, Klient& uzytkownik);

	/** Funkcja zajmujaca sie glownymi opcjami kantoru, wywoluje odpowiednie metody kantoru odpowiedzialne za mozliwosci wypisane w konsoli. */

	void obslugujKantor(BazaDanych& baza, Klient& uzytkownik, Kantor& kantor, ofstream &of, ofstream &off);
	
};
#endif
