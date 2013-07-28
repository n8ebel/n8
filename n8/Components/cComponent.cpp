/*
* cComponent.cpp
* n8
*
* Author:          Nate Ebel
* Date:            7/27/13
* Organization:    n8Tech
*
*/

#include "cComponent.h"

cComponent::~cComponent(){

}

cComponent::cComponent(){

}

cComponent::cComponent(string newID){
  id = newID;
}

string cComponent::get_id(){
  return id;
}

