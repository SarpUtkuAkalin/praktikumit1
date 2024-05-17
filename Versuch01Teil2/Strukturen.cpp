/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Person{

	string sNachname;
	string sVorname;
	int iGeburtsjahr;
	int iAlter;
};

int main()
{
	Person nBenutzer; //Variable vom Typ Person
    //Benutzereingaben anfordern
	cout << "Bitte geben Sie Ihren Vornamen ein: ";
	cin >> nBenutzer.sVorname;
	cout << "Bitte geben Sie Ihren Nachnamen ein: ";
	cin >> nBenutzer.sNachname;
	cout << "Bitte geben Sie Ihr Geburtsjahr ein: ";
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Bitte geben Sie Ihr Alter ein: ";
	cin >> nBenutzer.iAlter;

	//Ausgabe der Personendaten
	cout << "\nSie haben eingegeben:\n";
	cout << "Vorname: " << nBenutzer.sVorname << endl;
	cout << "Nachname: " << nBenutzer.sNachname << endl;
	cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << endl;
	cout << "Alter: " << nBenutzer.iAlter << endl;

	//Kopieren des Inhalts von nBenutzer in nKopieEinzeln, Element für Element
	Person nKopieEinzeln;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	//Kopieren der gesamten Inhalts von nBenutzer in nKopieGesamt
	Person nKopieGesamt = nBenutzer;

	//Ausgabe der kopierten Daten
	cout << "\nKopierte Daten (einzelne Elemente):\n";
	cout << "Vorname: " << nKopieEinzeln.sVorname << endl;
	cout << "Nachname: " << nKopieEinzeln.sNachname << endl;
	cout << "Geburtsjahr: " <<nKopieEinzeln.iGeburtsjahr << endl;
	cout << "Alter: " << nKopieEinzeln.iAlter << endl;

	cout << "\nKopierte Daten (gesamte Struktur):\n";
	cout << "Vorname: " << nKopieGesamt.sVorname << endl;
	cout << "Nachname: " << nKopieGesamt.sNachname << endl;
	cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << endl;
	cout << "Alter: " << nKopieGesamt.iAlter << endl;
	return 0;

}
