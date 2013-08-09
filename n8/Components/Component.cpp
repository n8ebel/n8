/*
* Component.cpp
* n8
*
* Author:          Nate Ebel
* Date:            7/27/13
* Organization:    n8Tech
*
*/

#include "Component.h"

Component::~Component(){

}

Component::Component(){

}

Component::Component(string newID){
  id_ = newID;
}

string Component::get_id(){
  return id_;
}

