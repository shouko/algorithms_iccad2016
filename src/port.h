#ifndef _PORT_H_
#define _PORT_H_

typedef char PortName;

enum PortType {
  INPUT,
  OUTPUT
};

class Port {
public:
  Port(PortName name, PortType type) : name(name), type(type) {}
  void setWire(Wire* wire);
  void setGate(Gate* gate);
  const Wire* getWire();
  const Gate* getGate();
  const PortType getType();
  const PortName getName();
private:
  PortName name;
  PortType type;
  Wire* wire;
  Gate* gate;
};

#endif
