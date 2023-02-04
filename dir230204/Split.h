#ifndef MYLIB_SPLIT_H_
#define MYLIB_SPLIT_H_

#include <string>
#include <sstream>
#include <vector>

namespace Mylib
{
  /// @brief 区切り文字を含む文字列を分割してコンテナ化する
  /// @param target_str 区切り文字を含む文字列
  /// @param delimiter 区切り文字
  /// @return 分割後のコンテナ
  auto Split(std::string const &target_str, char delimiter) -> std::vector<std::string>;
}

#endif // MYLIB_SPLIT_H_