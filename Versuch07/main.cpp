#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage == 'j')
    {
        do
        {
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            std::cout << "Bitte geben Sie die Daten für den Studenten ein.\nName: ";
            getline(std::cin, name);

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            student = Student(matNr, name, geburtstag, adresse);

            studentenListe.push_back(student);

            std::cout << "Weiteren Studenten hinzufügen? (j/n): ";
            std::cin >> abfrage;
            std::cin.ignore(10, '\n');
        } while (abfrage == 'j');
    }
    else
    {
        studentenListe.push_back(Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1"));
        studentenListe.push_back(Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23"));
        studentenListe.push_back(Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55"));
        studentenListe.push_back(Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12"));
        studentenListe.push_back(Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9"));
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement löschen" << std::endl
                  << "(6): Datenelement vorne hinzufügen" << std::endl
                  << "(7): Daten aus einer Datei einlesen" << std::endl
                  << "(8): Daten in eine Datei sichern" << std::endl
				  << "(9): Datenelemente in aufsteigender Reihenfolge sortieren" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            case '1':
            {
                unsigned int matNr = 0;
                std::string name = "";
                std::string geburtstag = "";
                std::string adresse = "";

                std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                getline(std::cin, name);

                std::cout << "Geburtsdatum: ";
                getline(std::cin, geburtstag);

                std::cout << "Adresse: ";
                getline(std::cin, adresse);

                std::cout << "Matrikelnummer: ";
                std::cin >> matNr;
                std::cin.ignore(10, '\n');

                student = Student(matNr, name, geburtstag, adresse);

                studentenListe.push_back(student);
            }
                break;

            case '2':
            {
                if (!studentenListe.empty())
                {
                    student = studentenListe.front();
                    std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                    student.ausgabe();
                    studentenListe.erase(studentenListe.begin());
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n";
                }
            }
                break;

            case '3':
            {
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (const auto& stud : studentenListe)
                    {
                        stud.ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
            }
                break;

            case '4':
            {
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                    for (auto it = studentenListe.rbegin(); it != studentenListe.rend(); ++it)
                    {
                        it->ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n";
                }
            }
                break;

            case '5':
            {
                unsigned int matNr;
                std::cout << "Geben Sie die Matrikelnummer des zu löschenden Studenten ein: ";
                std::cin >> matNr;
                bool found = false;
                for (auto it = studentenListe.begin(); it != studentenListe.end(); ++it)
                {
                    if (it->getMatNr() == matNr)
                    {
                        studentenListe.erase(it);
                        std::cout << "Student erfolgreich geloescht.\n";
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
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

                std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                getline(std::cin, name);

                std::cout << "Geburtstagsdatum: ";
                getline(std::cin, geburtstag);

                std::cout << "Adresse: ";
                getline(std::cin, adresse);

                std::cout << "Matrikelnummer: ";
                std::cin >> matNr;
                std::cin.ignore(10, '\n');

                student = Student(matNr, name, geburtstag, adresse);
                studentenListe.insert(studentenListe.begin(), student);
            }
                break;

            case '7':
            {
                std::string filename;
                std::cout << "Geben Sie den Dateinamen für das Einlesen an: ";
                getline(std::cin, filename);
                std::ifstream file(filename);
                if (file)
                {
                    studentenListe.clear(); // Bestehende Daten löschen
                    std::string line, name, geburtstag, adresse;
                    unsigned int matNr;

                    try {
                        while (getline(file, line)) // Read Matrikelnummer
                        {
                            if (line.empty()) {
                                continue; // Skip empty lines if any
                            }

                            // Attempt to convert line to integer for Matrikelnummer
                            matNr = std::stoi(line);

                            if (!getline(file, name) || name.empty()) { // Read name
                                std::cerr << "Unexpected end of file or empty name encountered." << std::endl;
                                break;
                            }

                            if (!getline(file, geburtstag) || geburtstag.empty()) { // Read Geburtsdatum
                                std::cerr << "Unexpected end of file or empty birthdate encountered." << std::endl;
                                break;
                            }

                            if (!getline(file, adresse) || adresse.empty()) { // Read Adresse
                                std::cerr << "Unexpected end of file or empty address encountered." << std::endl;
                                break;
                            }

                            studentenListe.push_back(Student(matNr, name, geburtstag, adresse));
                        }
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid number format in file: " << e.what() << std::endl;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Number out of range in file: " << e.what() << std::endl;
                    }

                    file.close();
                    std::cout << "Daten erfolgreich eingelesen.\n";
                }
                else
                {
                    std::cerr << "Datei konnte nicht geöffnet werden.\n";
                }
            }
            break;


            case '8':
            {
                std::string filename;
                std::cout << "Geben Sie den Dateinamen für das Speichern an: ";
                getline(std::cin, filename);
                std::ofstream outFile(filename);
                if (outFile) {
                	for (const auto& stud : studentenListe) {
                		outFile << stud.getMatNr() << std::endl;
                		outFile << stud.getName() << std::endl;
                		outFile << stud.getGeburtstag() << std::endl;
                		outFile << stud.getAdresse() << std::endl;
                	}
                	outFile.close();
                	std::cout << "Daten erfolgreich gesichert.\n";
                } else {
                	std::cout << "Fehler: Datei konnte nicht zum Schreiben geöffnet werden.\n";
                }
            }
                break;

            case '9':
            	std::sort(studentenListe.begin(), studentenListe.end());
            	std::cout << "Sortierte Liste:" << std::endl;
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
