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
