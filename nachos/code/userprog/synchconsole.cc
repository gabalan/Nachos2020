#ifdef CHANGED
#include "copyright.h"
#include "console.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"
static Semaphore *readAvail;
static Semaphore *writeDone;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }
SynchConsole::SynchConsole(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    console   =  new Console (in, out,ReadAvailHandler ,WriteDoneHandler, 0);
}
SynchConsole::~SynchConsole()
{
    delete console;
    delete writeDone;
    delete readAvail;
}
void SynchConsole::SynchPutChar(int ch)
{
  console->PutChar(ch);
  writeDone->P();
	
}
int SynchConsole::SynchGetChar()
{
   readAvail->P();
   int c = console->GetChar();
   return c;
}
void SynchConsole::SynchPutString(const char s[])
{
  int i=0;
  while (s[i]!='\0'){
    SynchPutChar(s[i]);
    i++;
  }
  
}
void SynchConsole::SynchGetString(char *s, int n)
{
  int i = 0;
  int c = 0;
  while (i < n && c != EOF && c != '\n')
    {
      c = SynchGetChar();
      s[i] = (char)c;
      i++;
    }
    if (c == EOF)
      i--;

    s[i] = '\0';

}
void SynchConsole::SynchPutInt(int n)
{
  char* str = new char[MAX_STRING_SIZE];
  snprintf(str, MAX_STRING_SIZE, "%i", n);
  SynchPutString(str);
  delete[] str;
}
void SynchConsole::SynchGetInt(int *n)
{
  char* str = new char[MAX_STRING_SIZE];
  SynchGetString(str, MAX_STRING_SIZE);
  sscanf(str, "%i", n);
  delete[] str;
}
#endif // CHANGED
