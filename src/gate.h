#ifndef _GATE_H_
#define _GATE_H_

#include "common.h"
#include <map>
using namespace std;

class Pin;
class Wire;

class Gate {
public:
  Gate(GateName name, GateType type) : type(type), name(name) {}
  ~Gate() {}
  Pin* addPin(PinName name, PinType type);
  const string getName() const;
  const GateType getType() const;
private:
  void attachPin(Pin* pin);
  map<PinName, Pin*> inPins;
  map<PinName, Pin*> outPins;
  GateType type;
  GateName name;
};

#endif
