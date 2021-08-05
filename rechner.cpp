#include <iostream> //wird für CIN und COUT benötigt
#include <tchar.h>
#include "math.h"
//#include "BigInt.hpp"

using namespace std; //Die normale Klassenschreibweise std::cin wird nun abgekürzt mit cin



double zahleingeben()
{
     double dzahl2;
     cout << "Bitte geben Sie die zweite Zahl ein: ";
     cin >> dzahl2;
     return dzahl2;
}

//Hauptprogramm
 int _tmain(int argc, _TCHAR* argv[]) 
{
     //Hauptprogrammablauf nach Schema EVA
     //Variablendeklaration und Initialisierung
     //(Deklaration=Anlage;Initialisierung=Ersten Wert setzen)
     bool bweiter=true; //Kennzeichnung, ob erneuter Programmdurchlauf oder Ende
     int ieingabemodus=0;
     char cantwort=' '; //Einzelzeichen werden mit einfachen ',
                        //Zeichenketten mit " Zeichen dargestellt
     double dzahl1=0; //Variablen werden immer initialisiert!!!
     double dzahl2=0;
     char coperator=' ';
     double dergebnis=0;
    
     do //Wiederholung des Programms, bis Benutzer das Ende wünscht
     {
         //E-ingabe
         //Begrüßung
         cout << "*******************************************************\n";
         // \n bedeutet ein Zeilenumbruch
         cout << "Herzlich Willkommen bei meinem ersten Taschenrechner!\n";
         cout << "*******************************************************\n\n";
        
         //Wir fragen den Nutzer, ob er Einzeleingaben oder eine natürliche Eingabe machen möchte
         cout << "Moechten Sie die Eingabe mit Einzelwerten (1)\n";
         cout << "oder eine natuerliche Eingabe (2)\n";
         cout << "oder einer Fakultaet vornehmen? (3) ";
         cin >> ieingabemodus;
        
         // || ist eine OR Verknüpfung
         while (ieingabemodus >= 4 || ieingabemodus <= 0)
         {
             cout << "Bitte machen Sie eine korrekte Angabe (Moegliche Eingaben 1 bis 3): ";
             cin >> ieingabemodus;
         }
         //Unterscheidung der 2 Eingabemöglichkeiten
         if (ieingabemodus==1)
         {
             //Einzelwertemodus
             cout << "Bitte geben Sie die erste Zahl ein: ";
             cin >> dzahl1;
            
            //Rechenart abfragen
             do
             {
                 cout << "Bitte eine Rechenart eingeben. Moegliche Eingaben sind +, -, *, /, !: ";
                 cin >> coperator;
             } while(coperator!='+' && coperator!='-' && coperator!='*' && coperator!='/' && coperator!='!');

             //Alternative Eingabe über eine Funktion / Unterprogramm
             //cout << "Bitte geben Sie die zweite Zahl ein: ";
             //cin >> dzahl2;

             if(coperator!='!') {
                dzahl2 = zahleingeben();
             }
            
             
            
         }
         else if (ieingabemodus==2)//ieingabemodus
         {
             //Optionale natürliche Eingabe
             cout << "Bitte geben Sie die durchzufuehrende Berechnung wie folgt ein (5+7): ";
             //Einlesen der einzelnen Eingabeströme in separate Variablen
             cin >> dzahl1 >> coperator >> dzahl2;
         }

         else
         {
             cout << "Geben sie eine Fakultaet ein: ";
             cin >> dzahl1 >> coperator;
         }
        
         //Division durch 0 abfangen
         if (coperator=='/')
         {
             while(dzahl2==0)
             {
                 cout << "Bitte geben Sie die zweite Zahl ein, welche keine 0 sein darf: ";
                 cin >> dzahl2;
             }
         }
        
         //V-erarbeitung
         switch(coperator) //switch: Mehrfachverzweigung, cases für die einzelnen Fälle
         {
             case '+':
                 dergebnis = dzahl1 + dzahl2;
                 //dergebnis = addiere(dzahl1, dzahl2); ist die alternative Berechnung
                 //über ein Unterprogramm bzw. Funktion über ein Unterprogramm bzw. Funktion
                 break; //Ans Ende der Switch Anweisung gehen,
                     //ohne break würden alle weiteren Anweisungen ausgeführt werden!
             case '-':
                 //dergebnis = dzahl1 - dzahl2; ist die Standard-Berechnung im Hauptprogramm
                 dergebnis = substrahiere(dzahl1, dzahl2);
                 break;
             case '*':
                 //dergebnis = dzahl1 * dzahl2;
                 dergebnis = multipliziere(dzahl1, dzahl2);
                 break;
             case '/':
                 //dergebnis = dzahl1 / dzahl2;
                 dergebnis = dividiere(dzahl1, dzahl2);
                 break;
                 /* Das letzte break könnte man theoretisch weglassen,
                    da keine weiteren Anweisungen folgen!
                    Default technisch nicht möglich, da Plausis verhindern das ein ungültiges
                    Operatorzeichen eingegeben werden kann
                 */
             case '!':
                // bigint a = 0;
                std::cout << fak(dzahl1) << std::endl;
                break;   
         }
        
         if (coperator != '!') {
            //A-usgabe
            cout << "Ihr Ergebnis lautet: " << dergebnis << "\n"; //Verkettete Ausgabe durch erneutes <<
         }
         
         //Benutzerabfrage: Noch eine Runde?
         cout << "Moechten Sie noch eine Rechnung durchfuehren (J/N)?";
         cin >> cantwort;
         while (cantwort!='j' && cantwort!='J'&& cantwort!='n' && cantwort!='N')
         {
             cout << "Bitte machen Sie eine korrekte Eingabe (J/N): ";
             cin >> cantwort;
         }
        
         // || ist die ODER Verknüfung, Kurzschreibweise ohne {} da jeweils nur eine Anweisung if/else
         if (cantwort=='j' || cantwort=='J')
             bweiter=true;
         else
             bweiter=false;
         cout << "\n";
    
     } while (bweiter==true);
    
     return 0; //Rückgabewert an das Betriebssystem, Programm beendet mit Rückwert 0
}