#ifndef _WIRE_H_
#define _WIRE_H_

#include <iostream>
#include <map>
#include "common.h"
using namespace std;

class Port;
class Gate;

class Wire {
public:
  Wire(WireName name) : name(name) {}
  ~Wire() {}
  void attachPort(Port* port);
private:
  WireName name;
  map<pair<GateName, PortName>, Port*> ins;
  map<pair<GateName, PortName>, Port*> outs;
};

#endif
