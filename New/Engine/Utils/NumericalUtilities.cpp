/*
 * Numberical_Utilities.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: nath7313
 */

#include "NumericalUtilities.h"

Numerical_Utilities::Numerical_Utilities() {
	// TODO Auto-generated constructor stub

}

Numerical_Utilities::~Numerical_Utilities() {
	// TODO Auto-generated destructor stub
}

/** Converts an integer to a string
 *
 *  @param num The number to convert
 *  @return A string representation of the passed value
 */
string Numerical_Utilities::num_to_string(int num){
    string result;
    ostringstream convert;
    convert << num;
    result = convert.str();

    return result;
}

/** Converts a double to a string
 *
 *  @param num The number to convert
 *  @return A string representation of the passed value
 */
string Numerical_Utilities::num_to_string(double num){
    string result;
    ostringstream convert;
    convert << num;
    result = convert.str();

    return result;
}

/** Converts a float to a string
 *
 *  @param num The number to convert
 *  @return A string representation of the passed value
 */
string Numerical_Utilities::num_to_string(float num){
    string result;
    ostringstream convert;
    convert << num;
    result = convert.str();

    return result;
}