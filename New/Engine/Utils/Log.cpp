/*
 * Log.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: nath7313
 */

#include "Log.h"

using namespace std;

Log::Log() {
	// TODO Auto-generated constructor stub

}

Log::~Log() {
	// TODO Auto-generated destructor stub
}

/** Used to print error messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print describing the error
 */
void Log::error(string tag, string msg){
    cout << "(ERROR) " << tag << ": " << msg << endl;
}

/** Used to print info messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print
 */
void Log::info(string tag, string msg){
    cout << "(INFO) " << tag << ": " << msg << endl;
}

/** Used to print debug messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print
 */
void Log::debug(string tag, string msg){
    cout << "(DEBUG) " << tag << ": " << msg << endl;
}
