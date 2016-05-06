#include <apue.h>
#include <fcntl.h>

int main(){
    pid_t pid;
    int pfd[2];
    char line[MAXLINE];

    if(pipe(pfd) < 0)
        err_sys("pipe error");

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0){
        close(pfd[1]);
        int fd, n;
        n = read(pfd[0], line, MAXLINE);
        line[n] = 0;
        sscanf(line, "%d", &fd);
        printf("file description : %d\n", fd);
        if(write(fd, "hello", 6) < 0)
            err_sys("write error");
        exit(0);
    }
    close(pfd[0]);
    int fd;
    char path[] = "hosts";
    if((fd = open(path, O_RDWR)) < 0)
        err_sys("open error");
    sprintf(line, "%d", fd);
    write(pfd[1], line, strlen(line));
    exit(0);
}
