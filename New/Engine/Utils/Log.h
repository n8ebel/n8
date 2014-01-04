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
	static void error(string tag,string msg);
	static void info(string tag, string msg);
	static void debug(string tag, string msg);

  private:
	Log();
	virtual ~Log();
};

#endif /* LOG_H */
