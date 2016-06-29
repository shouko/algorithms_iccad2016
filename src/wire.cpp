#include "pin.h"
#include "wire.h"
#include "gate.h"

void Wire::attachPin(Pin* pin) {
  if(pin->getType() == PIN_INPUT) {
    outs.insert(make_pair(make_pair(pin->getGate()->getName(), pin->getName()), pin));
  } else {
    ins.insert(make_pair(make_pair(pin->getGate()->getName(), pin->getName()), pin));
  }
  pin->setWire(this);
}

Gate* Wire::getInputGate() const {
  if(ins.empty()) {
    return 0;
  }
  return ins.begin()->second->getGate();
}

Gate* Wire::getOutputGate() const {
  if(outs.empty()) {
    return 0;
  }
  return outs.begin()->second->getGate();
}

const WireName Wire::getName() const {
  return name;
}
