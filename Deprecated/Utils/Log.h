/*
 * Log.h
 *
 *  Created on: Aug 15, 2013
 *      Author: nath7313
 */

#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>

using namespace std;

class Log {
  public:
    
	static void Error(string tag,string msg);
	static void Info(string tag, string msg);
	static void Debug(string tag, string msg);
    
    static void TurnOnErrorMessages();
    static void TurnOffErrorMessages();
    
    static void TurnOnInfoMessages();
    static void TurnOffInfoMessages();
    
    static void TurnOnDebuggingMessages();
    static void TurnOffDebuggingMessages();

  private:
	Log();
	virtual ~Log();
    
    static bool ERROR;  /** < static boolean flag to control whether ERROR messages are displayed > */
    static bool INFO;  /** < static boolean flag to control whether INFO messages are displayed > */
    static bool DEBUGGING;  /** < static boolean flag to control whether DEBUGGING messages are displayed > */
};

#endif /* LOG_H */
