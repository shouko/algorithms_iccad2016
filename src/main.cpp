#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include "pin.h"
#include "gate.h"
#include "wire.h"
#include "graph.h"
#include "solver.h"
using namespace std;

string gets_nc(stringstream &ss) {
  string tmp;
  ss >> tmp;
  if(tmp.back() == ',') {
    tmp.pop_back();
  }
  return tmp;
}

int main(int argc, char* argv[]) {
  Graph graph;
  // read circuit
  string tmp;
  while(cin.peek() != -1) {
    if(cin.peek() == '/') {
      getline(cin, tmp, '\n');
      continue;
    }
    getline(cin, tmp, ';');
    stringstream ss(tmp);
    ss >> tmp;
    if(tmp == "module") {
      continue;
    }
    if(tmp[0] != 'N') {
      // input, output, wire
      WireType type;
      if(tmp == "input") {
        type = WIRE_INPUT;
      } else if(tmp == "output") {
        type = WIRE_OUTPUT;
      } else if(tmp == "wire") {
        type = WIRE_NORMAL;
      } else {
        continue;
      }
      while(ss.peek() != -1) {
        tmp = gets_nc(ss);
        graph.addWire(tmp, type);
      }
    } else {
      // gates
      GateType type;
      if(tmp == "NOT1") {
        type = GATE_NOT1;
      } else if(tmp == "NAND2") {
        type = GATE_NAND2;
      } else if(tmp == "NOR2") {
        type = GATE_NOR2;
      } else {
        return -1;
      }
      ss >> tmp; // gate name
      Gate* gate = graph.addGate(tmp, type);
      while(ss.peek() != -1) {
        ss.ignore(16, '.');
        if(ss.peek() != -1) {
          PinName name = ss.get();
          ss.get(); // '('
          getline(ss, tmp, ')');
          graph.connectGateAndWire(gate, name, tmp);
        }
      }
    }
  }
  int slack = atoi(argv[1]);
  Solver solver(&graph, slack);
//  solver.findTruePath(gate, output, 0);
  return 0;
}
