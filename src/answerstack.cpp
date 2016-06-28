#include "answerstack.h"

void AnswerStack::insert(const Gate* g) {
  AnsEntry entry;
  entry.g = (Gate*)g;
  s.push(make_pair(ANS_GATE, entry));
}

void AnswerStack::insert(const Wire* w) {
  AnsEntry entry;
  entry.w = (Wire*)w;
  s.push(make_pair(ANS_WIRE, entry));
}

void AnswerStack::print() {

}

bool AnswerStack::check() {
  return true;
}

void AnswerStack::pop() {
  s.pop();
}
