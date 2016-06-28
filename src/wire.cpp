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

Gate* getInputGate() const {
  return ins.begin()->second->getGate();
}
