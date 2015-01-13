#include "MovingAverage.h"
#include <iostream>

/****************************************************************
 * MovingAverage program for Homework 2.
 *
 * Author/copyright:  Omar Ansari. All rights reserved. 
 * Date: 10 September 2014.
 *
**/

/******************************************************************************
 * Constructor
**/
MovingAverage::MovingAverage()
{
}
/******************************************************************************
 * Destructor
**/
MovingAverage::~MovingAverage()
{
}
/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to compute and return the average or a range of double values.
 *
 * Parameters:
 *   int start -- the starting index in a range from which to compute values.
 *	 int width -- range of values starting at index start and ending at index start+width.
 *
 * Returns:
 *	  Average of values within window of length width.
**/

double MovingAverage::computeAverage(int start, int width)
{
	double tempPrice = 0.0;

	for (int i = start; i < start + width; i++){
		cout << "	" << (theData.at(i)); //Print out the values within the window of length width.
		tempPrice = theData.at(i) + tempPrice; //Add all values within the window of length width together. 
		
	}
		cout << ":	" <<  tempPrice << ":"; //Formatting the tempPrice after the output of values withint the window of lenght width.
		cout << "	" << tempPrice/width;
		return (tempPrice/width); //Return the average by dividing the total sum of values within the window of length width by the number of values within the width.
}
/****************************************************************
 * Function which implements the computeAverage method and prints a BUY or SELL string depending on certain paramteters.
 * If the value at the end of the width divided by the average of the days within the width is less than 1 minus the tolerance, issue a "BUY" string.
 * If the value at the end of the width divided by the average of the days within the width is greater than 1 + the tolerance, issue a "SELL" string.
 * 
 *	Parameters:
 *   int start -- the starting index in a range from which to compute values.
 *	 int width -- range of values starting at index start and ending at index start+width.
**/
void MovingAverage::doMovingAverage(int width, double tolerance)
{
	cout << "Enter doMovingAverage. \n";
	
	int i = 0;
	double decisionMetric = 0.0;

	cout << "Compute with 'width' and 'tolerance':" << "	"<< width <<"	" << tolerance << endl; //Display the width and tolerance being used for calculations.
		
		while (i+width < theData.size()){ //Loop to determine if the value at the end of the width divided by the average of the days within the width is greater or less than the tolerance passed in the mehod, and issue a BUY or SELL string.
			
			cout << setprecision(5); //Set precisions of values output to the console to maximum of 5 digits. 

			decisionMetric = (theData.at(width-1+i))/MovingAverage::computeAverage(i, width); //NOTE!! The decisionMetric is the value at position width-1+i divided by the average of the width of values. This handles the issue of reaching the end of the width and accidenatlly catching the next value outside of the intended width.
			
			cout << "	" << decisionMetric << " ";  //Output decisionMetric after the average. 

			if (decisionMetric < 1-tolerance){ //Do test to issue BUY or SELL or nothing.
				cout << "BUY." << endl;

			} else if (decisionMetric > 1 + tolerance) {
				cout << "SELL." << endl;
		
			} else {
				cout << endl;
			}

		i++; //Increment counter.
		}

	cout << "Leave doMovingAverage. \n"; //Message which notifies the user that the doMovingAverage method is complete.
	
}
/****************************************************************
 * Function to read data from .txt file into vector of doubles.
 *
 * Parameters
 * 	 inScanner -- the 'Scanner' from which to read.
 **/
void MovingAverage::readData(string fileName)
{

cout << "Execution beginning\n";
Scanner inScanner; 
inScanner.openFile(fileName); //Open file.

	while (inScanner.hasNext()) {
	
	double value;

	value = inScanner.nextDouble();

	theData.push_back(value); //Add value read from Scanner to theData vector.
	
	}
	
	cout << "File has successfully been read. \n";
	cout << "Leave readData. \n";
	
}
/****************************************************************
 * Function for returning the result of the parse.
 *
 * Returns:
 *   String version of the line.
**/
string MovingAverage::toStringTheData()
{
	int i = theData.size();

	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	
	return s;
}
