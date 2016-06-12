#include "gate.h"

Gate::~Gate() {
}

void Gate::attachPort(Port* port) {
  port->setGate(this);
  if(port->getType() == PortType.INPUT) {
    inPorts.insert(make_pair(port->getName(), port));
  } else {
    outPorts.insert(make_pair(port->getName(), port));
  }
}

Port* Gate::addPort(PortName name, PortType type) {
  Port* port = new Port(name, type);
  attachPort(port);
  return Port;
}
