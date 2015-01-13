/****************************************************************
 * Rather generic header file that includes the 'Utilities' code.
 *
 * Author/copyright:  Duncan Buell used by Omar Ansari.
 * Date: 8 July 2014 used 10 September 2014.
 *
**/
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cmath>
using namespace std;

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "MovingAverage.h"

class Main
{
public:
  int main();
  virtual ~Main();

private:

};

#endif // MAIN_H
