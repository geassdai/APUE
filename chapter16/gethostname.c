#include <apue.h>
#include <unistd.h>

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

int main(){
    char *host;
    int n;

    if((n = sysconf(_SC_HOST_NAME_MAX)) < 0)
        n = HOST_NAME_MAX;
    if((host = malloc(n)) == NULL)
        err_sys("malloc error");
    if(gethostname(host, n) < 0)
        err_sys("gethostname error");
    printf("hostname : %s\n", host);
    exit(0);
}
