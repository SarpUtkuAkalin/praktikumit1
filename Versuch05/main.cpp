/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>

#include "Liste.h"
#include "Student.h"

int main()
{
    Liste studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage == 'j')
    {
    	//Nutzer gibt Studenten manuell ein
    	do
    	{
    		unsigned int matNr = 0;
    		std::string name = "";
    		std::string geburtstag = "";
    		std::string adresse = "";

    		std::cout << "Bitte geben Sie die Daten f�r den Studenten ein.\nName: ";
    		getline(std::cin, name);

    		std::cout << "Geburtsdatum: ";
    		getline(std::cin, geburtstag);

    		std::cout << "Adresse: ";
    		getline(std::cin, adresse);

    		std::cout << "Matrikelnummer: ";
    		std::cin >> matNr;
    		std::cin.ignore(10, '\n');

    		student = Student(matNr, name, geburtstag, adresse);

    		studentenListe.pushBack(student);

    		std::cout << "Weiteren Studenten hinzuf�gen? (j/n): ";
    		std::cin >> abfrage;
    		std::cin.ignore(10, '\n');
    	} while (abfrage == 'j');
    }
    else
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.pushBack(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.pushBack(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.pushBack(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.pushBack(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.pushBack(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
        		  << "(5): Datenelement l�schen" << std::endl
				  << "(6): Datenelement vorne hinzuf�gen" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.pushBack(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.dataFront();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.popFront();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    studentenListe.ausgabeVorwaerts();
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            case '4':
            	if(!studentenListe.empty())
            	{
            		std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
            		studentenListe.ausgabeRueckwaerts();
            	}
            	else
            	{
            		std::cout << "Die Liste ist leer!\n";
            	}
            	break;

            case '5':
            {
            	unsigned int matNr;
            	std::cout << "Geben Sie die Matrikelnummer des zu l�schenden Studenten ein: ";
            	std::cin >> matNr;
            	if(studentenListe.deleteByMatNr(matNr)) {
            		std::cout << "Student erfolgreich geloescht.\n";
            	} else {
            		std::cout << "Student nicht gefunden oder Liste ist leer.\n";
            	}
            }
            	break;
            case '6':
            {
            	unsigned int matNr = 0;
            	std::string name = "";
            	std::string geburtstag = "";
            	std::string adresse = "";

            	std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
            	getline(std::cin, name);

            	std::cout << "Geburtstagsdatum: ";
            	getline(std::cin, geburtstag);

            	std::cout << "Adresse: ";
            	getline(std::cin, adresse);

            	std::cout << "Matrikelnummer: ";
            	std::cin >> matNr;
            	std::cin.ignore(10, '\n');

            	student = Student(matNr, name, geburtstag, adresse);
            	studentenListe.pushFront(student);
            }
            	break;

            case '0':
            	std::cout << "Das Programm wird nun beendet.\n";
            	break;

            default:
            	std::cout << "Falsche Eingabe, bitte nochmal versuchen.\n";
            	break;
        }
    }
    while (abfrage != '0');

    return 0;
}
