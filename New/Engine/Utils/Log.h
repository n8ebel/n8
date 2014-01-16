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
    
    static void TurnOnDebugMessages();
    static void TurnOffDebugMessages();

  private:
	Log();
	virtual ~Log();
    
    static bool ERROR;
    static bool INFO;
    static bool DEBUGGING;
};

#endif /* LOG_H */
