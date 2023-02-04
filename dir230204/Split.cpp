#include "Split.h"

namespace Mylib
{
  auto Split(std::string const &target_str, char delimiter) -> std::vector<std::string>
  {
    // 読み取る対象として文字列ストリームを定義
    std::istringstream target_sstream(target_str);
    // 分割後の文字列要素
    std::string split_str;
    // 分割後の文字列コンテナ
    std::vector<std::string> vector_str;

    while (std::getline(target_sstream, split_str, delimiter))
      vector_str.push_back(split_str);

    return vector_str;
  }
}