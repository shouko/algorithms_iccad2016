#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "port.h"
#include "wire.h"
using namespace std;

class Graph {
public:
  Graph() {}
  ~Graph() {}
  Wire* getWire(WireName name);
  void addWire(WireName name);
  void addWire(WireName name, WireType type);
  Gate* addGate(GateName name, GateType type);
  void connectGateAndWire(Gate* gate, PortName portName, Wire* wire);
private:
  map<WireName, Wire*> ins;
  map<WireName, Wire*> outs;
  map<WireName, Wire*> wires;
  map<GateName, Gate*> gates;
}

#endif
