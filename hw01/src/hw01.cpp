#include <hw01.h>

int hw01(int start, int end)
{
  if (start <= 9 || end >= 100)
    return -1;
  int sum = 0;
  for (int i = start; i <= end; i++)
  {
    bool is_simple = true;
    for (int j = 2; j < i; j++)
    {
      if (i % j == 0)
        is_simple = false;
    }
    if (is_simple)
    {
      sum = sum + i % 10 + i / 10;
    }
  }
  return sum;
}

