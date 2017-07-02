#include <yong/head.h>

class Solution {
public:
  int TossCoins(vector<double> coins, int k) {
    int n = coins.size();
    vector<double> dp(k + 1, 0.0);
    for (auto coin : coins) {
      for (int i = 0; i < k; i++) {
        dp[i] = (i - 1 >= 0 ? dp[i - 1] * coin : 0) + dp[i] * (1 - coin);
      }
    }
    return dp[k];
  }
};
