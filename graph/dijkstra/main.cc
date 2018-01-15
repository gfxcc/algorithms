#include "dijkstra.h"
#include "graph.h"

int main() {
  /*
  vector<pair<string, string>> edges = {{"1", "3"}, {"1", "6"}, {"1", "2"},
    {"6", "5"}, {"6", "3"}, {"5", "4"}, {"3", "4"}, {"3", "2"}, {"2", "4"}};
  vector<int> weights = {9, 14, 7, 9, 2, 6, 11, 10, 15};
  */
  vector<pair<string, string>> edges;
  vector<int> weights;

  LoadData(edges, weights);

  Graph g(edges, weights);

  auto path = g.FindPath("A", "Z");
  return 0;
}

