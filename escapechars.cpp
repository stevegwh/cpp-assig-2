#include<iostream>
#include<string>
#include <ctype.h>

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

int main(int argc, char *argv[])
{
  char ch;
  while(std::cin.get(ch)) {
    std::cout << escapeChars(ch);
  }

  return 0;
}
