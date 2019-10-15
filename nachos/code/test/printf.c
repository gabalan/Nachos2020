//
// Created by nlesne on 10/10/2019.
//

#include "syscall.h"
#include "lib/vsprintf.h"

int main(){
  printf("testing flags and varargs number:%d string:%s Hex:%x Octal:%o Char:%c%c", 156, "test", 56, 777, 'c', '\n');
  printf("%s", "very very very very very very very very very very long string to test truncate behaviour,"
               "it should stop printing after this.<--\n"
               "this should not be displayed");
  Exit(0);
}