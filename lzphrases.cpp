#include <iostream>
#include <string>
#include <vector>
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
  // TODO: Check if this is correct.
  if (isspace(ch)) {
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
  std::string s;
  std::vector<std::string> seen;
  while(std::cin.get(ch)) {
    s += ch;
    if(std::find(std::begin(seen), std::end(seen), s) == std::end(seen)) {
      seen.push_back(s);
      std::cout << escapeString(s) << std::endl;
      s = "";
    }
  }
  return 0;
}
