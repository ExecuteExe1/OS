#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>




int main() {
 
 int pid;
pid=fork();
if(pid<0){
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if(pid==0){ //child here 
int x;
 printf("What do  you like more? 1.Reindeer 2.Snowball 3.Jingle Bells");
scanf("%d",&x);
 if(x==1){
 while(1){
   printf("Reindeers are the best!\n");
}
}
 else if(x==2){
  while(1){
  printf("Snowballs are fun!\n");
}
}
 else{
  while(1){
    printf("Jingle my balls~ :D\n");
}
}
}
 else { //parent
sleep(4);
 printf("Ok enough!Christmas is over!");
        kill(pid, SIGTERM);

}
return 0;
}

