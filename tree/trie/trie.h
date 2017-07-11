#include <yong/head.h>

class Trie {
public:
  class Node {
  public:
    char c;
    bool isWord;
    vector<Node*> next;
    Node(char c) : c(c), isWord(false), next(26, NULL) {}
  };

  Trie() : root('a') {}

  bool isWord(const string& str) {
    Node* cur = &root;
    for (auto c : str) {
      if (cur->next[c - 'a'] == NULL)
        return false;
      cur = cur->next[c - 'a'];
    }
    return cur->isWord;
  }

  bool helper(const string& str, int i, Node* cur) {
    if (i == str.size() - 1)
      return cur->next[str[i] - 'a'] != NULL && cur->next[str[i] - 'a']->isWord;
    return cur->next[str[i] - 'a'] != NULL && helper(str, i + 1, cur->next[str[i] - 'a']);
  }

  bool isWordRec(const string& str) {
    return helper(str, 0, &root);
  }

  void addWord(const string& str) {
    Node* cur = &root;
    for (auto c : str) {
      if (cur->next[c - 'a'] == NULL)
        cur->next[c - 'a'] = new Node(c);
      cur = cur->next[c - 'a'];
    }
    cur->isWord = true;
  }



  Trie::Node root;
};
