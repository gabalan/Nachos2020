#ifdef CHANGED
//
// Created by nlesne on 17/10/2019.
//

#ifndef _USERTHREAD_H_
#define _USERTHREAD_H_

#include "system.h"
#include "thread.h"

struct Thread_args {
    int f;
    int arg;
    int exit_func;
    Thread_args(int new_f, int new_arg, int new_exit_func)
      : f(new_f), arg(new_arg), exit_func(new_exit_func) {}
};

extern int numActiveThreads;
extern int do_ThreadCreate(int f, int arg, int exit_func);
extern void do_ThreadExit();

#endif //_USERTHREAD_H_
#endif // CHANGED