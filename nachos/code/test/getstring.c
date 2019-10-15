#include "syscall.h"
int
main ()
{
  char s[128];
  GetString(s,-1); // value will be ignored, syscall will print a warning
  PutString(s);

  GetString(s, 1024); // size value will be set to MAX_STRING_SIZE, will print a warning
  PutString(s);


  Exit(0);

}
