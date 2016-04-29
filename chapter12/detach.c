#include <apue.h>
#include <pthread.h>

int main(){
    pthread_attr_t attr;
    int err, state;

    err = pthread_attr_init(&attr);
    if(err != 0)
        err_exit(err, "init error");
    err = pthread_attr_getdetachstate(&attr, &state);
    if(err != 0)
        err_exit(err, "get error");
    if(state == PTHREAD_CREATE_JOINABLE)
        printf("thread joinable\n");
    else
        printf("thread detachable\n");
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(err != 0)
        err_exit(err, "set error");
    pthread_attr_getdetachstate(&attr, &state);
    if(state == PTHREAD_CREATE_JOINABLE)
        printf("thread joinable\n");
    else
        printf("thread detachable\n");
    exit(0);
}
