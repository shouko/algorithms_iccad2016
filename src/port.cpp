#include "port.h"

void Port::setGate(Gate* gate) {
  this->gate = gate;
}

void Port::setWire(Wire* wire) {
  wire->attachPort(this);
  this->wire = wire;
}

const Gate* Port::getGate() {
  return gate;
}

const Wire* Port::getWire() {
  return wire;
}

const PortName Port::getName() {
  return name;
}

const PortType Port::getType() {
  return type;
}
