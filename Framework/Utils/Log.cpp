/*
 * Log.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: nath7313
 */

#include "Log.h"

using namespace std;

bool Log::ERROR = true;
bool Log::INFO = true;
bool Log::DEBUGGING = true;

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
void Log::Error(string tag, string msg){
    if (ERROR) {
        cout << "(ERROR) " << tag << ": " << msg << endl;
    }
}

/** Used to print info messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print
 */
void Log::Info(string tag, string msg){
    if(INFO){
        cout << "(INFO) " << tag << ": " << msg << endl;
    }
}

/** Used to print debug messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print
 */
void Log::Debug(string tag, string msg){
    if(DEBUGGING){
        cout << "(DEBUG) " << tag << ": " << msg << endl;
    }
}

/** Sets the ERROR flag to true.
 *  This allows error messages to be displayed
 */
void Log::TurnOnErrorMessages(){
    ERROR = true;
}

/** Sets the ERROR flag to false
 *  This causes error messages to not be displayed
 */
void Log::TurnOffErrorMessages(){
    ERROR = false;
}

/** Sets the INFO flag to true.
 *  This allows info messages to be displayed
 */
void Log::TurnOnInfoMessages(){
    INFO = true;
}

/** Sets the INFO flag to false
 *  This causes info messages to not be displayed
 */
void Log::TurnOffInfoMessages(){
    INFO = false;
}

/** Sets the DEBUGGING flag to true.
 *  This allows debugging messages to be displayed
 */
void Log::TurnOnDebuggingMessages(){
    DEBUGGING = true;
}

/** Sets the DEBUGGING flag to false
 *  This causes debugging messages to not be displayed
 */
void Log::TurnOffDebuggingMessages(){
    DEBUGGING = false;
}