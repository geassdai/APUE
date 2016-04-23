#include "apue.h"
#include <setjmp.h>

sigjmp_buf jmpbuffer;

static void handler(int signo){
    siglongjmp(jmpbuffer, 1);
}

int main(){
    if(signal(SIGQUIT, handler) < 0)
        err_sys("signal error");
    if(sigsetjmp(jmpbuffer,1) == 0){
        pause();
    }
    pause();
    return 0;
}
