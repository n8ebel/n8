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

