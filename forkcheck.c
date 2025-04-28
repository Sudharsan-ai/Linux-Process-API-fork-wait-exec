#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    int pid = fork();

    if (pid == 0) { 
        printf("I am child, my PID is %d\n", getpid()); 
        printf("My parent PID is: %d\n", getppid()); 
        sleep(2); 
    } else if (pid > 0) { 

        printf("I am parent, my PID is %d\n", getpid()); 
        wait(NULL);
    } else {
        
        perror("Fork failed");
        exit(1);
    }

    return 0;
}

