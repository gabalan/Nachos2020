#include "syscall.h"

int main(){
	
    int entier;
    GetInt(&entier);
    PutInt(entier); //à décommenter si on veut voir que l'affectation de i fonctionne
    return 0;
}