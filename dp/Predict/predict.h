#include <yong/head.h>

// dp[i][l] represent interval start from i lenght l
// dp[i][l] = { case : l == 1
//                     val[i]
//              else :
//                     max(// pick first element
//                         val[i]         + min ( dp[i + 2][l - 2], dp[i + 1][l - 2] ) ,
//                         // pick last element
//                         val[i + l - 1] + min ( dp[i][l - 2], dp[i + 1][l - 2] )
//
//                                         ) }
//
class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int l = 1; l <= n; l++) {
      for (int i = 0; i + l - 1 < n; i++) {
        if (l == 1) {
          dp[i][l] = nums[i];
        } else {
          int pick_first  = nums[i] + min(i + 2 < n ? dp[i + 2][l - 2] : 0, dp[i + 1][l - 2]),
              pick_second = nums[i + l - 1] + min(dp[i][l - 2], dp[i + 1][l - 2]);
          dp[i][l] = max(pick_first, pick_second);
        }
      }
    }

    return dp[0][n] * 2 >= accumulate(nums.begin(), nums.end(), 0);
  }
};
