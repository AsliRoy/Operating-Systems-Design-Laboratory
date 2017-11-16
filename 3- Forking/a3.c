#include<stdio.h>
#include <unistd.h>
main()
{ printf("Before Exec()");
execl("/bin/ls","ls","-l",(char*)0);
printf("After");
}
