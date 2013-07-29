/*
 * cName_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "cName_Component.h"
#include <iostream>
#include <string>

using namespace std;

cName_Component::~cName_Component(){

}

cName_Component::cName_Component(){
    
}

cName_Component::cName_Component(string newID, string newName) : cComponent(newID){
    
    
    name = newName;
    cout << "name component: " << name << endl;
}

string cName_Component::get_name(){
    return name;
}