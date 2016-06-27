#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "common.h"
#include "wire.h"
#include "pin.h"
#include "gate.h"
using namespace std;

class Graph {
public:
  Graph() {}
  ~Graph() {}
  Wire* getWire(WireName name) const;
  void addWire(WireName name);
  void addWire(WireName name, WireType type);
  Gate* addGate(GateName name, GateType type);
  void connectGateAndWire(Gate* gate, PinName pinName, WireName wireName);
private:
  map<WireName, Wire*> ins;
  map<WireName, Wire*> outs;
  map<WireName, Wire*> wires;
  map<GateName, Gate*> gates;
};

#endif
