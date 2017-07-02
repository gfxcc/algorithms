#include <yong/head.h>

class Solution {
public:
  struct Node {
    Node(int v) : val(v) {}
    int val;
    vector<Node*> off_spring;
    Node* sibling = nullptr;

  };

  //        N      ->        N
  //   N -> N -> N  ->   N    ->     N
  //
  void BuildSibling(Node* root) {
    Node* prev = nullptr, *head = root;
    while (prev || head) {
      if (!prev) {
        prev = head;
        head = nullptr;
      } else {
        if (!head && prev->off_spring.size()) {
          head = prev->off_spring[0];
        }
        // connect prev node's offstring's sibling
        for (int i = 0; i + 1 < prev->off_spring.size(); i++) {
          prev->off_spring[i]->sibling = prev->off_spring[i + 1];
        }
        // find next node in prev's level
        Node* next = prev->sibling;
        while (next && next->off_spring.size() == 0) {
          next = next->sibling;
        }
        if (next)
          prev->off_spring.back()->sibling = next->off_spring[0];
        prev = next;
      }
    }
  }
};


