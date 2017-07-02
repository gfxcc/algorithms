#include <yong/head.h>

class Solution {
  //
  // if not fit: INT_MAX
  // else: (page_width - width_token) ^ 3
  // avoid int overflow
  //
  int Badness(int page_width, vector<string>& words, vector<int>& widths, int start, int end) {
    int width = widths[start] - widths[end] + end - start - 1;
    // not fit
    if (width > page_width)
      return numeric_limits<int>::max();
    //
    return (page_width - width <= pow(numeric_limits<int>::max(), 1 / 3.0)) ?
      pow(page_width - width, 3) : numeric_limits<int>::max();
  }

  //
  // memorized dp
  //
  int helper(vector<string>& words, vector<int>& split_points, vector<int>& memo,
      vector<int>& widths, int start, int page_width) {
    if (memo[start] != -1)
      return memo[start];
    if (start >= words.size())
      return 0;
    int badness = numeric_limits<int>::max(), split_point = 0;
    for (int j = start + 1; j <= words.size(); j++) {
      // avoid overflow
      int badness_j = Badness(page_width, words, widths, start, j),
          badness_suffix = helper(words, split_points, memo, widths, j, page_width);
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
  //
  // memorized dp based on recursion
  //
  vector<vector<string>> JustificationRec(vector<string>& words, int page_width) {
    vector<int> memo(words.size(), -1);
    vector<int> split_points(words.size());
    vector<int> widths(words.size() + 1, 0);

    // preprocess widths
    int cnt = 0;
    for (int i = words.size() - 1; i >= 0; i--) {
      // cannot construct valid result
      if (words[i].size() > page_width)
        return vector<vector<string>>();
      cnt += words[i].size();
      widths[i] = cnt;
    }

    helper(words, split_points, memo, widths, 0, page_width);

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

  //
  // bottom to top dp based on loop
  //
  vector<vector<string>> Justification(vector<string>& words, int page_width) {
    vector<int> dp(words.size() + 1, numeric_limits<int>::max());
    vector<int> split_points(words.size());
    vector<int> widths(words.size() + 1, 0);

    // preprocess widths
    int cnt = 0;
    for (int i = words.size() - 1; i >= 0; i--) {
      // can not construct valid result
      if (words[i].size() > page_width)
        return vector<vector<string>>();
      cnt += words[i].size();
      widths[i] = cnt;
    }

    dp[words.size()] = 0;
    for (int i = words.size() - 1; i >= 0; i--) {

      for (int j = i + 1; j <= words.size(); j++) {
        int badness_j = Badness(page_width, words, widths, i, j),
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
