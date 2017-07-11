#include "trie.h"
#include <limits.h>
#include <gtest/gtest.h>

using namespace std;

TEST(Trie, Sample) {
  Trie trie;
  EXPECT_EQ(false, trie.isWord("hello"));
  EXPECT_EQ(false, trie.isWord("world"));
  EXPECT_EQ(false, trie.isWord("unix"));
  EXPECT_EQ(false, trie.isWord("programming"));
}

TEST(Trie, Add) {
  Trie trie;

  trie.addWord("today");
  trie.addWord("hello");

  EXPECT_EQ(true, trie.isWord("hello"));
  EXPECT_EQ(true, trie.isWord("today"));
  EXPECT_EQ(true, trie.isWordRec("hello"));
  EXPECT_EQ(true, trie.isWordRec("today"));
  EXPECT_EQ(false, trie.isWord("unix"));
  EXPECT_EQ(false, trie.isWord("programming"));
}




