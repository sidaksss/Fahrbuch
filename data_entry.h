// Ziel: Data_Display in OI-System �bernehmen / wie bei der Data Entry
// 2. Ziel Eingabe und Ausgabe �ber Parameter Liste laufen lassen.

#ifndef data_entry_h //f�r include Datei
#define data_entry_h

# define _CRT_SECURE_NO_WARNINGS 


struct data_entry
{
	std::string Vorname;
	std::string Nachname;
	std::string KFZ_Kennzeichen;
	std::string Tankstellen_Name;
	std::string datum;
	float getankte_Liter;
	float gezahlter_Betrag;
	float euro_pro_liter;
};
//int data_entry(data_entry(von der struct)*desptr);
//error code=data_entry(&Eingabe);
//desptr->datum
//variante Pionter dereferenziert (*desptr).datum
//void data_display (data_entry desvar);
int data_entry(float gezahlter_Betrag, float getankte_Liter);
void data_display();
int read_float();
int read_float2();

extern struct data_entry Eingabe;
#endif 