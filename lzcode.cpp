#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

std::string escapeChars(char ch) 
{
  if (ch == '\\') {
    return "\\";
  }
  if (isdigit(ch)) {
    std::string s = "\\";
    return  s + ch;
  }
  if (ch == '\n') {
    return "\\n";
  }
  if (ch == '\t') {
    return "\\t";
  }
  if (ch == '\r') {
    return "\\r";
  }
  if (ch == ' ') {
    return "\\s";
  }
  return std::string(1, ch);
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
  int i = 1;
  std::string s;
  std::set<std::string> seen;
  std::map<std::string, unsigned int> serials;
  serials[""] = 0;
  while(std::cin.get(ch)) {
    std::string copy = s;
    s += ch;
    if (seen.insert(s).second) {
      serials[s] = i;
      std::cout << std::to_string(serials[copy]) + escapeChars(ch) << std::endl;
      i++;
      s = "";
    }
  }
  return 0;
}
