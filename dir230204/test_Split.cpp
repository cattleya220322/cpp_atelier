#include <gmock/gmock.h>
#include "Split.h"

TEST(testsuite, test1)
{
  std::string in_str = "yuri,ebihara";
  char delimiter = ',';
  std::vector<std::string> exp_vstr = {"yuri", "ebihara"};
  EXPECT_THAT(Mylib::Split(in_str, delimiter), testing::Eq(exp_vstr));
}

TEST(testsuite, test2)
{
  std::string in_str = "ふしぎ/できごと/わくわく/ドキドキ";
  char delimiter = '/';
  std::vector<std::string> exp_vstr = {"ふしぎ", "できごと", "わくわく", "ドキドキ"};
  EXPECT_THAT(Mylib::Split(in_str, delimiter), testing::Eq(exp_vstr));
}