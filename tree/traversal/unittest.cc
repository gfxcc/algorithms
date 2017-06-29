#include "traversal.h"
#include <limits.h>
#include <gtest/gtest.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

TEST(ExampleTest, PreOrder) {
  srand (time(NULL));
  vector<int> vals;
  for (int i = 100; i >= 0; i--) {
    vals.push_back(rand() % 1000);
  }
  cout << "Random Tree:";
  for (auto val : vals)
    cout << val << ", ";
  cout << endl;
  TreeNode* root = BuildTree(vals);
  auto vec = PreOrder(root);
  auto vec_ = PreOrderRec(root);
  EXPECT_EQ(vec, vec_);
}

TEST(ExampleTest, InOrder) {
  srand (time(NULL));
  vector<int> vals;
  for (int i = 100; i >= 0; i--) {
    vals.push_back(rand() % 1000);
  }
  cout << "Random Tree:";
  for (auto val : vals)
    cout << val << ", ";
  cout << endl;

  TreeNode* root = BuildTree(vals);
  auto vec = InOrder(root);
  auto vec_ = InOrderRec(root);
  EXPECT_EQ(vec, vec_);
}

TEST(ExampleTest, PostOrder) {
  srand (time(NULL));
  vector<int> vals;
  for (int i = 100; i >= 0; i--) {
    vals.push_back(rand() % 1000);
  }
  cout << "Random Tree:";
  for (auto val : vals)
    cout << val << ", ";
  cout << endl;

  TreeNode* root = BuildTree(vals);
  auto vec = PostOrder(root);
  auto vec_ = PostOrderRec(root);
  EXPECT_EQ(vec, vec_);

}




