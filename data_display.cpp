# define _CRT_SECURE_NO_WARNINGS
# include "iostream"
#include "data_entry.h"
# include "windows.h"



const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char ss = static_cast<unsigned char>(225);

void data_display()
{
	//eingegebe Daten werden visualisiert für den User zur letzen Prüfung
	system("CLS");
	std::cout << "Ihre Eingaben:" << std::endl;

	int i = 20;									// maximale Stellen der Vor- und Nachnamen
	int j = 12;									// maximale Stellen für den Rest außer datum

	std::cout << "\nIhre Eingaben:" << std::endl;
	std::cout << "+--------------------+--------------------+------------+------------+------------+----------+------------+" << std::endl;
	std::cout << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Vorname" << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Nachname" << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << "Kennzeichen" << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << "Liter [l]" << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << "Betrag [EUR]" << "|";
	std::cout.width(10);
	std::cout.fill(' ');
	std::cout << std::left << "Datum" << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << "Tankstelle" << "|" << std::endl;
	std::cout << "+--------------------+--------------------+------------+------------+------------+----------+------------+" << std::endl;
	std::cout << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << Eingabe.Vorname << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << Eingabe.Nachname << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << Eingabe.KFZ_Kennzeichen << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << Eingabe.getankte_Liter << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << Eingabe.gezahlter_Betrag << "|";
	std::cout.width(10);
	std::cout.fill(' ');
	std::cout << std::left << Eingabe.datum << "|";
	std::cout.width(j);
	std::cout.fill(' ');
	std::cout << std::left << Eingabe.Tankstellen_Name << "|" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Berechnete Gr" << oe << ss << "e:" << std::endl;
	std::cout << "				Euro pro Liter: ";
	std::cout << Eingabe.euro_pro_liter << " ";
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"€\n", wcslen(L"€\n"), NULL, NULL);   //stellt das €-Symbol dar
	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "M" << oe << "chten Sie ihre Eingaben speichern?\n" << std::endl;
	std::cout << "				+-----01-----+			+-----02-----+" << std::endl;
	std::cout << "				|     ja     |			|    nein    |" << std::endl;
	std::cout << "				+------------+			+------------+" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Eingabe der Zahl: ";

	
}