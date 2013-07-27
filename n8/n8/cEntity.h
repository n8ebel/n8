#ifndef CENTITY_H
#define CENTITY_H

#include <vector>
#include <map>
#include "cComponent.h"

using namespace std;


class cEntity{
 private:
    int id;
    map<string, cComponent*> componentMap;

 public:
    ~cEntity();
    cEntity();
    cEntity(int newId);
  
    void add_component(cComponent* newComponent);
    void remove_component(string componentID);
  
    int get_id();
    cComponent* get_component(string componentID);
    map<string,cComponent*> get_components();
};

#endif 
