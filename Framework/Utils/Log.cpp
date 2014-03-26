/*
 *  LogService.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Log.h"

using namespace std;

bool n8::Log::ERROR = true;
bool n8::Log::INFO = true;
bool n8::Log::DEBUGGING = true;

n8::Log::Log() {
	// TODO Auto-generated constructor stub
    
}

n8::Log::~Log() {
	// TODO Auto-generated destructor stub
}

/** Used to print error messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print describing the error
 */
void n8::Log::Error(std::string tag, std::string msg){
    if (ERROR) {
        std::cout << "(ERROR) " << tag << ": " << msg << std::endl;
    }
}

/** Used to print info messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print
 */
void n8::Log::Info(std::string tag, std::string msg){
    if(INFO){
        std::cout << "(INFO) " << tag << ": " << msg << std::endl;
    }
}

/** Used to print debug messages to the console
 *
 *  @param tag A string to indicate something about the message such as the class, method, or file it's from
 *  @param msg The message to print
 */
void n8::Log::Debug(std::string tag, std::string msg){
    if(DEBUGGING){
        std::cout << "(DEBUG) " << tag << ": " << msg << std::endl;
    }
}

/** Sets the ERROR flag to true.
 *  This allows error messages to be displayed
 */
void n8::Log::TurnOnErrorMessages(){
    ERROR = true;
}

/** Sets the ERROR flag to false
 *  This causes error messages to not be displayed
 */
void n8::Log::TurnOffErrorMessages(){
    ERROR = false;
}

/** Sets the INFO flag to true.
 *  This allows info messages to be displayed
 */
void n8::Log::TurnOnInfoMessages(){
    INFO = true;
}

/** Sets the INFO flag to false
 *  This causes info messages to not be displayed
 */
void n8::Log::TurnOffInfoMessages(){
    INFO = false;
}

/** Sets the DEBUGGING flag to true.
 *  This allows debugging messages to be displayed
 */
void n8::Log::TurnOnDebuggingMessages(){
    DEBUGGING = true;
}

/** Sets the DEBUGGING flag to false
 *  This causes debugging messages to not be displayed
 */
void n8::Log::TurnOffDebuggingMessages(){
    DEBUGGING = false;
}
