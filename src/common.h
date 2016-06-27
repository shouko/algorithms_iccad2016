#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
using namespace std;

typedef char PinName;
typedef string GateName;
typedef string WireName;

enum PinType {
  PIN_INPUT,
  PIN_OUTPUT
};

enum GateType {
  GATE_NAND2,
  GATE_NOR2,
  GATE_NOT1
};

enum WireType {
  WIRE_INPUT,
  WIRE_OUTPUT,
  WIRE_NORMAL
};

#endif
