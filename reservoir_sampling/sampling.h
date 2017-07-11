//
// Algorithm R
//
#include <yong/head.h>

// rand [low, high)
int Rand(int low, int high);

class Solution {
public:
  vector<int> func(vector<int>& vec, int k) {
    vector<int> ret(k);
    // fill reservior array
    for (int i = 0; i < k; i++)
      ret[i] = vec[i];

    // replace element with gradually decreasing probability
    for (int i = k, n = vec.size(); i < n; i++) {
      int val = Rand(0, i);
      if (val < k) {
        ret[val] = vec[i];
      }
    }
    return ret;
  }
};
