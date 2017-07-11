#include <yong/head.h>

class Solution {
public:
  string Compress(const string& str) {
    string ret;
    int n = str.size(), i = 0, j = 0;
    while (i < n) {
      j = i;
      while (j < n && str[j] == str[i])
        j++;

      // len = j - i
      if (j - i > 1) {
        ret += string(1, str[i]) + to_string(j - i - 1);
      } else {
        ret += string(1, str[i]);
      }
      i = j;
    }
    return ret;
  }
};
