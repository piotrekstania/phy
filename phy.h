#ifndef _phy_h
#define _phy_h

/*
  Funkcja do obliczania wilgotnosci bezwzglednej z podanej temperatury
  i wilgotnosci wzglednej. Wartosci z poza zakresu beda przycinane
  do wartosci granicznych.
  
  arg 1: (double) temperatura (-20..50 °C)
  arg 2: (double) wilgotnosc wzgledna (0..100 %)
  ret  : (double) wilgotnosc bezwzgledna (g/m³)
*/

double phyCalcAh(double temp, double rh);

/*
  Funkcja do obliczania punktu rosy z podanej temperatury i wilgotnosci
  wzglednej. Wartosci z poza zakresu beda przyciete do wartosci
  granicznych.
  
  arg 1: (double) temperatura (-20..50 °C)
  arg 2: (double) wilgotnosc wzgledna (0..100 %)
  ret  : (double) punkt rosy (°C)
*/

double phyCalcDp(double temp, double rh);

#endif //_phy_h
