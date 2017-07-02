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
      int space = page_width - width_word, one_more_pace = space % (line.size() - 1), indent = space / (line.size() - 1);
      for (auto& word : line) {
        cout << word;
        // print space
        for (int i = 0; i < indent; i++)
          cout << " ";
        if (one_more_pace) {
          cout << " ";
          one_more_pace--;
        }
      }
      cout << endl;
    }
  }

  return 0;
}
