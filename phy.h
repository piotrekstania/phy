#ifndef _phy_h
#define _phy_h

/*
  Function calculates and returns absolute humidity.
  Inputs over range will be cutted to min or max value.
  
  arg 1: (double) temperature (-20..50 °C)
  arg 2: (double) relative humidity (0..100 %)
  ret  : (double) absolute humidity (g/m³)
*/

double phyCalcAh(double temp, double rh);

/*
  Function calculates and returns dew point.
  Inputs over range will be cutted to min or max value.
  
  arg 1: (double) temperature (-20..50 °C)
  arg 2: (double) relative humidity (0..100 %)
  ret  : (double) dew point (°C)
*/

double phyCalcDp(double temp, double rh);

/*
  Function calculates and returns pressure of liquid R410A.
  Inputs over range will be cutted to min or max value.

  arg 1: (double) temperature (-100..72 °C)
  ret  : (double) absolute pressure (bar)
*/

double phyCalcLiqPresR410A(double temp);

/*
  Function calculates and returns pressure of vapor R410A.
  Inputs over range will be cutted to min or max value.

  arg 1: (double) temperature (-100..72 °C)
  ret  : (double) absolute pressure (bar)
*/

double phyCalcVapPresR410A(double temp);


#endif //_phy_h
