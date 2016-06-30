#include "pin.h"
#include "wire.h"

void Pin::setGate(Gate* gate) {
  this->gate = gate;
}

void Pin::setWire(Wire* wire) {
  this->wire = wire;
}

Gate* Pin::getGate() const {
  return gate;
}

Wire* Pin::getWire() const {
  return wire;
}

const PinName Pin::getName() const {
  return name;
}

const PinType Pin::getType() const {
  return type;
}

void Pin::setVal(bool val) {
  this->val = val;
}

const bool Pin::getVal() const {
  return val;
}
