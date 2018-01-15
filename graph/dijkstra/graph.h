#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
using namespace boost;

void LoadData(vector<pair<string, string>>& edges, vector<int>& weights) {
  ifstream file("data/graph.dat");

  string line;
  while (getline(file, line)) {
    cout << "load:" << line << endl;
    vector<string> tokens;
    split(tokens, line, is_any_of(" "));
    edges.emplace_back(tokens[0], tokens[1]);
    weights.push_back(stoi(tokens[2]));
  }

  cout << "load finished" << endl;
}
