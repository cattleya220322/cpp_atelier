// <a href="https://koshinran.hateblo.jp/entry/2018/04/04/234111">C++_ std::setprecision と std::fixed ( 桁数指定 )</a>

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <vector>
#include <string>

namespace Tmp
{
  // type alias
  using vector2d = std::vector<std::vector<double>>;

  template <typename T, typename U>
  auto Add(T const &lhs, U const &rhs) -> decltype(lhs + rhs)
  {
    return lhs + rhs;
  }
}

auto main() -> int
{
  auto result = Tmp::Add(11, 3.14);
  std::cout << typeid(11 + 3.14).name() << std::endl;
  std::cout << typeid(result).name() << std::endl;
  if (typeid(11 + 3.14) == typeid(result))
    std::cout << "same" << std::endl;
  std::ios::fmtflags flg_saved = std::cout.flags();
  std::cout << std::fixed << std::scientific << std::setprecision(3) << result << std::endl;
  std::cout.flags(flg_saved);

  Tmp::vector2d v2d{{1, 2.2}, {3, 4.4}};
  auto rlt_2 = Tmp::Add(v2d[0][0], v2d[1][1]);
  for (auto const &row : v2d)
  {
    for (auto const &e : row)
      std::cout << e << ' ';
    std::cout << '\n';
  }
  std::cout << rlt_2 << std::endl;

  std::string first_name = "yuri";
  auto rlt_3 = Tmp::Add(first_name, "ebihara");
  std::cout << typeid(rlt_3).name() << ": " << rlt_3 << std::endl;
}
