#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Function to add two integers using pointers

int main() {
    int a,b;
   int *p;
 p=&a;
a=5;
printf("Pointer address:%p Pointer Value{points at a}%d\n",&p,*p);
printf("A adress: %p  A value:%d\n",&a,a);
printf("Let;s change A value via p");
*p=10;
printf("\n A value:%d",a);
//to point on adress no * to change value yes *
return 0;
}

