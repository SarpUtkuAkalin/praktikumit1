//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	if(n == 1){
		return 1;
	}
	int previousFib = 0; //Starte mit f(0)
	int currentFib = 1; //Starte mit f(1)
	for(int i = 2; i<=n; i++){
		int newFib = previousFib + currentFib; //Berechnet die nächste Fibonacci-Zahl
		previousFib = currentFib; //Aktualisiert previousFib zur alten currentFib
		currentFib = newFib; //Aktualisiert currentFib zum neu berechneten Wert
	}
	return currentFib; //Gibt die n-te Fibonacci-Zahl zurück
}

int main(){
	std::cout << "Fibonacci-Zahlen von 0 bis 12:" << std::endl;
	for (int i = 0; i <= 12; i++){
		std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
	}
	return 0;
}
