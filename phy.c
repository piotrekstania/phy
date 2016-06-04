#include "phy.h"
#include <math.h>

/*
  Function calculates and returns absolute humidity.
  Inputs over range will be cutted to min or max value.
  
  arg 1: (double) temperature (-20..50 °C)
  arg 2: (double) relative humidity (0..100 %)
  ret  : (double) absolute humidity (g/m³)
*/

double phyCalcAh(double temp, double rh) {
  
  if(temp < -20.0) temp = -20.0;
  else if(temp > 50.0) temp = 50.0;
  
  if(rh < 0.0) rh = 0.0;
  else if(rh > 100.0) rh = 100.0;
  
  return (double)(216.7*(((rh/100)*6.112*exp((17.62*temp)/(243.12+temp)))/(273.15+temp)));
}

/*
  Function calculates and returns dew point.
  Inputs over range will be cutted to min or max value.
  
  arg 1: (double) temperature (-20..50 °C)
  arg 2: (double) relative humidity (0..100 %)
  ret  : (double) dew point (°C)
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

/*
  Function calculates and returns pressure of liquid R410A.
  Inputs over range will be cutted to min or max value.

  arg 1: (double) temperature (-68..72 °C)
  ret  : (double) absolute pressure (bar)
*/

double phyCalcPresLiqR410A(double temp) {
  
  const double A = -1.4376;
  const double B = -6.8715;
  const double C = -0.53623;
  const double D = -3.82642;
  const double E = -4.06875;
  const double F = -1.2333;
  const double X0 = 0.2086902;
  const double Tc = 345.28;
  const double Pc = 4926.1;
  
  double X, Tr;
  
  if(temp < -68.0) temp = -68.0;
  else if(temp > 72.0) temp = 72.0;
  
  Tr = (temp+273.15)/Tc;
  X  = (1.0-Tr)-X0;
  
  return (double)(exp( (1.0/Tr) * (A + (B*X) + (C*pow(X,2)) + (D*pow(X,3)) + (E*pow(X,4)) + (F*pow(X,5)))  )*Pc/100.0);
  
}

/*
  Function calculates and returns pressure of vapor R410A.
  Inputs over range will be cutted to min or max value.

  arg 1: (double) temperature (-68..72 °C)
  ret  : (double) absolute pressure (bar)
*/

double phyCalcPresVapR410A(double temp) {
  
}