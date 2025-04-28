#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t pid;

    printf("Running ps with execl (without full path, expected to fail)\n");
    
    pid = fork(); 
    if (pid == 0) {
        
        execl("ps", "ps", "ax", NULL);
        perror("execl failed");
        exit(1);
    } else if (pid > 0) {
      
        wait(&status);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        else
            puts("Child did not exit successfully");
    } else {
        perror("fork failed");
        exit(1);
    }

    printf("Running ps with execl (with full path)\n");

    pid = fork(); 
    if (pid == 0) {
       
        execl("/bin/ps", "ps", "ax", NULL); // 
        perror("execl failed");
        exit(1);
    } else if (pid > 0) {
       
        wait(&status);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        else
            puts("Child did not exit successfully");
    } else {
        perror("fork failed");
        exit(1);
    }

    printf("Done.\n");
    return 0;
}

   
