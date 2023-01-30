#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
  std::string path_home = std::getenv("HOME");
  std::cout << path_home << std::endl;

  std::string str{"~/atelier"};
  std::string target_str{"~"};
  auto pos = str.find(target_str);
  str.replace(pos, target_str.length(), path_home);

  std::cout << str << std::endl;
}
