#ifdef CHANGED
//
// Created by nlesne on 17/10/2019.
//

#include "userthread.h"
#include "userfork.h"

static void StartUserThread(void *schmurtz);

int do_ThreadCreate(int f, int arg, int exit_func)
{
  if (currentThread->space->isStackFull())
    return -1;
  Thread* newThread = new Thread("UThread");
  Thread_args* schmurtz = new Thread_args(f, arg, exit_func);
  newThread->Start(StartUserThread, schmurtz);
  return 0;
}
void StartUserThread(void *schmurtz)
{
  DEBUG('s', "StartUserThread call: ");
  int f = ((Thread_args*)schmurtz)->f;
  int arg = ((Thread_args*)schmurtz)->arg;
  int exit_func = ((Thread_args*)schmurtz)->exit_func;
  DEBUG('s', "f:%d ; arg:%d\n",f,arg);
  delete (Thread_args*)schmurtz;

  for (int i = 0; i < NumTotalRegs; i++)
    machine->WriteRegister(i,0);

  machine->WriteRegister(PCReg, f);
  machine->WriteRegister(4, arg);
  machine->WriteRegister(NextPCReg, f + 4);
  machine->WriteRegister(RetAddrReg, exit_func);
  int userStackLocation = currentThread->space->AllocateUserStack(&currentThread->bitmapLocation);
  machine->WriteRegister(StackReg,userStackLocation);

  machine->Run();
}
void do_ThreadExit()
{
  currentThread->space->DeallocateUserStack(currentThread->bitmapLocation);
  if (currentThread->space->getNumThreads() == 0)
    {
      nbProcess--;
      //delete currentThread->space;
    }
  currentThread->Finish();
}

#endif
