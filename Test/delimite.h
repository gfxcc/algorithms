#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> SplitStringByDeli(const string& str, const string& deli) {
    vector<string> vec;

    int begin = 0, i = 0, n = str.size(), m = deli.size();
    if (m == 0) {
      vec.push_back(str);
      return vec;
    }
    while (i < n) {
      int j = 0;
      while (j < m && i + j < n) {
        if (deli[j] != str[i + j])
          break;
        j++;
      }
      // .....(begin).....(i)deli(i + j) found
      if (j == m) {
        vec.push_back(str.substr(begin, i - begin));
        begin = i + j;
        i = begin;
      } else {
        i++;
      }
    }

    vec.push_back(str.substr(begin, i - begin));

    return vec;
  }

};
