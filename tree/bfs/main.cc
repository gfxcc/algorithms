#include "bfs.h"

int main(int argc, char const* argv[])
{
  Solution s;
  vector<Solution::Node> nodes;
  for (int i = 0; i < 10; i++)
    nodes.push_back(Solution::Node(i));
  nodes[0].off_spring.push_back(&(nodes[1]));
  nodes[0].off_spring.push_back(&(nodes[2]));
  nodes[1].off_spring.push_back(&(nodes[3]));
  nodes[1].off_spring.push_back(&(nodes[4]));
  nodes[2].off_spring.push_back(&(nodes[5]));
  nodes[2].off_spring.push_back(&(nodes[6]));

  s.BuildSibling(&nodes[0]);
  return 0;
}
