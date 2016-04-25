#include <apue.h>
#include <pthread.h>

pthread_barrier_t barr;

void thread_work(){
    int res = pthread_barrier_wait(&barr);
    if(res == PTHREAD_BARRIER_SERIAL_THREAD){
        //this is the unique "serial thread"; you can combine some results here
    }
    eles if(res != 0){
        //error occurred
    }
    else{
        //non-serial thread released
    }
}

int main(){
    int nthreads = 5;
    pthread_barrier_init(&barr, NULL, nthreads);

    int i;
    for(i = 0; i < nthreads; i++){
        //create threads
    }
}
