#include "syscall.h"
void writeString(char *s){
	int i;
	for(i=0;i<3;i++){PutString((char*)s);}

	ThreadExit();

}
int main () {
	PutString("aaaa\n");
    return 0;
}
