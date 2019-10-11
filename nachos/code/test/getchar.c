#include "syscall.h"

int // la valeur de retour d'un main est nécessairement un int sinon le compilateur génère une erreur
main ()
{
 GetChar();
  return 0;
}
