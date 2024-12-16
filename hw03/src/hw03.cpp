#include <cstring>
#include <hw03.h>

void hw03(char* str, const char* pattern)
{

  if (*str == '\0') {
    return;
  }

  size_t patternLength = std::strlen(pattern);


  char* found = std::strstr(str, pattern);

  if (!found) {
    return;
  }

  std::memmove(found, found + patternLength, std::strlen(found + patternLength) + 1);
}
