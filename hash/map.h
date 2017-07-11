

class Solution {
public:
  void f(vector<pair<int, int>>& vec) {
    map<int, int> mp;
    for (auto& ele : vec) {
      mp.insert(map<int, int>::value_type(ele.first, 1));
      mp.insert(map<int, int>::value_type(ele.second, -1));
    }

    vector<pair<int, int>> ret;
    int cnt = 0, start = -1;
    for (auto& ele : mp) {
      cnt += ele.second;
      if (cnt > 0 && start == -1) {
        start = ele.first;
      } else if (cnt == 0) {
        ret.push_back({start, ele.first});
        start = -1;
      }
    }
  }
};
