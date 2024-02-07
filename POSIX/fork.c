#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int args, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid()); //process 1 (parent)
    int rc = fork(); //process 2 (child) what is rc -> return code
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child (new process) -> ONE VARIANT of the process prints this
        printf("hello, I am child (pid:%d), I AM THE CHILD.\n", (int)getpid());
    }
    else
    { // parent -> ANOTHER VARIANT (the original one) of the process prints this
        printf("hello, I am parent of %d (pid:%d), I AM THE OG.\n", rc, (int)getpid());
    }
    return 0;

    //EXPLAINATION
    //The fork() system call is used to create a new process. When a process calls fork(), the operating system makes a copy of the process and all its memory space. The new process is called the child process, and the original process is called the parent process. The child process is an exact copy of the parent process except for the process ID and the parent process ID. The child process has its own memory space, and it runs independently of the parent process. The child process is a new process, and it has its own memory space, its own file descriptors, and its own environment variables. The child process is an exact copy of the parent process, and it runs independently of the parent process. The child process has its own memory space, and it runs independently of the parent process. The child process is an exact copy of the parent process, and it runs independently of the parent process. The child process has its own memory space, and it runs independently of the parent process.
}