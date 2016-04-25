#include <apue.h>
#include <pthread.h>

void cleanup(void *arg){
    printf("cleanup : %s\n", (char*)arg);
}

void *thr_fn(void *arg){
    pthread_cleanup_push(cleanup, "first handler");
    pthread_cleanup_push(cleanup, "second handler");
    pthread_cleanup_push(cleanup, "third handler");
    pthread_cleanup_push(cleanup, "forth handler");
    printf("thread push complete\n");
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    if(arg)
        pthread_exit((void*)1);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
}

int main(){
    int err;
    pthread_t tid;
    void *tret;

    err = pthread_create(&tid, NULL, thr_fn, (void*)1);
    if(err != 0)
        err_exit(err, "create thread error");
    err = pthread_join(tid, &tret);
    if(err != 0)
        err_exit(err, "join thread error");
    exit(0);
}
