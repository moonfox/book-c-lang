#include <stdio.h>

int main(int argc, char const *argv[])
{
  /* code */
  const char msg[] = "warning: ";
  printf("msg is %s\n", msg);

  // error: read-only variable is not assignable
  msg[1] = 'b';

  printf("msg is %s\n", msg);
  return 0;
}
