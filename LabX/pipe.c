#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int fd[2];

 //f[0]-read
//f[1]-write
 pid_t pid;
 if(pipe(fd)==-1){
 printf("An error occured with opening the pip\n");
 return 1;
}
pid=fork();
if(pid==0){
close(fd[0]);
 int Fuel=70;
int x;
 printf("We have 70 fuel to travel,how much do you need for your trip?");
 scanf("%d",&x);
x=70-x;
 write(fd[1],&x,sizeof(int));
 close(fd[1]);
}
else {
 close(fd[1]);
  int y;
 read(fd[0],&y,sizeof(int));
close(fd[0]);
 
printf("Got from child process %d\n",y);
}
return 0;
}

