//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */

/**
 * @brief Hinzufügen eines neuen Listenelements am Anfang der Liste
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

    if (empty()) {
        front = back = neuesElement;
    } else {
        front->setPrev(neuesElement);
        neuesElement->setNext(front);
        front = neuesElement;
    }
}

void Liste::popFront()
{
    ListenElement* temp = front; //Temporärer Zeiger auf das erste Element

    if (front == back)                                       // Liste enthält nur ein Listenelement
    {
        delete front;                                        // Listenelement löschen
        front = nullptr;
        back = nullptr;
    }
    else{
        front = front->getNext(); //Verschieben des front-Zeigers auf das zweite Element
    	front->setPrev(nullptr); //Setzen des prev-Zeigers des neuen ersten Elements auf nullptr
    }
    delete temp; //Löschen des ursprünglichen ersten Elements
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;
	while (cursor != nullptr) {
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}
/**
 * @brief Löschen eines Elements basierend auf der Matrikelnummer
 * @param matNr Die Matrikelnummer des zu löschenden Studenten
 * @return bool True, wenn das Element gefunden und gelöscht wurde, sonst False
 */
bool Liste::deleteByMatNr(unsigned int matNr)
{
	ListenElement* cursor = front;
	while (cursor != nullptr) {
		if (cursor->getData().getMatNr() == matNr){
			if (cursor == front) {
				popFront();
			} else {
				cursor->getPrev()->setNext(cursor->getNext());
				if (cursor == back) {
					back = cursor->getPrev();
				} else {
					cursor->getNext()->setPrev(cursor->getPrev());
				}
				delete cursor;
			}
			return true;
		}
		cursor = cursor->getNext();
	}
	return false;
}
