#include "stalib.h"

void findTruePath(Gate* n, bool output, int count) {
  count++;
  if(count > slack)
    return;
  Gate* next;
  vector<pair<bool, bool>>* choice = getChoice(n, output);
  // c.first[0] is the first choice of a pin, c.first[1] is the first choice of b pin
  Fast faster = getWhoIsFaster(Gate* n); //0 if a is faster, 1 if b is faster, 2 if same ,3 if dont know
  if(faster == FAST_UNKNOWN) {answer_deck.setcheckpoint(n);}
  //check if table_1 or table_0 have bean down
  if(table_1 != null) {
    check_the_table(table_1, answer_deck);//check the input and print the answer
    return;
  } else if(table_0 != null) {
    check_the_table(table_0, answer_deck);//check the input and print the answer
    return;
  }

  //deal with the a pin first
  for(auto c : choice) {
    if(!conflictlist.cotains(n, c.first, c.second)) {
      if(checkDelayCouldBeTrue(n, c, faster, 0)) {
        next = n.nexta;
        n.set_a_pin_input = c.first;
        n.set_b_pin_input = c.second;
        if(next.type = input) {
          if(checkIfInputConflict(next, c.first)) {
            continue;
          } else {
            if(!conflictlist.cotains(n, c.first, !c.second)) {
              if(checkIfTwoPinConflict(n, c.first, c.second)) {
                conflictlist.add(n, c.first, c.second);
                continue;
              } else{
                answer_inpur[next.number] = c.first;
                answer_deck.insert(n);
                answer_deck.insert(n.wirea);
                if(answer_deck.check) {
                  answer_deck.print;
                }
                answer_deck.del;
                answer_deck.del;
                continue;
              }
            } else{
              answer_inpur[next.number] = c.first;
              answer_deck.insert(n);
              answer_deck.insert(n.wirea);
              if(answer_deck.check) {
                answer_deck.print;
              }
              answer_deck.del;
              answer_deck.del;
              continue;
            }
          }
        } else{
        //when next != input
          if(!conflictlist.cotains(n, c.first, !c.second)) {
            if(checkIfTwoPinConflict(n, c.first, c.second)) {
              conflictlist.add(n, c.first, c.second);
              continue;
            } else{  answer_inpur[next.number] = c.second;
              answer_deck.insert(n);
              answer_deck.insert(n.wirea);
              findTruePath(next, c.first);
              continue;
            }
          } else{
            answer_deck.insert(n);
            answer_deck.insert(n.wirea);
            findTruePath(next, c.first);
            continue;
          }
        }
      }
    }
  }

  //deal with the b pin secand
  for(auto c : choice) {
    if(!conflictlist.cotains(n, c.first, c.second)) {
      if(checkDelayCouldBeTrue(n, c, faster, 1)) {
        next = n.nextb;
        n.set_a_pin_input = c.first;
        n.set_b_pin_input = c.second;
        if(next.type = input) {
          if(checkIfInputConflict(next, c.second)) {
            continue;
          } else {
            if(!conflictlist.cotains(n, c.first, c.second)) {
              if(!checkIfTwoPinConflict(n, c.first, c.second)) {
                conflictlist.add(n, c.first, c.second);
                continue;
              } else{  answer_inpur[next.number] = c.second;
                answer_deck.insert(n);
                answer_deck.insert(n.wireb);
                if(answer_deck.check) {
                  answer_deck.print;
                }
                answer_deck.del;
                answer_deck.del;
                continue;
              }
            } else {
              answer_inpur[next.number] = c.second;
              answer_deck.insert(n);
              answer_deck.insert(n.wireb);
              if(answer_deck.check) {
                answer_deck.print;
              }
              answer_deck.del;
              answer_deck.del;
              continue;
            }
          }
        } else {
        //when next != input
          if(!conflictlist.cotains(Gate* n, !c.first, c.second)) {
            if(checkIfTwoPinConflict(n, c.first, c.second)) {
              conflictlist.add(n, c.first, c.second);
              continue;
            } else{
              answer_deck.insert(n);
              answer_deck.insert(n.wireb);
              findTruePath(next, c.second);
              continue;
            }
          } else{
            answer_deck.insert(n);
            answer_deck.insert(n.wirea);
            findTruePath(next, c.second);
            continue;
          }
        }
    }
  }
}

vector<pair<bool, bool>> getChoice(Gate* n, bool output) {
  vector<pair<bool, bool>> vec;
  GateType type = n->getType();
  if(type == GATE_NOT1) {
    if(output) {

    } else {

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
}

bool checkDelayCouldBeTrue(Gate* n, pair<bool, bool> c, int faster, int pin) {
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

bool checkIfTwoPinConflict(Gate* n, c.first, c.second) {
  //not shure if it is okay
  for each input both in pin a and pin b
    checklist.add(input, Gate* n);
  return ture;
}
