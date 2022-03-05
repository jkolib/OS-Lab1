#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// establishing type 1 commands
char hello[] = "hello";
char bye[] = "bye";
char assignment[] = "assignment";
char author[] = "author";
char section[] = "section";


int main(void) {
  // creating container for input
  char inp[51];

  // main loop for getting commands
  while(1){
    // getting command from user
    fgets(inp, 50, stdin);

    // replacing \n with \0
    for(int i = 0; i<51; i++){
      if(inp[i] == '\n'){
        inp[i] = '\0';
        break;
      }
    }// for

    // executing type 1 commands if given
    if(strcmp(inp, hello)==0){
      printf("Hello, how are you?\n");
    }
    else if(strcmp(inp, bye)==0){
      printf("Terminating...\n");
      exit(0);
    }
    else if(strcmp(inp, assignment)==0){
      printf("202 lab #1 (Spring 2022)\n");
    }
    else if(strcmp(inp, author)==0){
      printf("John Kolibachuk, N10204381, jdk493\n");
    }
    else if(strcmp(inp, section)==0){
      printf("003\n");
    }

    // handling type 2 commands
    else{
      int status;
      int parentOrChild = fork();

      // executed by child process
      if(parentOrChild == 0){
        // getting directory for executable
        char dir[56] = "/bin/";
        strcat(dir, inp);

        // creating arg and environment pointers
        char *argv[] = {inp, NULL};
        char *env[] = {NULL};

        // executing command and exiting
        execve(dir, argv, env);
        exit(0);
      }

      // parent waits for child to finish
      else{
        wait(&status);
      } // if else
    }// if else
  }// while
}// main
