#include <yong/head.h>

class Solution {
public:
  struct Node {
    Node(int v, int w) : val(v), weight(w) {}
    int val, weight;
  };

  int helper(vector<Node>& nodes, int l, int r, vector<vector<int>>& dp, vector<int>& weight_sum) {
    if (l > r)
      return 0;
    if (l == r)
      return nodes[l].weight;
    if (dp[l][r] != -1)
      return dp[l][r];
    int ret = INT_MAX, weight_this_level = weight_sum[r] - (l > 0 ? weight_sum[l - 1] : 0);
    for (int i = l; i <= r; i++) {
      ret = min(ret, weight_this_level +
          helper(nodes, l, i - 1, dp, weight_sum) +
          helper(nodes, i + 1, r, dp, weight_sum));
    }
    return dp[l][r] = ret;
  }

  int BestWeightsRec(vector<Node>& nodes) {
    sort(nodes.begin(), nodes.end(), [](Node& lhs, Node& rhs) {
        return lhs.val < rhs.val;
        });
    int n = nodes.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> weight_sum(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nodes[i].weight;
      weight_sum[i] = sum;
    }
    return helper(nodes, 0, n - 1, dp, weight_sum);
  }

  int BestWeights(vector<Node>& nodes) {
    sort(nodes.begin(), nodes.end(), [](Node& lhs, Node& rhs) {
        return lhs.val < rhs.val;
        });
    int n = nodes.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> weight_sum(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nodes[i].weight;
      weight_sum[i] = sum;
    }
    // dp
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        int l = i, r = i + len - 1, weight_this_level = weight_sum[r] - (l > 0 ? weight_sum[l - 1] : 0);
        dp[l][r] = INT_MAX;
        if (l == r)
          dp[l][r] = nodes[l].weight;
        else {
          for (int j = l; j <= r; j++) {
            dp[l][r] = min(dp[l][r], weight_this_level +
                (j - 1 >= l ? dp[l][j - 1] : 0) +
                (j + 1 <= r ? dp[j + 1][r] : 0));
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};
