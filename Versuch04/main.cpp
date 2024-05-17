//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    std::cout << "Vektor 1:" << std::endl;
    vector1.ausgabe();

    std::cout << "Vektor 2:" << std::endl;
    vector2.ausgabe();

    Vektor ergebnisSub = vector1.sub(vector2);
    std::cout << "Subtraktion von Vektor 1 und Vektor 2:" << std::endl;
    ergebnisSub.ausgabe();

    double skalarErgebnis = vector1.skalarProd(vector2);
    std::cout << "Skalarprodukt von Vektor 1 und Vektor 2:" << skalarErgebnis << std::endl;

    double winkel = vector1.winkel(vector2);
    std::cout << "Winkel zwischen Vektor 1 und Vektor 2:" << winkel << "Grad" << std::endl;

    std::cout << "Vektor 1 nach der Rotation um PI/4 Radian um die Z-Achse:" << std::endl;
    vector1.rotiereUmZ(M_PI/4);
    vector1.ausgabe();

    //Berechnung zur Horizontdistanz

    const double erdRadius = 6371000.0; // Erdradius in Metern
        const double platformHöhe = 555.7; // Höhe der Plattform in Metern
        double personHöhe = 1.70; // Höhe der Person in Metern

        // Gesamthöhe von der Meeresoberfläche
        double totalHöhe = platformHöhe + personHöhe;
        double beobachterRadius = erdRadius + totalHöhe; // Radius vom Mittelpunkt zur Beobachtungsposition

        double dx = 0.1; // kleinerer Schritt in Metern für präzisere Berechnungen
        double distanz = 0.0;
        double x = 0.0; // aktuelle horizontale Distanz
        double y = beobachterRadius; // aktuelle vertikale Position
        int schritte = 0; // Schrittzähler

        // Simuliere die Bewegung
        while (y > erdRadius) {
            x += dx;
            schritte++;
            y = sqrt(beobachterRadius * beobachterRadius - x * x);
            if (y <= erdRadius) {
                distanz = x;
                break;
            }
        }

        // Berechnung des Winkels Beta
        double winkelBeta = atan2(totalHöhe, distanz) * (180.0 / M_PI);  // Dieser Winkel wird jetzt korrekt berechnet

        // Ausgabe der formatierten Ergebnisse
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Sie können " << distanz / 1000.0 << " Km weit sehen." << std::endl;
        std::cout << "Sie sind " << totalHöhe << " Meter hoch." << std::endl;
        std::cout << "Der Winkel beträgt " << winkelBeta << " Grad." << std::endl;
        std::cout << "Anzahl Schritte: " << schritte << std::endl;

    return 0;

}
