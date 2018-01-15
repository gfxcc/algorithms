#include <yong/head.h>


// time complexity
// Vertex, Edge
// E + V*Log(V)
//
class Graph {
public:
  Graph(vector<pair<string, string>>& edges, vector<int>& weights) {
    for (int i = 0, n = edges.size(); i < n; i++) {
      vertexs_.insert(edges[i].first);
      vertexs_.insert(edges[i].second);

      edges_[edges[i].first][edges[i].second] = weights[i];
      edges_[edges[i].second][edges[i].first] = weights[i];
    }
  }

  vector<pair<string, int>> FindPath(const string&               source,
                                     const string&               destination) {

    priority_queue<pair<int, string>,
                        vector<pair<int, string>>,
                        greater<pair<int, string>>> pq;
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;
x
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
      string u = pq.top().second;

      pq.pop();

      // update dist of vertex u 's neighbor
      for (auto iter = edges_[u].begin(); iter != edges_[u].end(); iter++) {
        string v = iter->first;
        int weight = iter->second;
        if (dist.find(v) == dist.end() || dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          prev[v] = u;
          pq.push({dist[v], v});
        }
      }
    }

    // generate path
    vector<pair<string, int>> path;
    string cur = destination;
    while (cur != source) {
      int dis = edges_[cur][prev[cur]];
      path.emplace_back(make_pair(cur, dis));
      cur = prev[cur];
    }
    reverse(path.begin(), path.end());

    // print
    cout << source;
    for (auto ele : path) {
      cout << "--(" << ele.second << ")-->" << ele.first;
    }
    cout << endl;
    return path;
  }
private:
  unordered_map<string, unordered_map<string, int>> edges_;
  unordered_set<string> vertexs_;
};

/*

*/
