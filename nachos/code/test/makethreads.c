//
// Created by nlesne on 18/10/2019.
//

#include "syscall.h"
#include "lib/vsprintf.h"

void threadTest()
{
  PutChar('s');
  ThreadExit();
}

int main()
{
  ThreadCreate(threadTest, 0);
  while (1) {}
}
