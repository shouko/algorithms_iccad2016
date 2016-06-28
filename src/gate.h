#ifndef _GATE_H_
#define _GATE_H_

#include "common.h"
#include <map>
using namespace std;

class Pin;
class Wire;

class Gate {
public:
  Gate(GateName name, GateType type) : type(type), name(name), toCheck(0) {}
  ~Gate() {}
  Pin* addPin(PinName name, PinType type);
  const string getName() const;
  const GateType getType() const;
  void setCheck(bool toCheck);
  const bool getCheck() const;
  const Gate* getPrev(PinName name) const;
  const Gate* getPrev(int num) const;
  const Pin* getInPin(PinName name) const;
  const Pin* getInPin(int num) const;
private:
  void attachPin(Pin* pin);
  map<PinName, Pin*> inPins;
  map<PinName, Pin*> outPins;
  GateType type;
  GateName name;
  bool toCheck;
};

#endif
