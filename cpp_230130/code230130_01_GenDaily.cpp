#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

namespace Daily
{
  /// @brief 区切り文字を含む文字列を分割してコンテナ化する
  /// @param target_str 区切り文字を含む文字列
  /// @param delimiter 区切り文字
  /// @return 分割後のコンテナ
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

  /// @brief ランダムな整数（0~(length-1)）を生成
  /// @param length 例えばコンテナのサイズ
  /// @return 例えばコンテナのランダムなインデックス
  auto GenRandom(int length) -> int
  {
    // 擬似乱数生成エンジンのシード初期化を行う、非決定論的な乱数生成エンジン
    std::random_device gen_seed;
    // std::random_device::operator() 非決定論的な乱数の生成を行う
    // mersenne_twister_engineのパラメータ設定済み別名であるmt19937を使用する。
    // std::mersenne_twister_engine::operator() 擬似乱数の生成を行う
    // シード値を指定して再初期化
    std::mt19937 engine(gen_seed());

    // 分布の最小最大値を決定
    int const kLowerBound = 0;
    int const kUpperBound = length - 1;

    // 抽選結果の数字を等確率でランダムに生成する分布
    std::uniform_int_distribution<> dist(kLowerBound, kUpperBound);

    return dist(engine);
  }

  /// @brief vector の要素順をシャッフル
  /// @tparam T 要素の型
  /// @param list シャッフルする vector
  template <typename T>
  void ShuffleList(std::vector<T> &list)
  {
    std::random_device gen_seed;
    std::mt19937 engine(gen_seed());
    std::shuffle(list.begin(), list.end(), engine);
  }
}

/// @brief csv ファイル中のリストからランダムなデイリーミッションを表示する
/// @return 0: 正常終了
auto main() -> int
{
  std::ifstream ifs("list_daily_mission.csv");
  // １行（１分野）
  std::string row_str;
  // デイリーミッションリスト
  std::vector<std::string> list_daily;
  // 全行（全分野）に渡って
  while (std::getline(ifs, row_str))
  {
    std::vector<std::string> elems_str_in_row = Daily::Split(row_str, ',');
    // １行（１分野）の中からランダムに１つ抽出する
    list_daily.push_back(elems_str_in_row.at(Daily::GenRandom(elems_str_in_row.size())));
  }
  // デイリーミッションリストの順番をシャッフル
  Daily::ShuffleList(list_daily);
  std::cout << '\n';
  // デイリーミッションを表示
  for (int i = 0; i < static_cast<int>(list_daily.size()); i++)
    std::cout << i + 1 << ": " << list_daily[i] << '\n';
  std::cout << std::flush;
}
