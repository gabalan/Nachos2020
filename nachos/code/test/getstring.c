#include "syscall.h"
#define size 256
int // la valeur de retour d'un main est nécessairement un int sinon le compilateur génère une erreur
main ()
{
  char s[size+1];
    GetString(s,size+1);
    PutString(s); // à decommenter pour "echo"  la chaine saisie
    /* not reached */
  return 0;

}
