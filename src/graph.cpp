#include "graph.h"

Wire* Graph::getWire(string name) {

}

void Graph::addWire(string name) {
  addWire(name, WIRE_NORMAL);
}

void Graph::addWire(string name, WireType type) {
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

void Graph::connectGateAndWire(Gate* gate, PortName portName, WireName wireName) {
  PortType portType = PORT_INPUT;
  if(portName == 'Y') {
    portType = PORT_OUTPUT;
  }
  Port* port = gate->addPort(portName, portType);
  Wire* wire = getWire(wireName);
  wire->attachPort(port);
}
