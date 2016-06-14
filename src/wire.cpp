#include "port.h"
#include "wire.h"
#include "gate.h"

void Wire::attachPort(Port* port) {
  if(port->getType() == PORT_INPUT) {
    outs.insert(make_pair(make_pair(port->getGate()->getName(), port->getName()), port));
  } else {
    ins.insert(make_pair(make_pair(port->getGate()->getName(), port->getName()), port));
  }
  port->setWire(this);
}
