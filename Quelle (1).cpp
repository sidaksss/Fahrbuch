 # define _CRT_SECURE_NO_WARNINGS
/*
Informatik Beleg Fahrtenbuch



#######################################################################
Standard-/Basisaufgabe: „Fahrtenbuch“
#######################################################################

Anforderungen:
		> keine Lösung auf Papier, keine Formulare, kein Excel, keine eigene Hardware, sondern….
		> Software auf PC unter Windows, der Einfachheit halber Konsolenanwendung, Windows 7 ff.

Input der Tankstellen-Kassenquittung („Rechnung“):
		> Namen des Fahrers
		> Kfz-Kennzeichen
		> getankte Liter
		> gezahlter Betrag
		> optional: Datum, Name der Tankstelle….

Berechnete Größen, auch als Ausgabe auf Konsole:
		> Kosten Eur/Liter
		> Durchschnittsverbrauch bis zum aktuellen Tankstopp in Eur/Liter

Gesamtausgabe:
		> alle Eingabegrößen incl. berechneter Größen

#######################################################################
Erweiterung der Standard-/Basisaufgabe
#######################################################################

Anforderungen:
		> Import/Export von Excel Tabellen
		> Erstellung von Fahrerprofilen 
		> Fehleranalyse
		> vereinfachte Menüführung
*/



# include "stdio.h"
# include "stdlib.h"
# include "iostream"
# include "iomanip"
# include "windows.h"
# include "string.h"
# include "fstream"
# include "string"
# include "vector"
# include "conio.h"
#include <iostream>
# include "data_entry.h"

// Umlaute:
const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

//Dateneingabevariablen:




//zu berechnende Variablen
float durchschnittsverbrauch = 0.0;

//Zählvariablen:
int Auswahl = 0;
int Auswahl2 = 0;

//Zwischenspeicherer
std::string Liter = "";
std::string Betrag = "";
std::string str_euro_pro_liter = "";

//Variablen für externe Speicherung in daten.txt
std::string filename("daten.txt");
std::fstream outfile;
std::string text("\n"); //erzeugt Zeilenumbrüche in daten.txt Datei


//Funktionen:
void firstpage();
int data_entry(float gezahlter_Betrag, float getankte_Liter);

void display();

struct data_entry Eingabe;

int main()

//Menüführung über zwei do-while-Schleifen mit den jewaligen Funktionsaufrufen
{

	
	do {
		firstpage();
		std::cin >> Auswahl;
		switch (Auswahl)
		{
		case 1:
			std::cout << "\n";
			//dateneingabe
			data_entry(Eingabe.gezahlter_Betrag,Eingabe.getankte_Liter);
			//berechnung euro pro liter
			

			//Anzeige der eingegeben Daten
			data_display();
			do
			{
				std::cin >> Auswahl2;
				switch (Auswahl2)
				{
				case 1:
					//speichern der Eingaben
					system("CLS");
					std::cout << "Speichere ihre eingegeben Eingaben" << std::endl;

					//aus den Float-Eingaben werden Strings zur einfacheren Speicherung gemacht
					Liter += std::to_string(Eingabe.getankte_Liter);
					Betrag += std::to_string(Eingabe.gezahlter_Betrag);
					str_euro_pro_liter += std::to_string(Eingabe.euro_pro_liter);

					//öffnet Daten.txt
					outfile.open(filename, std::ios_base::app);
					if (!outfile.is_open()) {
						std::cerr << "Fehler beim " << oe << "ffnen" << filename << '\n';
					}
					else {
						//schreibt Zeilenweise alle Eingaben in die Datei
						outfile.write(Eingabe.Vorname.data(), Eingabe.Vorname.size());
						outfile.write(text.data(), text.size());
						outfile.write(Eingabe.Nachname.data(), Eingabe.Nachname.size());
						outfile.write(text.data(), text.size());
						outfile.write(Eingabe.KFZ_Kennzeichen.data(), Eingabe.KFZ_Kennzeichen.size());
						outfile.write(text.data(), text.size());
						outfile.write(Liter.data(), Liter.size());
						outfile.write(text.data(), text.size());
						outfile.write(Betrag.data(), Betrag.size());
						outfile.write(text.data(), text.size());
						outfile.write(Eingabe.datum.data(), Eingabe.datum.size());
						outfile.write(text.data(), text.size());
						outfile.write(Eingabe.Tankstellen_Name.data(), Eingabe.Tankstellen_Name.size());
						outfile.write(text.data(), text.size());
						outfile.write(str_euro_pro_liter.data(), str_euro_pro_liter.size());
						outfile.write(text.data(), text.size());
						std::cerr << "Erfolgreich gespeichert!" << std::endl;
						outfile.close();
						
					}

					// Nullsetzen der Zwischenspeicherer string und float
					Liter = "";
					Betrag = "";
					str_euro_pro_liter = "";
					
					Eingabe.getankte_Liter = 0.0;
					Eingabe.gezahlter_Betrag = 0.0;
					Eingabe.euro_pro_liter = 0.0;

					std::cout << "\n" << std::endl;
					std::cout << "\n" << std::endl;
					std::cout << "Dr" << ue << "cke eine beliebige Taste um zur" << ue << "ck zum Hauptmen" << ue << " zu gelangen\n" << std::endl;
					break;

				case 2:
					//löschen
					system("cls");
					std::cout << "L" << oe << "schvorgang gestartet" << std::endl;
					std::cout << ".";
					Sleep(400);
					std::cout << ".";
					Sleep(400);
					std::cout << ".";
					Sleep(400);
					std::cout << ".";
					Sleep(400);
					std::cout << std::endl;

					//setzt alle Zwischenspeichervariabeln auf Anfangszustand
					Eingabe.Vorname = "";
					Eingabe.Nachname = "";
					Eingabe.KFZ_Kennzeichen = "";
					Eingabe.Tankstellen_Name = "";
					Eingabe.datum = "";
					Eingabe.getankte_Liter = 0.0;
					Eingabe.gezahlter_Betrag = 0.0;
					Eingabe.euro_pro_liter = 0.0;

					std::cout << "Alle Eingaben wurden zur"<< ue <<"ckgesetzt" << std::endl;
					std::cout << "\n" << std::endl;
					std::cout << "\n" << std::endl;
					std::cout << "Dr" << ue << "cke eine beliebige Taste um zur" << ue << "ck zum Hauptmen" << ue << " zu gelangen\n" << std::endl;
					break;
				default:
					std::cout << "keine korrekte Eingabe";
					break;
				}
			} while (Auswahl != 1 && Auswahl != 2);
			break;
		case 2:
			std::cout << "\n";
			//datenanzeige
			display();
			std::cout << "\n" << std::endl;
			std::cout << "\n" << std::endl;
			std::cout << "Dr" << ue << "cke eine beliebige Taste um zur" << ue << "ck zum Hauptmen" << ue << " zu gelangen\n" << std::endl;
			break;
		case 3:
			system("cls");
			std::cout << "Beenden wird ausgef"<< ue <<"hrt"<<std::endl;
			return(0);
			break;
		default:
			std::cout << "keine korrekte Eingabe";
			break;
		}
		_getch();
		system("cls");

	} while (Auswahl != 3);

	std::cin.ignore();
	return(0);
} 


void firstpage()
{
	// Titelseite
	system("CLS");
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "########## ########## ##      ## ########   ########## ########## ####    ## #########  ##      ##    #####   ##      ##\n";
	std::cout << "########## ########## ##      ## ##     ##  ########## ########## ####    ## #########  ##      ##  ##    ##  ##      ##\n";
	std::cout << "##         ##      ## ##      ## ##     ##      ##     ##         ## ##   ## ##      ## ##      ## ##      ## ##      ##\n";
	std::cout << "##         ##      ## ##      ## ##     ##      ##     ##         ## ##   ## ##      ## ##      ## ##      ## ##      ##\n";
	std::cout << "#######    ##      ## ##      ## ##     ##      ##     ##         ##  ##  ## ##    ##   ##      ## ##         ##      ##\n";
	std::cout << "#######    ##      ## ########## ########       ##     ########## ##  ##  ## ########   ##      ## ##         ##########\n";
	std::cout << "##         ########## ########## ########       ##     ########## ##   ## ## ########   ##      ## ##         ##########\n";
	std::cout << "##         ########## ##      ## ##     ##      ##     ##         ##   ## ## ##    ##   ##      ## ##         ##      ##\n";
	std::cout << "##         ##      ## ##      ## ##      ##     ##     ##         ##    #### ##      ## ##      ## ##      ## ##      ##\n";
	std::cout << "##         ##      ## ##      ## ##      ##     ##     ##         ##    #### ##      ## ##      ## ##      ## ##      ##\n";
	std::cout << "##         ##      ## ##      ## ##      ##     ##     ########## ##      ## #########   ########   ##    ##  ##      ##\n";
	std::cout << "##         ##      ## ##      ## ##      ##     ##     ########## ##      ## #########    ######      #####   ##      ##\n";
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Bitte w"<<ae<<"hlen Sie "<<ue<<"ber die Eingabe einer Zahl den jeweiligen Men"<<ue<<"punkt aus\n" << std::endl;
	std::cout << "		+-----01-----+		+-----02-----+		+-----03-----+" << std::endl;
	std::cout << "		|Dateneingabe|		|Datenanzeige|		|Beenden     |" << std::endl;
	std::cout << "		+------------+		+------------+		+------------+" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Eingabe der Zahl: ";
}





void display() {
	//Datendarstellung aller gespeicherten Daten in Daten.txt
	system("CLS");
	std::cout << OE  << "ffne Datei" << std::endl;

	std::string filename("daten.txt");
	std::ifstream input(filename);

	std::cout << ".";
	Sleep(700);
	std::cout << ".";
	Sleep(700);
	std::cout << ".";
	Sleep(700);

	if (!input)
	{
		std::cerr << "				--> " << "Keine Eintr" << ae << "ge beim " << oe << "ffnen der Datei '" << filename << "'" << " <--" << "\n";
	}
	std::cout << std::endl;
	std::cout << "Erfolgreich ge" << oe << "ffnet" << std::endl;
	std::cout << ".";
	Sleep(700);
	std::cout << ".";
	Sleep(700);
	std::cout << ".";
	Sleep(700);
	system("CLS");
	std::cout << "Gespeicherte Daten:" << std::endl;
	std::cout << "(limitiert auf die letzten 10)" << std::endl;

	int i = 25;									// maximale Stellen der Vor- und Nachnamen
	std::cout << "+---------------+---------------+---------------+---------------+---------------+---------------+---------------+" << std::endl;
	std::cout << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Vorname" << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Nachname" << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Kennzeichen" << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Liter [l]" << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Betrag [EUR]" << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Datum" << "|";
	std::cout.width(i);
	std::cout.fill(' ');
	std::cout << std::left << "Tankstelle" << "|" << std::endl;
	std::cout << "+---------------+---------------+---------------+---------------+---------------+---------------+---------------+" << std::endl;
	std::cout << "|";

	std::string line;

	//q ist die Zählvariable für die Anzeige der tabelle und w ist die Zählvariable für die berechnung von euro_pro_liter
	int q = 0, w = 0; 

	//Variable zur lokale Berechnung für die Anzeige euro_pro_liter
	float display_Durschnissverbrauch = 0.0;

	//Einlesen der Speicherdatei "daten.txt" und Zeilenweises auslesen / darstellen
	while (std::getline(input, line))
	{		
		q++;
		if (q == 8 || q == 17 || q == 26 || q == 35 || q == 44 || q == 53 || q == 62 || q == 71 || q == 80 || q == 89) {
			float wert;
			sscanf(line.c_str(), "%f", &wert);
			display_Durschnissverbrauch = display_Durschnissverbrauch + wert;
			std::cout << std::endl;
			std::cout << "|";
			q++;
			w++;
		}
		else {
			std::cout.width(i);
			std::cout.fill(' ');
			std::cout << std::left << line << "|";
		}
	}
	std::cout << "\n" << std::endl;
	std::cout << "Durchschnitzkosten pro liter: ";
	std::cout << display_Durschnissverbrauch / w << " ";
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"€\n", wcslen(L"€\n"), NULL, NULL);
	std::cout << std::endl;

}
