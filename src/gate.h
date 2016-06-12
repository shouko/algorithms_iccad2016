#ifndef _GATE_H_
#define _GATE_H_

#include <iostream>
#include <map>
#include "wire.h"
#include "port.h"
using namespace std;
typedef string GateName;

enum GateType {
  NAND2,
  NOR2,
  NOT1
};

class Gate {
public:
  Gate(GateName name, GateType type) : type(type), name(name) {}
  ~Gate() {}
  Port* addPort(PortName name, PortType type);
private:
  void addPort(Port* port);
  map<PortName, Port*> inPorts;
  map<PortName, Port*> outPorts;
  GateType type;
  GateName name;
};

#endif
