#include <apue.h>
#include <unistd.h>
#include <pthread.h>

void *thr_fn(void *arg){
    printf("thread started...\n");
    sleep(5);
    printf("thread end...\n");
    return 0;
}

int main(){
    pthread_t tid;
    pid_t pid;
    int err;

    if((err = pthread_create(&tid, NULL, thr_fn, NULL)) != 0)
        err_exit(err, "create pthread_t error");
    sleep(2);
    printf("parent about to fork...\n");

    if((pid = fork()) < 0)
        err_quit("fork error");
    else if(pid == 0)
        printf("child from fork\n");
    else
        printf("parent from fork\n");
    sleep(7);
    exit(0);
}
