// Nom script : phm_ds1302_serial_hard 
// Creation : Le 03 06 2016
// Description : Initialisation date/heure puis boucle affichage
// Inspiré du script suivant :
// DS1302_Serial_Hard (C)2010 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// Les connections suivantes doivent être effectuées DS1302.
// DS1302 patte RST  -> Arduino Digital 18
// DS1302 patte DATA -> Arduino Digital 17
// DS1302 patte CLK  -> Arduino Digital 16

#include <DS1302.h>

// Init DS1302
DS1302 rtc(12, 14, 27);

// Init structure Time-data
Time t;

void setup()
{
  // Positionnement horloge a run-mode et desactive protection en ecriture
  rtc.halt(false);
  rtc.writeProtect(false);
  
  // Init connection serie
  Serial.begin(9600);

  // Initialisation de l'horloge
  // A mettre a jour avec les bones valeurs pour initialiser l horloge RTC DS1302
  //rtc.setDOW(THURSDAY);        // Jour a FRIDAY
  rtc.setTime(19, 10, 0);    // Heure a 19:10:00 (format sur 24 heure)
  rtc.setDate(6, 9, 2003);   // Date  au jour moi année
}

void loop()
{
  // recup donnees DS1302
  t = rtc.getTime();
  
  // Ecriture date sur console serie
  Serial.print("Jour : ");
  Serial.print(t.date, DEC);
  Serial.print(" - Mois : ");
  Serial.print(rtc.getMonthStr());
  Serial.print(" - Annee : ");
  Serial.print(t.year, DEC);
  Serial.println(" -");
  
  // Ecriture heure sur console serie
  Serial.print("C est le ");
  Serial.print(t.dow, DEC);
  Serial.print(" ieme jour de la semaine (avec lundi le premier), et il est ");
  Serial.print(t.hour, DEC);
  Serial.print(" heures, ");
  Serial.print(t.min, DEC);
  Serial.print(" minutes ");
  Serial.print(t.sec, DEC);
  Serial.println(" secondes.");

  // Affichage d un separateur
  Serial.println("------------------------------------------");
  
  // Attente d une seconde avant lecture suivante :)
  delay (1000);
}
