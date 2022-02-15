/** Forking Practice 3
 *  Write a program using the Pthreads API that prints “Hello, World!” from four 
 *  threads it creates and prints the ids of the threads along with in the format
 *  “Hello, World! from thread id : 0” from each of the threads
*/

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// Global variable for number of threads
int MAX_THREADS = 4;

void *thr_fn(void *arg)
{
    // Prints hello world messgage and the ID for the thread
    printf("Hello, World! from thread id : %lu\n", (unsigned long)pthread_self());
    return ((void *)0);
}

int main(int argc, char *arg[])
{
    int err;
    for (int count = 0; count < MAX_THREADS; count++)
    {
        // Creating new pthread
        pthread_t ntid;
        // Creating the thread with the thread id
        err = pthread_create(&ntid, NULL, thr_fn, NULL);
        // If there was an error in creating the thread, print an error message
        if (err != 0)
        {
            printf("%d - Thread error\n", err);
        }
        sleep(1);
    }
    exit(0);
}
