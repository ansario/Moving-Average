#include "Main.h"

/****************************************************************
 * Main program for Homework 2.
 *
 * Author/copyright:  Duncan Buell. All rights reserved. Used by Omar Ansari.
 * Date: 8 July 2014 used 10 September 2014.
 *
**/

int main(int argc, char *argv[])
{
  string fileName = "xinput.txt";
  MovingAverage movingAverage;

  movingAverage.readData(fileName);

  movingAverage.doMovingAverage(5, 0.1);

  movingAverage.doMovingAverage(5, 0.05);

  movingAverage.doMovingAverage(10, 0.1);

  movingAverage.doMovingAverage(10, 0.05);

  return 0;
}

