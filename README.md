# Linux-Process-API-fork-wait-exec-

Ex02-Linux Process API-fork(), wait(), exec()

# Ex02-OS-Linux-Process API - fork(), wait(), exec()

Operating systems Lab exercise

# AIM:
To write C Program that uses Linux Process API - fork(), wait(), exec()

# DESIGN STEPS:

### Step 1:

Navigate to any Linux environment installed on the system or installed inside a virtual environment like virtual box/vmware or online linux JSLinux (https://bellard.org/jslinux/vm.html?url=alpine-x86.cfg&mem=192) or docker.

### Step 2:

Write the C Program using Linux Process API - fork(), wait(), exec()

### Step 3:

Test the C Program for the desired output. 

# PROGRAM:

## C Program to print process ID and parent Process ID using Linux API system calls

```
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


```

## OUTPUT

![alt text](ex02-forkcheck.png)



## C Program to create new process using Linux API system calls fork() and exit()

```
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

   
```

## OUTPUT
![alt text](w-and-e1.png)
![alt text](w-and-e2.png)
![alt text](w-and-e3.png)
![alt text](w-and-e4.png)


## C Program to execute Linux system commands using Linux API system calls exec() family
```
//C Program to execute Linux system commands using Linux API system calls exec() family
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;

    printf("Running ps with execl\n");
    if (fork() == 0) {
        execl("ps", "ps", "-f", NULL);
        perror("execl failed");
        exit(1);
    }
    wait(&status);

    if (WIFEXITED(status)) {
        printf("Child exited with status: %d\n", WEXITSTATUS(status));
    } else {
        printf("Child did not exit successfully\n");
    }

    printf("Running ps with execlp (without full path)\n");
    if (fork() == 0) {
        execlp("ps", "ps", "-f", NULL);
        perror("execlp failed");
        exit(1);
    }
    wait(&status);

    if (WIFEXITED(status)) {
        printf("Child exited for execlp with status: %d\n", WEXITSTATUS(status));
    } else {
        printf("Child did not exit successfully\n");
    }

    printf("Done.\n");
    return 0;
}

```
## OUTPUT

![alt text](execcheck2.png)

# RESULT:

The programs are executed successfully.
