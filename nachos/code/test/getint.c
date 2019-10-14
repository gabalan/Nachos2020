#include "syscall.h"
#include "lib/vsprintf.h"

int main(){
	
    int entier;
    if (GetInt(&entier))
      PutInt(entier);
    else
      printf("Error : Input is not a number\n");
    return 0;
}
