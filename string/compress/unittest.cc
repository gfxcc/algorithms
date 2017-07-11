#include "compress.h"
#include <limits.h>
#include <gtest/gtest.h>

using namespace std;

TEST(ExampleTest, Sample) {
  Solution s;
  EXPECT_EQ("ab2c3", s.Compress("abbbcccc"));
  EXPECT_EQ("ababc", s.Compress("ababc"));
}



