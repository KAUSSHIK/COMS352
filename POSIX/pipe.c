#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int pipefd[2]; // Array to hold the two pipe (file) descriptors

    pid_t pid;

    char buf[30];

    // Explicitly create a pipe
    int pipe_status = pipe(pipefd);

    if (pipe_status == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipefd[0]); // Close the unused READ end of the pipe

        // Write a message to the pipe
        const char *msg = "Hello from child!";
        write(pipefd[1], msg, strlen(msg));
        
        close(pipefd[1]); // Close the write end of the pipe
        exit(EXIT_SUCCESS);

    } else { // Parent process
        close(pipefd[1]); // Close the unused write end of the pipe

        // Read data from the pipe
        read(pipefd[0], buf, sizeof(buf));
        printf("Parent received: %s\n", buf);
        
        close(pipefd[0]); // Close the read end of the pipe
    }

    return 0;
}

// pipefd[2]: This array stores the file descriptors for the pipe. pipefd[0] is used for reading from the pipe, and pipefd[1] is used for writing to it.

// pipe(pipefd): This function call creates the pipe. It takes an array of two integers as an argument and assigns the file descriptors for the read and write ends of the pipe to pipefd[0] and pipefd[1], respectively.

// fork(): This function creates a new process. The return value is stored in pid. In the child process, pid is 0, and in the parent process, pid is the PID of the child.

// write(pipefd[1], msg, strlen(msg)): In the child process, this function writes the message to the write end of the pipe.
// file descriptor to write to, pointer to the buffer containing the data to be written, number of bytes to write

// read(pipefd[0], buf, sizeof(buf)): In the parent process, this function reads the message from the read end of the pipe into buf.

// we specify the end of the pipe meaning which file descriptor, a pointer to the buffer where the read data should be stored and number of bytes to read. once a message is read, its no longer available in the pipe

// close(pipefd[...]): Closing the unused ends of the pipe in each process is essential. The child closes the read end (pipefd[0]), and the parent closes the write end (pipefd[1]).

// This enhanced version of the code provides a more detailed understanding of each part of the process of creating a pipe, forking a process, and using the pipe for inter-process communication between the parent and child processes.

// a buffer is a temporary storage area used to hold data while its being moved from one place to another. 

//O is read side of pipe, 1 is write side of pipe