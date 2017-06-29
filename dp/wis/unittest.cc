#include "wis.h"
#include <limits.h>
#include <gtest/gtest.h>

using namespace std;

TEST(WIS, Sample) {
  vector<Solution::Interval> intervals = {Solution::Interval{0,3,3}, Solution::Interval{1,4,2},
    Solution::Interval{0,5,4}, Solution::Interval{3,6,1}, Solution::Interval{4,7,2}, Solution::Interval{3,9,5},
    Solution::Interval{5,10,2}, Solution::Interval{8,10,1}};

  for (int i = 0; i < 20; i++) {
    for (int j = 0, n = intervals.size(); j < n; j++)
      intervals.push_back(intervals[j]);
  }
  cout << intervals.size() << endl;
  Solution s;
  EXPECT_EQ(s.WIS(intervals), 8);
}

