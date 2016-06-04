#include "phy.h"
#include <math.h>

/*
  Funkcja do obliczania wilgotnosci bezwzglednej z podanej temperatury
  i wilgotnosci wzglednej. Wartosci z poza zakresu beda przycinane
  do wartosci granicznych.
  
  arg 1: (double) temperatura (-20..50 °C)
  arg 2: (double) wilgotnosc wzgledna (0..100 %)
  ret  : (double) wilgotnosc bezwzgledna (g/m³)
*/

double phyCalcAh(double temp, double rh) {
  
  if(temp < -20.0) temp = -20.0;
  else if(temp > 50.0) temp = 50.0;
  
  if(rh < 0.0) rh = 0.0;
  else if(rh > 100.0) rh = 100.0;
  
  return (double)(216.7*(((rh/100)*6.112*exp((17.62*temp)/(243.12+temp)))/(273.15+temp)));
}

/*
  Funkcja do obliczania punktu rosy z podanej temperatury i wilgotnosci
  wzglednej. Wartosci z poza zakresu beda przyciete do wartosci
  granicznych.
  
  arg 1: (double) temperatura (-20..50 °C)
  arg 2: (double) wilgotnosc wzgledna (0..100 %)
  ret  : (double) punkt rosy (°C)
*/

double phyCalcDp(double temp, double rh) {
  
  double h;
  
  if(temp < -20.0) temp = -20.0;
  else if(temp > 50.0) temp = 50.0;
  
  if(rh < 0.0) rh = 0.0;
  else if(rh > 100.0) rh = 100.0;
  
  h = ((log10(rh)-2.0)/0.4343) + ((17.62*temp)/(243.12+temp));
  return (double)((243.12*h)/(17.62-h));
}
