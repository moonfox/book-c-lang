#include <stdio.h>

void lower(char s[]);

int main(int argc, char const *argv[])
{
  char s[] = "HELLO WORld";
  lower(s);
  printf("convert 'HELLO WORld' to lower is %s\n", s);

  return 0;
}

void lower(char s[])
{
  char c;
  for (int i = 0; s[i] != '\0'; i++)
  {
    c = s[i];
    if (c >= 'A' && c <= 'Z')
      s[i] = c + 'a' - 'A';
  }
}
