/* compile and build
 * cc -D_REENRANT -I/usr/include/nptl thread1.c -o thread1 -L/usr/lib/nptl -lpthread
 * or
 * cc -D_REENRANT thread1.c -o thread1 -lpthread
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);

static char message[] = "Hello World";
static int run_now = 1;

int main(){
    int res;
    pthread_t a_thread;
    void *thread_result;

    /*create the thread, and set the callback*/
    res = pthread_create(&a_thread, NULL, thread_function, (void*)message);
    if(res != 0){
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    int print_count1 = 0;
    while(print_count1++ < 20){
        if(run_now==1){
            printf("1");
            run_now = 2;
        }else{
            sleep(1);
        }

    printf("Waiting for thread to finish...\n");

    res = pthread_join(a_thread, &thread_result);
    if(res != 0){
        perror("Thread join failed");
        exit(0);
    }

    printf("Thread joined, it returned %s\n", (char *)thread_result);
    printf("Message is now %s\n", message);

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg){
    int print_count2 = 0;
    while(print_count2++ < 20){
        if(run_now==2){
            printf("2");
            run_now = 1;
        }else{
            sleep(1);
        }
    }
}
