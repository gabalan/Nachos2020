//
// Created by nlesne on 18/10/2019.
//

#include "syscall.h"
#include "lib/vsprintf.h"

#define DATA_LENGTH 50
#define THREAD_PAIRS 1
int buffer;
sem_t cons;
sem_t prod;
sem_t mutex;
sem_t cons_done;

void producer()
{
  int i;
  for (i = 0; i < DATA_LENGTH; i++)
    {
      SemWait(prod);
      SemWait(mutex);
      buffer = i;
      printf("Produced : %d\n", buffer);
      SemPost(mutex);
      SemPost(cons);
    }
}

void consumer()
{
  int i;
  for (i = 0; i < DATA_LENGTH; i++)
    {
      SemWait(cons);
      SemWait(mutex);
      printf("Consumed : %d\n", buffer);
      SemPost(mutex);
      SemPost(prod);
    }
    SemPost(cons_done);
}

int main()
{
  int i;
  prod = SemInit(1);
  cons = SemInit(0);
  mutex = SemInit(1);
  cons_done = SemInit(1-THREAD_PAIRS);


  for (i = 0; i < THREAD_PAIRS; i++)
    {
      ThreadCreate(producer,0);
      ThreadCreate(consumer,0);
    }

  SemWait(cons_done);

  SemDestroy(prod);
  SemDestroy(cons);
  SemDestroy(mutex);
  SemDestroy(cons_done);

  return 0;
}
