//Funktionen und Unterprogramme
int fak (int z1)
{
    if(z1==0)
    return 1;
    
    int erg=z1;
    
    for(int i=1;i<z1;i++)
    {
        erg*=i;
    }
    return erg;
}
double substrahiere(double z1, double z2)
{
     return z1-z2;
}

/* Wichtiger Hinweis: Diese Funktion wird im Hauptprogramm nicht verwendet und
   dient lediglich der Darstellung der Verwendung einer For-Schleife.
   Begründung: Eine Multiplikation via einfacher For-Schleife gilt nur für positive Ganzzahlen!
   Negative oder Fließkommazahlen innerhalb der Division können nicht via einer einfachen
   Zählschleife berechnet werden. */
double multipliziere(double z1, double z2)
{
     //return z1*z2;
     double erg=0;
     //int i=0; Man kann in der For Schleife eine Direktdeklaration durchführen
     for(int i=0;i<z2;i++) //Abkürzung: i++ bedeutet soviel wie i = i + 1;
     {
         erg+=z1; //Abkürzung: += bedeutet soviel wie erg = erg + z1;
     }
     return erg;
}

double dividiere(double z1, double z2)
{
     return z1/z2;
}