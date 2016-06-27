#include "port.h"
#include "gate.h"
#include "wire.h"

void Gate::attachPort(Port* port) {
  port->setGate(this);
  if(port->getType() == PORT_INPUT) {
    inPorts.insert(make_pair(port->getName(), port));
  } else {
    outPorts.insert(make_pair(port->getName(), port));
  }
}

Port* Gate::addPort(PortName name, PortType type) {
  Port* port = new Port(name, type);
  attachPort(port);
  return port;
}

const GateName Gate::getName() const {
  return name;
}

const GateType Gate::getType() const {
  return type;
}
