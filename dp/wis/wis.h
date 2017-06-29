//
// Time = nlogn + nlogn = O(nlogn)
// Recursive methon might get stack overflow easily
//
#include <yong/head.h>

class Solution {
public:
  struct Interval {
    int l, r, w;
    Interval(int l, int r, int w) : l(l), r(r), w(w) {}
  };

  int helper(vector<Interval>& intervals, int start, vector<int>& dp) {
    if (start >= intervals.size())
      return 0;
    if (dp[start] != 0)
      return dp[start];

    int l = start + 1, r = intervals.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (intervals[mid].l < intervals[start].r)
        l = mid + 1;
      else
        r = mid;
    }
    int next = l;

    int not_pick = helper(intervals, start + 1, dp),
        pick = intervals[start].w + helper(intervals, next, dp);
    return dp[start] = max(pick, not_pick);
  }

  int WISRec(vector<Interval>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](Interval& lhs, Interval& rhs) {
          return lhs.l < rhs.l;
        });
    std::vector<int> dp(n, 0);
    return helper(intervals, 0, dp);
  }

  int WIS(vector<Interval>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](Interval& lhs, Interval& rhs) {
          return lhs.r < rhs.r || (lhs.r == rhs.r && lhs.l < rhs.l);
        });
    vector<int> dp(n, 0);
    dp[0] = intervals[0].w;
    for (int i = 0; i < n; i++) {
      // find prev start
      int l = 0, r = i - 1;
      while (l < r - 1) {
        int mid = l + (r - l) / 2;
        if (intervals[mid].r > intervals[i].l)
          r = mid - 1;
        else
          l = mid;
      }
      int prev = intervals[r].r <= intervals[i].l ? r : intervals[l].r <= intervals[i].l ? l : -1;
      dp[i] = max(dp[i - 1], intervals[i].w + (prev == -1 ? 0 : dp[prev]));
    }
    return dp[n - 1];
  }
};
