/** Forking Practice 1
 * Write a program that prints “Hello, World!” from a child process it creates and 
 * prints the ids of the child and parent processes in the format “The child and 
 * parent process ids are: 1234 and 1235.”
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void err_sys()
{
    printf("Error with fork call.\n");
    exit(-1);
}

int main(int argc, char *arg[])
{
    int status;
    // Calling fork and saving the pid
    pid_t pid = fork();
    if (pid < 0)
    {
        err_sys();
    }

    // If the pid is 0, then inside the child process
    if (pid == 0)
    {
        printf("Hello, World!\n");
        pid_t child = getpid();

        printf("The child and parent process ids are: %lu", (unsigned long)child);
        exit(0);
    }

    wait(&status);
    pid_t parent = getpid();
    printf(" and %lu\n", (unsigned long)parent);

    return 0;
}
