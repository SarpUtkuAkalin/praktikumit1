//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout;
using std::cin;

int main() {
    int iErste = 0;
    int iZweite = 0;

    cout << "Bitte geben Sie die erste Zahl ein: ";
    cin >> iErste;
    cout << "Bitte geben Sie die zweite Zahl ein: ";
    cin >> iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite; // Nachkommawert wird abgeschnitten, da beide Variablen vom Typ int sind

    double dSumme = iErste + iZweite;
    double dQuotient = static_cast<double>(iErste) / iZweite; // Cast nach double, aber nur nach der Division

    double dSummeCast = static_cast<double>(iErste) + static_cast<double>(iZweite);
    double dQuotientCast = static_cast<double>(iErste) / static_cast<double>(iZweite); // Richtige Konvertierung vor der Division

    cout << "Die Summe der beiden Zahlen ist: " << iSumme << std::endl;
    cout << "Der Quotient der beiden Zahlen ist: " << iQuotient << std::endl;
    cout << "Die Summe (vom Typ double) der beiden Zahlen ist: " << dSumme << std::endl;
    cout << "Der Quotient (vom Typ double) der beiden Zahlen ist: " << dQuotient << std::endl;
    cout << "Die Summe (vom Typ double) der beiden (zu double gecasteten) Zahlen ist: " << dSummeCast << std::endl;
    cout << "Der Quotient (vom Typ double) der beiden (zu double gecasteten) Zahlen ist: " << dQuotientCast << std::endl;

    std::string sVorname, sNachname;
    cout << "\nBitte geben Sie Ihren Vornamen ein: ";
    cin >> sVorname;
    cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    cin >> sNachname;

    std::string sVornameName = sVorname + ", " + sNachname;
    cout << "\nIhr Name ist: " << sVornameName << std::endl << std::endl;

    {
        int iFeld[2] = {1, 2};
        cout << "iFeld[0] = " << iFeld[0] << std::endl;
        cout << "iFeld[1] = " << iFeld[1] << std::endl;

        int spielfeld[2][3] = {{1, 2, 3}, {4, 5, 6}};
        cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld[0][2] << std::endl;
        cout << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;

        const int iZweite = 2;  // Lokale Schattenvariable iZweite
        cout << "Lokale iZweite im Block: " << iZweite << std::endl; // Ausgabe: 2
    }
    cout << "Globale iZweite nach dem Block: " << iZweite << std::endl; // Ausgabe: Wert von früherer Eingabe

    cout << "der ASCII Code von " << sVorname[0] << " ist " << (int)sVorname[0] << " und er steht an der " << (int)sVorname[0]%32 << ". Stelle im Alphabet." << std::endl; // Ausgabe: ASCII-Wert des ersten Zeichens des Vornamens
    cout << "der ASCII Code von " << sVorname[1] << " ist " << (int)sVorname[1] << " und er steht an der " << (int)sVorname[1]%32 << ". Stelle im Alphabet." << std::endl; // Ausgabe: ASCII-Wert des zweiten Zeichens des Vornamens

    return 0;
}
