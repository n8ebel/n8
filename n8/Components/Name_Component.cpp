/*
 * Name_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "Name_Component.h"
#include <iostream>
#include <string>

using namespace std;

Name_Component::~Name_Component(){

}

Name_Component::Name_Component(){
    
}

Name_Component::Name_Component(string newID, string newName) : Component(newID){
    
    name_ = newName;
}

string Name_Component::get_name(){
    return name_;
}