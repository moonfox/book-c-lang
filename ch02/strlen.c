#include <stdio.h>

int my_strlen(char *string);

int main(int argc, char const *argv[])
{
  // char *string;
  // string = "hello world haha";
  char string[] = "hello world haha";
  printf("The string '%s' len is \"%d\"\n", string, my_strlen(string));
  return 0;
}

int my_strlen(char s[])
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return i;
}