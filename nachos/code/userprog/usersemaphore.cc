#ifdef CHANGED
//
// Created by nlesne on 10/11/2019.
//

#include "usersemaphore.h"
int semListCapacity = 10;
unsigned int nextSemId = 0;
Semaphore** semList = (Semaphore**)malloc(semListCapacity * sizeof(Semaphore*));

void testAndResize()
{
  if (nextSemId >= semListCapacity)
    {
      semListCapacity += 10;
      semList = (Semaphore**)realloc(semList, semListCapacity * sizeof(Semaphore*));
    }
}
unsigned int do_semInit(int value)
{
  testAndResize();
  char semName[20] = "userSem_";
  char id_string[10];
  sprintf(id_string, "%d", nextSemId);
  strcat(semName, id_string);
  semList[nextSemId] = new Semaphore(semName,value);
  return nextSemId++;
}
int do_semDestroy(int semId)
{
  if (semList[semId] != nullptr)
    {
      delete semList[semId];
      return 0;
    }
  else
    return -1;
}
int do_semWait(int semId)
{
  if (semId < semListCapacity && semList[semId] != nullptr)
      semList[semId]->P();
  else
      return -1;
  return 0;
}
int do_semPost(int semId)
{
  if (semId < semListCapacity && semList[semId] != nullptr)
    semList[semId]->V();
  else
    return -1;
  return 0;
}
#endif //CHANGED
