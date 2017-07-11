#include "text_justification.h"
#include <fstream>
#include <sstream>

int main(int argc, char const* argv[])
{
  // read words from file
  ifstream input("input.txt");
  vector<string> words;
  string line, word;
  while (getline(input, line)) {
    stringstream linestream(line);
    while (linestream >> word) {
      words.emplace_back(word);
    }
  }

  Solution s;
  while (1) {
    cout << "input page_width:";
    int page_width;
    cin >> page_width;
    cout << endl;
    if (page_width == 0)
      return 0;

    auto lines = s.Justification(words, page_width);
    for (int i = 0; i < page_width; i++)
      cout << "-";
    cout << endl;
    for (auto& line : lines) {
      int width_word = accumulate(line.begin(), line.end(), 0, [](int a, string& b) { return a + b.size(); });
      if (line.size() == 1) {
        cout << line[0] << endl;
        continue;
      }
      int space = page_width - width_word, one_more_space = space % (line.size() - 1), indent = space / (line.size() - 1);
      int cnt = 0;
      for (int j = 0; j < line.size(); j++) {
        string& word = line[j];
        cout << word;
        // print space
        for (int i = 0; i < indent && j + 1 != line.size(); i++)
          cout << " ";
        //i
        if (cnt < one_more_space && one_more_space && ((j % ((line.size() - 1) / one_more_space)) == 0) && j != line.size() - 1) {
          cout << " ";
          cnt++;
        }

      }
      cout << endl;
    }
    for (int i = 0; i < page_width; i++)
      cout << "-";
    cout << endl << endl;

  }

  return 0;
}
