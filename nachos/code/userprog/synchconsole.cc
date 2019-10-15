#ifdef CHANGED
#include <cctype>
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
void SynchConsole::SynchPutString(const char str[])
{
  int i=0;
  while (str[i]!='\0'){
    SynchPutChar(str[i]);
    i++;
  }
  
}
void SynchConsole::SynchGetString(char *s, int n)
{
  if (n <= 0)
    return;

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
  char* str = new char[MAX_INT_LENGTH];
  snprintf(str, MAX_INT_LENGTH, "%i", n);
  SynchPutString(str);
  delete[] str;
}
bool SynchConsole::SynchGetInt(int *n)
{
  char* str = new char[MAX_INT_LENGTH];
  SynchGetString(str, MAX_INT_LENGTH);
  bool isInt = true;
  int i = 0;
  // Testing if every char is a digit or a space
  while (isInt && str[i] != '\0' && i < MAX_INT_LENGTH)
    {
      isInt = isdigit(str[i]) || isspace(str[i]);
      i++;
    }
    if (isInt)
      sscanf(str, "%i", n);
  delete[] str;
  return isInt; // Returns true if input is an Integer
}
#endif // CHANGED
