#include <stdio.h>

int atoi(char s[]);

int main(int argc, char const *argv[])
{
  char s[] = "1234560";
  printf("convert '%s' to int is %d\n", s, atoi(s));
  return 0;
}

int atoi(char s[])
{
  int n = 0;
  for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++)
  {
    n = 10 * n + (s[i] - '0');
    printf("'%c', int %d\n", s[i], s[i]);
  }
  return n;
}