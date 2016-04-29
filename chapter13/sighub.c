#include <apue.h>
#include <signal.h>
#include <fcntl.h>

void sighub(int signo){
    int fd;
    fd = open("/home/dai/hello.txt", O_RDWR | O_APPEND | O_CREAT, 0777);
    char buf[] = "caught SIGHUP\n";
    write(fd, buf, strlen(buf));
    close(fd);
}

int pass = 0;
void sigusr(int signo){
    pass = 1;
}

int main(){
    struct sigaction sa;
    sa.sa_handler = sighub;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGHUP, &sa, NULL);
    struct sigaction ssa;
    ssa.sa_handler = sighub;
    ssa.sa_flags = 0;
    sigemptyset(&ssa.sa_mask);
    sigaction(SIGUSR1, &ssa, NULL);
    while(pass == 0){

    }
    return 0;
}
