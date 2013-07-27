#ifndef CCOMPONENT_H
#define CCOMPONENT_H

#include <string>

using namespace std;

class cComponent {
 private:
  string id;

 public:
  ~cComponent();
  cComponent();
  cComponent(string newID);

  string get_id();

};

#endif 
