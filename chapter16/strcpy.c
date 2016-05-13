#include <apue.h>

int main(){
    char s[] = "hello";
    strcpy(s+1, s);
    printf("%s\n", s);
    exit(0);
}
