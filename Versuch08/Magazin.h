#include "Medium.h"
#include "Datum.h"
#include <string>

class Magazin : public Medium
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /**
     * @brief Ausgabefunktion
     * Überladene Funktion aus Medium
    */
    void ausgabe() const;

    /**
     * @brief Ausleihen-Funktion
     *
     * @param person Person die das Medium ausleihen möchte.
     * @param ausleihdatum Datum an dem das Medium ausgeliehen wird.
     *
     * @return true, wenn die Ausleihbeschränkungen erfüllt sind und das Medium ausgeliehen werden kann.
    */
    bool ausleihen(Person person, Datum ausleihdatum);

private:
    Datum datumAusgabe;
    std::string sparte;
};
