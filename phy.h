#ifndef _phy_h
#define _phy_h

/*
  Function returning absolute humidity.
  Inputs over range will cut to min or max value.
  
  arg 1: (double) temperature (-20..50 °C)
  arg 2: (double) relative humidity (0..100 %)
  ret  : (double) absolute humidity (g/m³)
*/

double phyCalcAh(double temp, double rh);

/*
  Function returning absolute humidity.
  Inputs over range will cut to min or max value.
  
  arg 1: (double) temperature (-20..50 °C)
  arg 2: (double) relative humidity (0..100 %)
  ret  : (double) dew point (°C)
*/

double phyCalcDp(double temp, double rh);

#endif //_phy_h
