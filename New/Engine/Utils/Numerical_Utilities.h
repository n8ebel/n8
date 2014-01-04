/*
 * Numberical_Utilities.h
 *
 *  Created on: Aug 15, 2013
 *      Author: nath7313
 */

#ifndef NUMBERICAL_UTILITIES_H_
#define NUMBERICAL_UTILITIES_H_

#include <string>
#include <sstream>

using namespace std;

class Numerical_Utilities {
  public:
    static string num_to_string(int num);
    static string num_to_string(double num);
    static string num_to_string(float num);

  private:
    Numerical_Utilities();
    virtual ~Numerical_Utilities();
};

#endif /* NUMBERICAL_UTILITIES_H_ */
