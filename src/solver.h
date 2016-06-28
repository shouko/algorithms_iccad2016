#ifndef _SOLVER_H_
#define _SOLVER_H_

#include <set>
#include <vector>
#include <tuple>
#include <pair>
#include "common.h"

class Solver {
public:
  Solver(Graph* graph, int slack) : graph(graph), slack(slack) {}
  ~Solver() {}
  void solve();
private:
  int slack;
  Graph* graph;
  set<tuple<Gate*, bool, bool>> conflictList;
  void findTruePath(Gate* n, bool output, int count);
  vector<pair<bool, bool>> getChoice(Gate* n, bool output);
  bool checkDelayCouldBeTrue(Gate* n, pair<bool, bool> c, int faster, int pin);
  bool checkIfTwoPinConflict(Gate* n, pair<bool, bool> c);
  inline bool conflictListContains(Gate* n, bool a, bool b);
  inline void conflictListInsert(Gate* n, bool a, bool b);
};

#endif
