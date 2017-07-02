#include <yong/head.h>

class Solution {
  int Badness(int page_width, vector<string>& words, int start, int end) {
    // you might want optimize this by preprocess
    int width = accumulate(words.begin() + start, words.begin() + end, 0, [](int a, string& b) {
          return a + b.size() + 1;
        }) - 1;
    // not fit
    if (width > page_width)
      return numeric_limits<int>::max();
    //
    return pow(page_width - width, 3);
  }

  int helper(vector<string>& words, vector<int>& split_points, vector<int>& memo, int start, int page_width) {
    if (memo[start] != -1)
      return memo[start];
    if (start >= words.size())
      return 0;
    int badness = numeric_limits<int>::max(), split_point = 0;
    for (int j = start + 1; j <= words.size(); j++) {
      // avoid overflow
      int badness_j = Badness(page_width, words, start, j),
          badness_suffix = helper(words, split_points, memo, j, page_width);
      if (numeric_limits<int>::max() - badness_j >= badness_suffix) {
        badness_j += badness_suffix;
      } else {
        badness_j = numeric_limits<int>::max();
      }

      // better split point
      if (badness_j < badness) {
        split_point = j;
        badness = badness_j;
      }
    }
    split_points[start] = split_point;
    return memo[start] = badness;
  }
public:
  vector<vector<string>> JustificationRec(vector<string>& words, int page_width) {
    vector<int> memo(words.size(), -1);
    vector<int> split_points(words.size());

    helper(words, split_points, memo, 0, page_width);

    // build lines
    vector<vector<string>> lines;
    int split = 0;
    while (split != words.size()) {
      vector<string> line(words.begin() + split, words.begin() + split_points[split]);
      lines.push_back(move(line));
      split = split_points[split];
    }

    return lines;
  }

  vector<vector<string>> Justification(vector<string>& words, int page_width) {
    vector<int> dp(words.size() + 1, numeric_limits<int>::max());
    vector<int> split_points(words.size());
    dp[words.size()] = 0;
    for (int i = words.size() - 1; i >= 0; i--) {

      for (int j = i + 1; j <= words.size(); j++) {
        int badness_j = Badness(page_width, words, i, j),
            badness_suffix = dp[j];
        // avoid overflow
        if (numeric_limits<int>::max() - badness_j < badness_suffix) {
          badness_j = numeric_limits<int>::max();
        } else {
          badness_j += badness_suffix;
        }

        if (dp[i] > badness_j) {
          dp[i] = badness_j;
          split_points[i] = j;
        }
      }
    }

    // build lines
    vector<vector<string>> lines;
    int split_point = 0;
    while (split_point != words.size()) {
      vector<string> line(words.begin() + split_point, words.begin() + split_points[split_point]);
      lines.push_back(move(line));
      split_point = split_points[split_point];
    }

    return lines;
  }

};
