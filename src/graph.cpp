#include "graph.h"

Wire* Graph::getWire(WireName name) const {
  auto it = wires.find(name);
  if(it != wires.end()) {
    return it->second;
  } else {
    return 0;
  }
}

void Graph::addWire(WireName name) {
  addWire(name, WIRE_NORMAL);
}

void Graph::addWire(WireName name, WireType type) {
  Wire* wire = new Wire(name);
  if(type == WIRE_INPUT) {
    ins.insert(make_pair(name, wire));
  } else if(type == WIRE_OUTPUT) {
    outs.insert(make_pair(name, wire));
  }
  wires.insert(make_pair(name, wire));
}

Gate* Graph::addGate(GateName name, GateType type) {
  Gate* gate = new Gate(name, type);
  gates.insert(make_pair(name, gate));
  return gate;
}

void Graph::connectGateAndWire(Gate* gate, PinName pinName, WireName wireName) {
  PinType pinType = PIN_INPUT;
  if(pinName == 'Y') {
    pinType = PIN_OUTPUT;
  }
  Pin* pin = gate->addPin(pinName, pinType);
  Wire* wire = getWire(wireName);
  wire->attachPin(pin);
}
