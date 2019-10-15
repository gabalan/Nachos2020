#include "syscall.h"
#include "lib/vsprintf.h"

int
main ()
{
  printf("PutInt overflow test :\n-2147483649 overflows to 2147483647 ->\n");
  PutInt(-2147483649);
  printf("\n2147483648 overflows to -2147483648 ->\n");
  PutInt(2147483648); // Overflow to -2147483648
  printf("\nEnd of PutInt overflow test\n");
    return 0;
}