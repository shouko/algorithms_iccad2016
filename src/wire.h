#ifndef _WIRE_H_
#define _WIRE_H_

#include <iostream>
#include <map>
#include "common.h"
using namespace std;

class Pin;
class Gate;

class Wire {
public:
  Wire(WireName name) : name(name) {}
  ~Wire() {}
  void attachPin(Pin* pin);
  Gate* getInputGate() const;
private:
  WireName name;
  map<pair<GateName, PinName>, Pin*> ins;
  map<pair<GateName, PinName>, Pin*> outs;
};

#endif
