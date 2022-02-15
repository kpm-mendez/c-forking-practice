/** Forking Practice 2
 *  Write a C program using the fork() system call that generates and prints the 
 *  Fibonacci sequence in the child process. The number of members in the sequence 
 *  will be determined by a user provided as a user prompted input. Make the parent
 *  process wait for the child process to complete before exiting. Make the program 
 *  print both the parent and child process IDs.
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

int fibonacciFn(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacciFn(n-1) + fibonacciFn(n-2);;
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
        int n;
        printf("Enter the number of terms to display the fibonacci sequence: ");
        int check = scanf("%d", &n);

        if (check != 1)
        {
            printf("Error: Incorrect input format. Must be an integer.");
            exit(0);
        }
        if (n < 1)
        {
            printf("Error: No number less than 1 is allowed.");
            exit(0);
        }


        for (int i = 0; i < n; i++)
        {
            printf("%d ", fibonacciFn(i));
        }

        pid_t child = getpid();
        pid_t parent = getppid();
        printf("\nThe child and parent process ids are %lu and %lu\n", (unsigned long)child, (unsigned long)parent);

        exit(0);
    }

    wait(&status);

    return 0;
}
