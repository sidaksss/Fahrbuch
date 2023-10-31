# define _CRT_SECURE_NO_WARNINGS
# include "iostream"
#include <sstream>
#include <limits>
#include <vector>
#include <fstream>
#include "data_entry.h"
float User_eingabe;
float User_eingabe2;

int data_entry(float gezahlter_Betrag , float getankte_Liter)
{
	
	//Dateneingabe
	system("CLS");
	std::cout << "Bitte geben Sie den Namen des Fahrers ein:" << std::endl;
	std::cout << "\n\nVorname: ";
	std::cin >> Eingabe.Vorname;
	std::cout << "Nachname: ";
	std::cin >> Eingabe.Nachname;
	std::cout << "\n\nBitte geben Sie das KFZ Kennzeichen ein:								Bsp.: MKGG23E" << std::endl;
	std::cout << "\n\nKennzeichen: ";
	std::cin >> Eingabe.KFZ_Kennzeichen;
	std::cout << "\n\nBitte geben Sie die getankten Liter und den bezahlten Betrag ein (statt Komma -> Punkt setzen):		Bsp.:75.54" << std::endl;
	std::cout << "(statt Komma -> Punkt setzen)" << std::endl;
	std::cout << "\n\nLiter: ";
	std::cin >> User_eingabe;
	read_float();
	std::cout << "Betrag: ";
	std::cin >> User_eingabe2;
	read_float2();
	std::cout << "\n\nBitte geben Sie noch das Datum (Format dd.mm.yyyy) und den Namen der Tankstelle ein:			Bsp.: 01.03.2001" << std::endl;
	std::cout << "\n\nDatum: ";
	std::cin >> Eingabe.datum;
	std::cout << "Name der Tankstelle: ";
	std::cin >> Eingabe.Tankstellen_Name;

	gezahlter_Betrag = Eingabe.gezahlter_Betrag;
	getankte_Liter = Eingabe.getankte_Liter;

	return(Eingabe.euro_pro_liter = Eingabe.gezahlter_Betrag / Eingabe.getankte_Liter);
}

int read_float() {
	if (User_eingabe < 3 || User_eingabe > 100) {
		do {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nBitte gib einen Wert zwichen 3 und 100 ein.\n";
			std::cout << "Liter: ";
			std::cin >> User_eingabe;
			std::cout << "\n";
		} while (User_eingabe < 3 || User_eingabe > 100);
	}
	return(Eingabe.getankte_Liter = User_eingabe);
}

int read_float2() {
	if (User_eingabe2 < User_eingabe * 1.5 || User_eingabe2 > User_eingabe * 3) {
		do {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nBitte gib einen Wert zwichen 3 und 100 ein.\n";
			std::cout << "Betrag: ";
			std::cin >> User_eingabe2;
			std::cout << "\n";
		} while (User_eingabe2 < User_eingabe * 1.5 || User_eingabe2 > User_eingabe * 3);
	}
	return(Eingabe.gezahlter_Betrag = User_eingabe2);
}