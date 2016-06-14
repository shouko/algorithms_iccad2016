#ifndef _GATE_H_
#define _GATE_H_

#include "common.h"
#include <map>
using namespace std;

class Port;
class Wire;

class Gate {
public:
  Gate(GateName name, GateType type) : type(type), name(name) {}
  ~Gate() {}
  Port* addPort(PortName name, PortType type);
  const string getName() const;
private:
  void attachPort(Port* port);
  map<PortName, Port*> inPorts;
  map<PortName, Port*> outPorts;
  GateType type;
  GateName name;
};

#endif
