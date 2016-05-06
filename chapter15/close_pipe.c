#include <apue.h>

int main(){
    pid_t pid;
    int fd[2];

    if(pipe(fd) < 0)
        err_sys("pipe error");

    if((pid = fork()) < 0)
        err_sys("fork error");
    if(pid == 0){
        close(fd[1]);
        sleep(3);
        int n;
        char c;
        if((n = read(fd[0], &c, 1)) != 1)
            err_sys("read error");
        printf("ok\n");
        exit(0);
    }
    close(fd[0]);
    char c = 'c';
    if(write(fd[1], &c, 1) != 1)
        err_sys("write error");
    exit(0);
}
