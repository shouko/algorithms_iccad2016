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
