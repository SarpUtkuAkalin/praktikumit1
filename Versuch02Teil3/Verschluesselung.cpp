///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

string verschluesseln(char schluessel[2][26], string wort) {
    string verschluesselt = "";
    for (char c : wort) {
        if (isupper(c)) {
            int index = c - 'A';
            verschluesselt += schluessel[1][index];
        } else {
            verschluesselt += c;  // Nicht-Gro�buchstaben bleiben unver�ndert
        }
    }
    return verschluesselt;
}

string entschluesseln(char schluessel[2][26], string wort) {
    string entschluesselt = "";
    for (char c : wort) {
        if (isupper(c)) {
            for (int i = 0; i < 26; i++) {
                if (schluessel[1][i] == c) {
                    entschluesselt += schluessel[0][i]; // Anh�ngen des entsprechenden Klartextbuchstabens
                    break;
                }
            }
        } else {
            entschluesselt += c; // Nicht-Gro�buchstaben bleiben unver�ndert
        }
    }
    return entschluesselt;
}

int main() {
    char schluessel[2][26];

    // Initialisierung der Schl�sseltabelle
    for (int i = 0; i < 26; i++) {
        schluessel[0][i] = 'A' + i;  // A-Z
    }
    string temp = "QWERTYUIOPLKJHGFDSAZXCVBNM";  // Beispiel f�r eine zuf�llige Reihenfolge
    for (int i = 0; i < 26; i++) {
        schluessel[1][i] = temp[i];
    }

    // Eingabe des Wortes durch den Benutzer
    string wort;
    cout << "Bitte geben Sie ein Wort in Gro�buchstaben ein: ";
    cin >> wort;

    // Verschl�sselung des Wortes
    string verschluesseltesWort = verschluesseln(schluessel, wort);
    cout << "Originalwort: " << wort << endl;
    cout << "Verschl�sseltes Wort: " << verschluesseltesWort << endl;

    // Entschl�sselung des Wortes
    string entschluesseltesWort = entschluesseln(schluessel, verschluesseltesWort);
    cout << "Entschl�sseltes Wort: " << entschluesseltesWort << endl;

    return 0;
}
