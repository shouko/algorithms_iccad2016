#ifndef _GATE_H_
#define _GATE_H_

#include "common.h"
#include <map>
#include <vector>
using namespace std;

class Pin;
class Wire;

class RouteRow {
public:
  Pin* pin;
  Gate* gate;
  Wire* input;
  int dist;
  RouteRow(Pin* pin, Gate* gate, Wire* input, int dist) : pin(pin), gate(gate), input(input), dist(dist) {}
  ~RouteRow() {}
};

class Gate {
public:
  Gate(GateName name, GateType type) : type(type), name(name), routeRecordInfo {{0, 0}, {0, 0}}, toCheck(0) {}
  ~Gate() {}
  Pin* addPin(PinName name, PinType type);
  const string getName() const;
  const GateType getType() const;
  void setCheck(bool toCheck);
  const bool getCheck() const;
  Gate* getPrev(PinName name) const;
  Gate* getPrev(int num) const;
  Pin* getInPin(PinName name) const;
  Pin* getInPin(int num) const;
  void deriveRoute();
  vector<RouteRow> routeRecord;
  int routeRecordInfo[2][2];
private:
  void attachPin(Pin* pin);
  void routeRecordAdd(Pin* pin, Gate* gate, Wire* input, int dist);
  map<PinName, Pin*> inPins;
  map<PinName, Pin*> outPins;
  GateType type;
  GateName name;
  bool toCheck;
};

#endif
