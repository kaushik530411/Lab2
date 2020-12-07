/*
 *This file implements all the functionalities required by Lab2.
 */

// Imports
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ITERATION 31
#define MAX_SLEEP_TIME 11

// Function prototypes
void  ChildProcess();
void  ParentProcess();

void main() {
  // Seeding the random number generator
  srandom(1);
  pid_t pid;
  pid_t pid_2;
  
  // Initializing the first fork
  pid = fork(); 
  
  // Check for child or parent pid
  if (pid == 0) {
    ChildProcess();
  } else {
    // Initializing the second fork
    pid_2 = fork();
    if (pid_2 == 0) {
      ChildProcess();
    } else {
      ParentProcess();
    }
  }
}

void ChildProcess() {
  int count;
  for (count = 1; count <= random() % MAX_ITERATION; count++) {
    printf("Child Pid: %d is going to sleep!", getpid());
    printf("\n");
    sleep(random() % MAX_SLEEP_TIME);
    printf("Child Pid: %d is awake!", getpid());
    printf("\n");
    printf("Where is my Parent: %d?", getppid());
    printf("\n");
  exit(0);
  }
}

void  ParentProcess() {
//   // Wait for the first child process
  pid_t chpid_1 = wait(NULL);
  printf("Child Pid: %d has completed", chpid_1);
  printf("\n");
  
  // Wait for the second child process
  pid_t chpid_2 = wait(NULL);
  printf("Child Pid: %d has completed", chpid_2);
  printf("\n");
}