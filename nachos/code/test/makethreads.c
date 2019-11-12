//
// Created by nlesne on 12/11/2019.
//

/*
 * Ce programme teste l'implémentation des threads utilisateurs
 * Il permet de voir comment passer des arguments aux fonctions des threads,
 * ainsi qu'un moyen pour le main d'attendre les threads lancés à l'aide d'une sémaphore.
 * A partir de NB_THREADS > 1 les threads ne se lancent pas.
 *
 * Pour executer, en étant dans userprog:
 * ./nachos -x test/makethreads
 */

#include "syscall.h"
#include "lib/vsprintf.h"

#define NB_THREADS 1

void print_test(char *arg)
{
  PutString(arg);
}

int main()
{
  int i;
  for (i = 0; i < NB_THREADS; i++)
    {
      ThreadCreate(print_test,"userthread\n");
    }
  PutString("mainThread\n");
  return 0;
}