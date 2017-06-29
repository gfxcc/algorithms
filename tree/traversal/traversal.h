#include <yong/tree.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> PreOrder(TreeNode* root) {
  vector<int> ret;
  stack<TreeNode*> st;
  TreeNode* cur = root;
  while (!st.empty() || cur) {
    while (cur) {
      ret.push_back(cur->val);
      st.push(cur->right);
      cur = cur->left;
    }
    cur = st.top(); st.pop();
  }
  return ret;
}

vector<int> InOrder(TreeNode* root) {
  vector<int> ret;
  stack<TreeNode*> st;
  TreeNode* cur = root;
  while (!st.empty() || cur) {
    while (cur) {
      st.push(cur);
      cur = cur->left;
    }
    cur = st.top(); st.pop();
    ret.push_back(cur->val);
    cur = cur->right;
  }
  return ret;
}

vector<int> PostOrder(TreeNode* root) {
  vector<int> ret;
  stack<TreeNode*> st;
  TreeNode* cur = root;
  while (!st.empty() || cur) {
    while (cur) {
      st.push(cur);
      cur = cur->left ? cur->left : cur->right;
    }
    cur = st.top(); st.pop();
    ret.push_back(cur->val);
    if (st.size() && cur == st.top()->left)
      cur = st.top()->right;
    else
      cur = nullptr;
  }
  return ret;
}

void PreHelper(TreeNode* cur, vector<int>& ret) {
  if (!cur)
    return;
  ret.push_back(cur->val);
  PreHelper(cur->left, ret);
  PreHelper(cur->right, ret);
}
vector<int> PreOrderRec(TreeNode* root) {
  vector<int> ret;
  PreHelper(root, ret);
  return ret;
}

void InHelper(TreeNode* cur, vector<int>& ret) {
  if (!cur)
    return;
  InHelper(cur->left, ret);
  ret.push_back(cur->val);
  InHelper(cur->right, ret);
}
vector<int> InOrderRec(TreeNode* root) {
  vector<int> ret;
  InHelper(root, ret);
  return ret;
}

void PostHelper(TreeNode* cur, vector<int>& ret) {
  if (!cur)
    return;
  PostHelper(cur->left, ret);
  PostHelper(cur->right, ret);
  ret.push_back(cur->val);
}
vector<int> PostOrderRec(TreeNode* root) {
  vector<int> ret;
  PostHelper(root, ret);
  return ret;
}
