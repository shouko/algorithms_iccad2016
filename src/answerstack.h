#ifndef _ANSWERSTACK_H_
#define _ANSWERSTACK_H_

#include <stack>
#include <utility>
using namespace std;

class Gate;
class Wire;

typedef union AnsEntry {
  Gate* g;
  Wire* w;
} AnsEntry;

enum AnsEntryType {
  ANS_GATE,
  ANS_WIRE
};

class AnswerStack {
public:
  AnswerStack() {};
  ~AnswerStack() {};
  void insert(const Gate* g);
  void insert(const Wire* g);
  void print();
  bool check();
  void pop();
private:
  stack<pair<AnsEntryType, AnsEntry>> s;
};

#endif
