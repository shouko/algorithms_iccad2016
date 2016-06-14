#ifndef _PORT_H_
#define _PORT_H_

#include "common.h"

class Wire;
class Gate;

class Port {
public:
  Port(PortName name, PortType type) : name(name), type(type) {}
  void setWire(Wire* wire);
  void setGate(Gate* gate);
  const Wire* getWire() const;
  const Gate* getGate() const;
  const PortType getType() const;
  const PortName getName() const;
private:
  PortName name;
  PortType type;
  Wire* wire;
  Gate* gate;
};

#endif
