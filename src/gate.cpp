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

Gate* Gate::getPrev(PinName name) const {
  const Pin* pin = getInPin(name);
  if(pin == 0) {
    return 0;
  }
  return pin->getWire()->getInputGate();
}

Gate* Gate::getPrev(int num) const {
  if(num == 0) {
    return getPrev('A');
  } else if(num == 1) {
    return getPrev('B');
  } else {
    return 0;
  }
}

Pin* Gate::getInPin(PinName name) const {
  auto pin_it = inPins.find(name);
  if(pin_it == inPins.end()) {
    return 0;
  }
  return pin_it->second;
}

Pin* Gate::getInPin(int num) const {
  if(num == 0) {
    return getInPin('A');
  } else if(num == 1) {
    return getInPin('B');
  } else {
    return 0;
  }
}

void Gate::deriveRoute() {
  for(auto pin_it : inPins) {
    Gate* g = pin_it.second->getWire()->getInputGate();
    if(g != 0) {
      for(RouteRow rr : g->routeRecord) {
        routeRecordAdd(pin_it.second, g, rr.input, rr.dist + 1);
      }
    } else {
      // this gate is near input
      routeRecordAdd(pin_it.second, 0, pin_it.second->getWire(), 1);
    }
  }
  for(auto pin_it : outPins) {
    Gate* g = pin_it.second->getWire()->getOutputGate();
    if(g != 0) {
      g->deriveRoute();
    } else {
      // this gate is near output
    }
  }
}

void Gate::routeRecordAdd(Pin* pin, Gate* gate, Wire* input, int dist) {
  RouteRow rr(pin, gate, input, dist);
  routeRecord.push_back(rr);
  size_t rowIndex = 0;
  if(pin->getName() == 'B') {
    rowIndex = 1;
  }
  if(routeRecordInfo[rowIndex][0] == 0) {
    routeRecordInfo[rowIndex][0] = dist;
    routeRecordInfo[rowIndex][1] = dist;
    return;
  }
  if(dist < routeRecordInfo[rowIndex][0]) {
    routeRecordInfo[rowIndex][0] = dist;
  }
  if(dist > routeRecordInfo[rowIndex][1]) {
    routeRecordInfo[rowIndex][1] = dist;
  }
}
