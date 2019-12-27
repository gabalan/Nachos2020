#ifdef CHANGED
#include "userfork.h"
#include "thread.h"
#include "addrspace.h"
#include "system.h"
#include "console.h"

int nextPID = 0;

void StartForkedProcess(void *arg)
{
  AddrSpace *s = (AddrSpace *) arg;
  currentThread->space = s;
  currentThread->space->InitRegisters();
  currentThread->space->RestoreState();
  machine->Run();
  ASSERT(false);
}

int do_ForkExec(char *s)
{
  OpenFile *executable = fileSystem->Open(s);
  if (executable == nullptr)
    {
      SetColor(stdout, ColorRed);
      SetBold(stdout);
      printf("Unable to open file %s\n", s);
      ClearColor(stdout);
      Exit(1);
    }
  AddrSpace *space = new AddrSpace(executable);

  char semName[24] = "userProcess_";
  char id_string[10];
  snprintf(id_string, 10, "%d", nextPID++);
  strcat(semName, id_string);
  Thread *thread = new Thread(semName); //thread noyau
  nbProcess++;
  thread->Start(StartForkedProcess, (void *) space);
  delete executable;
  return 0;
}

int do_ProcessExit()
{
  nbProcess--;

  if (currentThread->space->getNumThreads() > 1)
    currentThread->space->finishThreads();
  //delete currentThread->space;
  if (nbProcess == 0)
      interrupt->Halt();
  else
      currentThread->Finish();
}

#endif 