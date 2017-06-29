#include "wbst.h"
#include <limits.h>
#include <gtest/gtest.h>
#include <ctime>
#include <cstdlib>

using namespace std;

TEST(Weight_Binary_Search_Tree, Sample) {
  srand(time(0));
  vector<Solution::Node> nodes;
  for (int i = 0; i < 1000; i++) {
    nodes.emplace_back(rand() % 1000, rand() % 100);
  }
  Solution s;
  int weight1 = s.BestWeightsRec(nodes);
  int weight2 = s.BestWeights(nodes);
  EXPECT_EQ(weight1, weight2);
}



