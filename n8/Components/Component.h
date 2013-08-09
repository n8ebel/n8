/*
 * Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef Component_H
#define Component_H

#include <string>

using namespace std;

class Component {
 private:
  string id_;

 public:

    ~Component();
    Component();
    Component(string newID);

    string get_id();

};

#endif 
