#ifdef CHANGED
//
// Created by nlesne on 10/11/2019.
//
#ifndef USERSEMAPHORE_H
#define USERSEMAPHORE_H
#include "synch.h"

extern int semListCapacity;
extern Semaphore** semList;
extern unsigned int nextSemId;

extern unsigned int do_semInit(int value);
extern int do_semDestroy(int semId);
extern int do_semWait(int semId);
extern int do_semPost(int semId);

#endif //USERSEMAPHORE_H
#endif //CHANGED
