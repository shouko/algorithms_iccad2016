#include "solver.h"

inline bool Solver::conflictListContains(Gate* n, bool a, bool b) {
  return conflictList.find(make_tuple(n, a, b)) != conflictList.end();
}

inline void conflictListInsert(Gate* n, bool a, bool b) {
  return conflictList.insert(make_tuple(n, a, b));
}

void Solver::findTruePath(Gate* n, bool output, int count) {
  count++;
  if(count > slack)
    return;
  Gate* next;
  vector<pair<bool, bool>>* choice = getChoice(n, output);
  Fast faster = getWhoIsFaster(Gate* n); // FAST_A, FAST_B, FAST_EQ, FAST_UNKNOWN
  if(faster == FAST_UNKNOWN) {
    n->setCheck(1);
  }
  //check if table_1 or table_0 have bean down
  if(table_1 != null) {
    check_the_table(table_1, answerStack);//check the input and print the answer
    return;
  } else if(table_0 != null) {
    check_the_table(table_0, answerStack);//check the input and print the answer
    return;
  }

  //deal with the a pin first
  for(int i = 0; i < 2; i++) {
    for(auto c : choice) {
      if(!conflictListContains(n, c.first, c.second)) {
        if(checkDelayCouldBeTrue(n, c, faster, i)) {
          next = n->getPrev(i);
          n->getInPin('A')->setVal(c.first);
          n->getInPin('B')->setVal(c.second);
          if(next == 0) {
            if(conflictListContains(n, c.first, !c.second)) {
              continue;
            } else{
              answerInput[next.number] = get<i>(c);
              answerStackInsert(n);
              answerStackInsert(n->getInPin(i)->getWire());
              if(answerStack.check) {
                answerStack.print;
              }
              answerStack.pop();
              answerStack.pop();
              continue;
            }
          } else{
          //when next != input
            bool cond;
            if(i == 0) {
              cond = conflictListContains(n, c.first, !c.second);
            } else {
              cond = conflictListContains(n, !c.first, c.second);
            }
            if(!cond) {
              continue;
            } else{
              answerStackInsert(n);
              answerStackInsert(n->getInPin(i)->getWire());
              findTruePath(next, get<i>(c));
              continue;
            }
          }
        }
      }
    }
  }
}

vector<pair<bool, bool>> Solver::getChoice(Gate* n, bool output) {
  vector<pair<bool, bool>> vec;
  GateType type = n->getType();
  if(type == GATE_NOT1) {
    if(output) {
      vec.push_back(make_pair(0, 0));
    } else {
      vec.push_back(make_pair(1, 0));
    }
  } else if(type == GATE_NOR2) {
    if(output) {
      vec.push_back(make_pair(0, 0));
    } else {
      vec.push_back(make_pair(0, 1));
      vec.push_back(make_pair(1, 0));
      vec.push_back(make_pair(1, 1));
    }
  } else if(type == GATE_NAND2) {
    if(output) {
      vec.push_back(make_pair(0, 0));
      vec.push_back(make_pair(0, 1));
      vec.push_back(make_pair(1, 0));
    } else {
      vec.push_back(make_pair(1, 1))
    }
  }
  return vec;
}

bool Solver::checkDelayCouldBeTrue(Gate* n, pair<bool, bool> c, int faster, int pin) {
  GateType type = n->getType();
  if(type == GATE_NOT1) {
    return true;
  } else  if(type == GATE_NOR2) {
    if(pin = 0) {
      if(c.first == 0 && c.second == 0) {if(faster != FAST_A)return true;}
      if(c.first == 1 && c.second == 0) {return true;}
      if(c.first == 1 && c.second == 1) {if(faster != FAST_B)return true;}
    } else {
      if(c.first == 0 && c.second == 0) {if(faster != FAST_B)return true;}
      if(c.first == 0 && c.second == 1) {return true;}
      if(c.first == 1 && c.second == 1) {if(faster != FAST_A)return true;}
    }
  } else if(type == GATE_NAND2) {
    if(pin = 0) {
      if(c.first == 1 && c.second == 1) {if(faster != FAST_B)return true;}
      if(c.first == 0 && c.second == 1) {return true;}
      if(c.first == 0 && c.second == 0) {if(faster != FAST_A)return true;}
    } else {
      if(c.first == 1 && c.second == 1) {if(faster != FAST_A)return true;}
      if(c.first == 1 && c.second == 0) {return true;}
      if(c.first == 0 && c.second == 0) {if(faster != FAST_B)return true;}
    }
  }
  return false;
}

inline void Solver::answerStackInsert(Gate* g) {
  AnsEntry entry;
  entry.g = g;
  answerStack.insert(make_pair(ANS_GATE, entry));
}

inline void Solver::answerStackInsert(Wire* w) {
  AnsEntry entry;
  wire.w = w;
  answerStack.insert(make_pair(ANS_WIRE, entry));
}
