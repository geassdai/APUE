#include "apue.h"
#include <setjmp.h>

jmp_buf jmpbuffer;

static void handler(int signo){
    longjmp(jmpbuffer, 1);
}

int main(){
    if(signal(SIGQUIT, handler) < 0)
        err_sys("signal error");
    if(setjmp(jmpbuffer) == 0){
        pause();
    }
    pause();
    return 0;
}
