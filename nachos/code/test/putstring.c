#include "syscall.h"

int
main ()
{
	PutString("String to test 128 char limit:\n"
           "CTmHqaRERtJgSllygRaPp5aG0lkMs943cTPlEWmMpwlOCP8l6Od4KMcYXJ40UU3atl39iPQWFoxgoJ9TZmc5QXeGhqyTROSt\n"
           "This should not be printed");
    return 0;
}