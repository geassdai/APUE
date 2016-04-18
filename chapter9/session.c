#include <apue.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    pid_t pid;

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0){
        printf("pid = %ld, ppid = %ld, sid = %ld, tpgid = %ld\n", getpid(), getppid(), getsid(0), getpgrp());
        if(setsid() == -1)
            err_sys("setuid error");
        printf("pid = %ld, ppid = %ld, sid = %ld, tpgid = %ld\n", getpid(), getppid(), getsid(0), getpgrp());
        if(open("/dev/tty", O_RDWR) == -1)
            err_sys("open error");

    }
    if(waitpid(pid,NULL,0) != pid)
        err_sys("waitpid error");
    exit(0);
}
