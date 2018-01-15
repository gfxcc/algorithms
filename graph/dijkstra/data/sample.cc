#include <utility>
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

class Edge {
public:
  Edge(char start, char end, int dis) : start(start), end(end), dis(dis) {}

  char start, end;
  int dis;
};

bool ValidEdge(const vector<Edge>& edges, Edge& edge) {
  if (edge.start == edge.end)
    return false;
  if (edge.start > edge.end)
    swap(edge.start, edge.end);
  for (auto& e : edges) {
    if (e.start == edge.start && e.end == edge.end)
      return false;
  }
  return true;
}

int main() {

  ofstream file("graph.dat");
  srand(time(0));

  vector<char> vertexs;
  vector<Edge> edges;

  for (int i = 0; i < 26; i++)
    vertexs.push_back('A' + i);

  for (int i = 0; i < 50; i++) {
    Edge edge(vertexs[rand() % 26], vertexs[rand() % 26], rand() % 100);

    if (ValidEdge(edges, edge)) {
      edges.push_back(move(edge));
    }
  }

  for (auto edge : edges) {
    file << edge.start << " " << edge.end << " " << edge.dis << endl;
  }

  return 0;
}
