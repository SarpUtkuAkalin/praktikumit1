//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung

    void pushBack(Student pData);
    void pushFront(Student pData); //Hinzufügen eines Elements am Anfang der Liste
    void popFront();
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const; //Ausgabe der Liste von hinten nach vorne
    bool deleteByMatNr(unsigned int MatNr);

    void clear(); //Hilfsmethode zur Bereinigung der Liste
};

#endif /*LISTE_H_*/
