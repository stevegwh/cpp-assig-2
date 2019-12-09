#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

std::string escapeChars(char ch) 
{
  if (isdigit(ch)) {
    std::string s = "\\";
    return  s + ch;
  }
  switch(ch) {
    case('\\'):
      return "\\";
      break;
    case('\n'):
      return "\\n";
      break;
    case('\t'):
      return "\\t";
      break;
    case('\r'):
      return "\\r";
      break;
    case(' '):
      return "\\s";
      break;
    default:
    return std::string(1, ch);
  }
};

std::string escapeString(const std::string& str)
{
  std::string s;
  for (auto & i : str)  {
    s += escapeChars(i);
  }
  return s;
};


int main(int argc, char *argv[])
{
  char ch;
  std::string s;
  std::set<std::string> seen;
  while(std::cin.get(ch)) {
    s += ch;
    if (seen.insert(s).second) {
      std::cout << escapeString(s) << std::endl;
      s = "";
    }
  }
  if (s != "") std::cout << escapeString(s) << std::endl;
  return 0;
}
