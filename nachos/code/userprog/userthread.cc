#ifdef CHANGED
//
// Created by nlesne on 17/10/2019.
//

#include "userthread.h"

int numActiveThreads = 0;

int do_ThreadCreate(int f, int arg)
{
  Thread* newThread = new Thread("newThread");
  Thread_args* schmurtz = new Thread_args(f,arg);
  newThread->Start(StartUserThread, schmurtz);
  numActiveThreads++;
  return 0;
}
void StartUserThread(void *schmurtz)
{
  DEBUG('s', "StartUserThread call\n");
  int f = ((Thread_args*)schmurtz)->f;
  int arg = ((Thread_args*)schmurtz)->arg;
  DEBUG('s', "f:%d ; arg:%d\n",f,arg);

  machine->WriteRegister(PCReg, f);
  machine->WriteRegister(4, arg);
  machine->WriteRegister(NextPCReg, f + 4);
  machine->WriteRegister(StackReg,currentThread->space->AllocateUserStack());

  machine->Run();
}
void do_ThreadExit()
{
  numActiveThreads--;
  currentThread->Finish();
  if (numActiveThreads == 0)
    interrupt->Halt();
}

#endif
