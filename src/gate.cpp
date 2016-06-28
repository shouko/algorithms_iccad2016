#include "pin.h"
#include "gate.h"
#include "wire.h"

void Gate::attachPin(Pin* pin) {
  pin->setGate(this);
  if(pin->getType() == PIN_INPUT) {
    inPins.insert(make_pair(pin->getName(), pin));
  } else {
    outPins.insert(make_pair(pin->getName(), pin));
  }
}

Pin* Gate::addPin(PinName name, PinType type) {
  Pin* pin = new Pin(name, type);
  attachPin(pin);
  return pin;
}

const GateName Gate::getName() const {
  return name;
}

const GateType Gate::getType() const {
  return type;
}

void Gate::setCheck(bool toCheck) {
  this->toCheck = toCheck;
}
const bool Gate::getCheck() const {
  return toCheck;
}

const Gate* getPrev(PinName name) const {
  Pin* pin = getInPin(name);
  if(pin == 0) {
    return 0;
  }
  return pin->getWire()->getInputGate();
}

const Gate* getPrev(int num) const {
  if(num == 0) {
    return getPrev('A');
  } else if(num == 1) {
    return getPrev('B');
  } else {
    return 0;
  }
}

const Pin* getInPin(PinName name) const {
  auto pin_it = inPins.find(name);
  if(pin_it == inPins.end()) {
    return 0;
  }
  return pin_it->second;
}

const Pin* getInPin(int num) const {
  if(num == 0) {
    return getInPin('A');
  } else if(num == 1) {
    return getInPin('B');
  } else {
    return 0;
  }
}
