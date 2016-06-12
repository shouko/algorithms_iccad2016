#include <iostream>
#include <map>
#include <sstream>
#include "graph.h"
using namespace std;

string gets_nc(stringstream &ss) {
  string tmp;
  ss >> tmp;
  if(tmp.back() == ',') {
    tmp.pop_back();
  }
  return tmp;
}

int main() {
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
        type = WireType.INPUT
      } else if(tmp == "output") {
        type = WireType.OUTPUT
      } else if(tmp == "wire") {
        type = WireType.NORMAL
      }
      while(ss.peek() != -1) {
        tmp = gets_nc(ss);
        graph.addWire(tmp, wiretype);
      }
    } else {
      // gates
      GateType type;
      if(tmp == "NOT1") {
        type = GateType.NOT1;
      } else if(tmp == "NAND2") {
        type = GateType.NAND2;
      } else if(tmp == "NOR2") {
        type = GateType.NOR2;
      }
      ss >> tmp; // gate name
      Gate* gate = graph.addGate(tmp, type);
      ss >> tmp; // '('
      while(ss.peek() != -1) {
        tmp = gets_nc(ss); // parameters like .A(b8)
        if(tmp[0] != ')') {
          PortName name = tmp[1];
          tmp.erase(0, args.find_first_of('('));
          tmp.pop_back(); // pop out trailing ')'
          graph->connectGateAndWire(gate, portName, tmp);
        }
      }
    }
  }
}
