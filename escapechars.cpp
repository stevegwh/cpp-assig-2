#include<iostream>
#include<string>
#include <ctype.h>

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

int main(int argc, char *argv[])
{
  char ch;
  while(std::cin.get(ch)) {
    std::cout << escapeChars(ch);
  }

  return 0;
}
