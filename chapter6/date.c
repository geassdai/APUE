#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    struct tm *tmp;
    char buf[64];

    time(&t);
    tmp = localtime(&t);
    strftime(buf, 64, "%Y %m %d %a %H:%M:%S %Z", tmp);
    printf("%s\n", buf);
    return 0;
}
