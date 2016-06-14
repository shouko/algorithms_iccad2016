#include "port.h"
#include "wire.h"

void Port::setGate(Gate* gate) {
  this->gate = gate;
}

void Port::setWire(Wire* wire) {
  wire->attachPort(this);
  this->wire = wire;
}

const Gate* Port::getGate() const {
  return gate;
}

const Wire* Port::getWire() const {
  return wire;
}

const PortName Port::getName() const {
  return name;
}

const PortType Port::getType() const {
  return type;
}
