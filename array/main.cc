#include <yong/head.h>

void PrintOuterToInner(vector<vector<int>>& matrix) {
  if (matrix.empty())
    return;
  int w = matrix.size() - 1, l = matrix[0].size() - 1, dir = 0, r = 0, c = 0;
  vector<pair<int, int>> neis = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  while (l > 0 || w > 0) {
    for (int i = 0; i < ((dir & 1) ? w : l); i++) {
      cout << matrix[r][c] << " ";
      r += neis[dir].first;
      c += neis[dir].second;
    }
    dir++;
    if (dir == 4) {
      l -= 2;
      w -= 2;
      dir = 0;
      r++; c++;
    }
  }
  cout << endl;
}

void PrintInnerToOuter(vector<vector<int>>& matrix) {
  if (matrix.empty())
    return;
  vector<pair<int, int>> neis;
  int m = matrix.size(), n = matrix[0].size(), r, c, l , w, dir;
  if (m > n) {
    r = (n - 1) / 2;
    c = (n - 1) / 2 + 1;
    dir = 0;
    l = 1;
    w = m - n + 1;
    neis = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  } else {
    r = (m - 1) / 2;
    c = (m - 1) / 2 + 1;
    dir = 0;
    l = n - m + 1;
    w = 1;
    neis = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  }

  while (r >= 0 && r < m && c >= 0 && c < n) {
    for (int i = 0; i < ((dir & 1) ? w : l); i++) {
      cout << matrix[r][c] << " ";
      r += neis[dir].first;
      c += neis[dir].second;
    }
    dir++;
    if (dir == 4) {
      l += 2;
      w += 2;
      dir = 0;
      if (neis[0].first == 1) {
        r--; c++;
      } else {
        r--;
      }
    }
  }

  cout << endl;
}

int main(int argc, char const* argv[])
{
  vector<vector<int>> matrix;
  int num = 1;
  for (int i = 0; i < 2; i++) {
    vector<int> row;
    for (int j = 0; j < 4; j++) {
      cout << num << " ";
      row.push_back(num++);
    }
    matrix.push_back(row);
    cout << endl;
  }
  PrintOuterToInner(matrix);
  //PrintInnerToOuter(matrix);
  return 0;
}
