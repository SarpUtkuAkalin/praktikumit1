/**
 * Praktikum Informatik 1
 *
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"

/**
 * @brief Initialisiert das Spielfeld mit den Startpositionen der Steine.
 * @param spielfeld Zweidimensionales Array, das das Spielfeld repräsentiert.
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X]) {
    for (int j = 0; j < GROESSE_Y; j++) {
        for (int i = 0; i < GROESSE_X; i++) {
            spielfeld[j][i] = 0;
        }
    }
    // Setzen der Startsteine
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i) {
        std::cout << (char)i << " | ";
    }
    std::cout << std::endl;
    for (int j = 0; j < GROESSE_Y; ++j) {
        for (int i = 0; i < GROESSE_X; ++i) {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;
        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i) {
            switch (spielfeld[j][i]) {
                case 0:
                    std::cout << "   ";
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        }; //for i
        std::cout << std::endl;
    } 	//for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY) {
    return (posX >= 0 && posX < GROESSE_X && posY >= 0 && posY < GROESSE_Y);
}

/**
 * @brief Überprüft, ob der Zug an der angegebenen Position gültig ist.
 * @param spielfeld Das aktuelle Spielfeld.
 * @param aktuellerSpieler Der Spieler, der den Zug macht.
 * @param posX Spaltenindex des Zuges.
 * @param posY Zeilenindex des Zuges.
 * @return Wahr, wenn der Zug gültig ist, sonst falsch.
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY) {
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1
    if (spielfeld[posY][posX] != 0) return false; // ist das Feld leer
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            if (i == 0 && j == 0) continue; // Überspringe das aktuelle Feld
            int x = posX + i, y = posY + j;
            bool found_opponent = false;
            while (aufSpielfeld(x, y) && spielfeld[y][x] == gegner) {
                found_opponent = true;
                x += i;
                y += j;
            }
            if (found_opponent && aufSpielfeld(x, y) && spielfeld[y][x] == aktuellerSpieler) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Führt einen Zug aus und ändert entsprechend die Steine auf dem Spielfeld.
 * @param spielfeld Das aktuelle Spielfeld.
 * @param aktuellerSpieler Der Spieler, der den Zug macht.
 * @param posX Spaltenindex des Zuges.
 * @param posY Zeilenindex des Zuges.
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY) {
    int gegner = 3 - aktuellerSpieler;
    if (!zugGueltig(spielfeld, aktuellerSpieler, posX, posY)) return;
    spielfeld[posY][posX] = aktuellerSpieler; // Setze den Stein des Spielers
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            if (i == 0 && j == 0) continue;
            int x = posX + i, y = posY + j;
            int count = 0;
            while (aufSpielfeld(x, y) && spielfeld[y][x] == gegner) {
                count++;
                x += i;
                y += j;
            }
            if (count > 0 && aufSpielfeld(x, y) && spielfeld[y][x] == aktuellerSpieler) {
                for (int k = 1; k <= count; k++) {
                    x -= i;
                    y -= j;
                    spielfeld[y][x] = aktuellerSpieler;
                }
            }
        }
    }
}

/**
 * @brief Berechnet die Anzahl der möglichen Züge für den angegebenen Spieler.
 * @param spielfeld Das aktuelle Spielfeld.
 * @param aktuellerSpieler Der Spieler, dessen Züge gezählt werden.
 * @return Anzahl der möglichen Züge.
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler) {
    int count = 0;
    for (int j = 0; j < GROESSE_Y; j++) {
        for (int i = 0; i < GROESSE_X; i++) {
            if (zugGueltig(spielfeld, aktuellerSpieler, i, j)) {
                count++;
            }
        }
    }
    return count;
}

/**
 * @brief Ermöglicht einem menschlichen Spieler, einen Zug zu machen.
 * @param spielfeld Das aktuelle Spielfeld.
 * @param aktuellerSpieler Der Spieler, der an der Reihe ist.
 * @return Wahr, wenn ein Zug gemacht wurde, sonst falsch.
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


/**
 * @brief Führt das Spiel zwischen zwei Spielern durch.
 * @param spielerTyp Array, das den Typ jedes Spielers angibt (Mensch oder Computer).
 */
void spielen(const int spielerTyp[2]) {
    int spielfeld[GROESSE_Y][GROESSE_X];
    initialisiereSpielfeld(spielfeld);
    int aktuellerSpieler = 1;
    int rundenZaehler = 1;

    zeigeSpielfeld(spielfeld);

    while (moeglicheZuege(spielfeld, aktuellerSpieler) > 0 || moeglicheZuege(spielfeld, 3 - aktuellerSpieler) > 0) {
        if (moeglicheZuege(spielfeld, aktuellerSpieler) > 0) {
        	std::cout << "Runde " << rundenZaehler << ": Spieler" << aktuellerSpieler << " ist am Zug." << std::endl;
            switch (spielerTyp[aktuellerSpieler - 1]) {
                case MENSCH:
                    menschlicherZug(spielfeld, aktuellerSpieler);
                    break;
                case COMPUTER:
                    computerZug(spielfeld, aktuellerSpieler);
                    break;
            }
            zeigeSpielfeld(spielfeld);
            rundenZaehler++;
        }
        aktuellerSpieler = 3 - aktuellerSpieler;
    }

    switch (gewinner(spielfeld)) {
        case 0:
            std::cout << "Unentschieden!" << std::endl;
            break;
        case 1:
            std::cout << "Spieler 1 hat gewonnen!" << std::endl;
            break;
        case 2:
            std::cout << "Spieler 2 hat gewonnen!" << std::endl;
            break;
        default:
            std::cout << "Unzulässige Daten im Spielfeld!" << std::endl;
            std::cout << "Abbruch ..." << std::endl;
            exit(0);
    }
}

/**
 * @brief Hauptfunktion, führt Tests durch und startet das Spiel.
 * @return Beendet das Programm mit einem Code.
 */
int main() {
    if (TEST == 1) {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis) {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        } else {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl;
    }

    int spielerTyp[2];
    std::cout << "Geben Sie den Typ für Spieler 1 ein (1 für Mensch, 2 für Computer): ";
    std::cin >> spielerTyp[0];
    std::cout << "Geben Sie den Typ für Spieler 2 ein (1 für Mensch, 2 für Computer): ";
    std::cin >> spielerTyp[1];

    spielen(spielerTyp);
    return 0;
}
