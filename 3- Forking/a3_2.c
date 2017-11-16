#include<stdio.h>
#include <unistd.h>
main()
{ printf("Before Exec()");
execl("a3.c/wc","wc",(char*)0);
printf("After");
}
