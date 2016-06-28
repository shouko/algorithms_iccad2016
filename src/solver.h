#ifndef _SOLVER_H_
#define _SOLVER_H_

#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <utility>
#include <stack>
#include "common.h"
#include "answerstack.h"

class Graph;
class Gate;
class Wire;

class Solver {
public:
  Solver(Graph* graph, int slack) : graph(graph), slack(slack) {}
  ~Solver() {}
  void solve();
private:
  Graph* graph;
  int slack;
  set<tuple<Gate*, bool, bool>> conflictList;
  AnswerStack answerStack;
  map<WireName, bool> answerInput;
  void findTruePath(Gate* n, bool output, int count);
  vector<pair<bool, bool>> getChoice(Gate* n, bool output);
  bool checkDelayCouldBeTrue(Gate* n, pair<bool, bool> c, int faster, int pin);
  bool checkIfTwoPinConflict(Gate* n, pair<bool, bool> c);
  Fast getWhoIsFaster(Gate* n);
  inline bool conflictListContains(Gate* n, bool a, bool b);
  inline void conflictListInsert(Gate* n, bool a, bool b);
};

#endif
