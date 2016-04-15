#include <apue.h>

int global = 6;

int main(){
    pid_t pid;
    int var;

    var = 88;
    printf("before fork\n");
    if((pid = vfork()) < 0)
        err_sys("vfork error");
    else if(pid == 0){
        global++;
        var++;
        _exit(0);  //exit(0)都可以正常输出
    }
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), global, var);
    exit(0);
}
