#ifdef CHANGED
#include "userfork.h"
#include "thread.h"
#include "addrspace.h"
#include "synch.h"
#include "system.h"
#include "console.h"


void StartProcess(void* arg){
   AddrSpace *s =(AddrSpace *)arg; 
	currentThread->space = s;
	currentThread->space->InitRegisters ();	
  currentThread->space->RestoreState ();
  machine->Run ();		
}

int do_ForkExec(char *s){
	OpenFile *executable = fileSystem->Open(s);
    if (executable == NULL)
      {
	  SetColor (stdout, ColorRed);
	  SetBold (stdout);
	  printf ("Unable to open file %s\n",s);
	  ClearColor (stdout);
	  Exit(1);
      }
    AddrSpace *space = new AddrSpace(executable); 
    Thread* thread = new Thread("newProcess"); //thread noyau
    thread->Start(StartProcess,(void*)space); 
    delete executable;
	return 0;
}

#endif 