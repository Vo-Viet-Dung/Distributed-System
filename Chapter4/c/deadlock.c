#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int a = 0, b = 0;
pthread_mutex_t lock_a, lock_b;
void *fun_1(void *arg)
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        // lock a then b
        pthread_mutex_lock(&lock_a);    // success
        pthread_mutex_lock(&lock_b);    // failded
        // CRITICAL SECTION
        a++;
        b++;
        pthread_mutex_unlock(&lock_a);
        pthread_mutex_unlock(&lock_b);
    }
    return NULL;
}
void *fun_2(void *arg)
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        // lock b then a
        pthread_mutex_lock(&lock_b);    // success
        pthread_mutex_lock(&lock_a);    // failded
        // CRITICAL SECTION
        a++;
        b++;
        pthread_mutex_unlock(&lock_b);
        pthread_mutex_unlock(&lock_a);
    }
    return NULL;
}
int main()
{
    pthread_t thread_1, thread_2;
    pthread_mutex_init(&lock_a, NULL);
    pthread_mutex_init(&lock_b, NULL);
    pthread_create(&thread_1, NULL, fun_1, NULL);
    pthread_create(&thread_2, NULL, fun_2, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    printf("\t a=%d b=%d \n", a, b);
    return 0;
}