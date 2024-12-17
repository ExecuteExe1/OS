#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
 const char *filename ="results.txt";
 int fd;
 int pid;
 fd=open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
 if(fd==-1){
 perror("Error opening file");
 exit(EXIT_FAILURE);
}
pid=fork();
if(pid==-1){
 perror("Error during fork");
 close(fd);
  exit(EXIT_FAILURE);
}

if(pid==0){
char child_msg[256];
        snprintf(child_msg, sizeof(child_msg), "Child: This is the child's result. PID: %d\n", getpid());
 if(write(fd,child_msg,strlen(child_msg))==-1){
 perror("Child Error writing");
 close(fd);
 exit(EXIT_FAILURE);
}
printf("Successfully wrote to the file{child}\n");
}
else{
wait(NULL);
char parent_msg[256];
        snprintf(parent_msg, sizeof(parent_msg), "Parent: This is the child's result. PID: %d\n", getpid());
if(write(fd,parent_msg,strlen(parent_msg))==-1){
 perror("Parent error writing to file");
close(fd);
exit(EXIT_FAILURE);
}
printf("Successful write{parent}\n");
}
 if(close(fd)==-1){
perror("Error closing");
exit(EXIT_FAILURE);
}
return 0;
}

