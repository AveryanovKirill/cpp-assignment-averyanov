#include <hw02.h>


std::string hw02(std::string str)
{
  std::string new_string = "";
  for (int i = 0; i < str.length(); i++)
  {
    if (new_string.find(str[i]) == std::string::npos)
      new_string += str[i];
  }
  return new_string;
}