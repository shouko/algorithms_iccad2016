#ifndef _WIRE_H_
#define _WIRE_H_

#include <map>
#include "port.h"
using namespace std;
typedef string WireName;

enum WireType {
  INPUT,
  OUTPUT,
  NORMAL
};

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
