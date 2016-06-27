#ifndef _PIN_H_
#define _PIN_H_

#include "common.h"

class Wire;
class Gate;

class Pin {
public:
  Pin(PinName name, PinType type) : name(name), type(type) {}
  void setWire(Wire* wire);
  void setGate(Gate* gate);
  const Wire* getWire() const;
  const Gate* getGate() const;
  const PinType getType() const;
  const PinName getName() const;
private:
  PinName name;
  PinType type;
  Wire* wire;
  Gate* gate;
};

#endif
