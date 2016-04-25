#include <apue.h>
#include <pthread.h>

int pass = 0;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg(void){
    pthread_mutex_lock(&qlock);
    while(pass == 0)
        pthread_cond_wait(&qready, &qlock);
    //process msg
    pthread_mutex_unlock(&qlock);
}

void enqueue_msg(void){
    pthread_mutex_lock(&qlock);
    //enqueue msg
    pass = 1;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}
