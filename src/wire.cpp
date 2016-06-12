#include "wire.h"

Wire::attachPort(Port* port) {
  if(port->getType() == PortType.INPUT) {
    outs.insert(make_pair(make_pair(port->getGate()->getName(), port->getName()), port));
  } else {
    ins.insert(make_pair(make_pair(port->getGate()->getName(), port->getName()), port));
  }
  port->setWire(this);
}
