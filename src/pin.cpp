#include "pin.h"
#include "wire.h"

void Pin::setGate(Gate* gate) {
  this->gate = gate;
}

void Pin::setWire(Wire* wire) {
  wire->attachPin(this);
  this->wire = wire;
}

const Gate* Pin::getGate() const {
  return gate;
}

const Wire* Pin::getWire() const {
  return wire;
}

const PinName Pin::getName() const {
  return name;
}

const PinType Pin::getType() const {
  return type;
}
