#include "syscall.h"
int
main ()
{
  int overflow_size = 256;
  char s[overflow_size];
  GetString(s,overflow_size); // value will be ignored and replaced by MAX_STRING_SIZE
  PutString(s);
  Exit(0);

}
