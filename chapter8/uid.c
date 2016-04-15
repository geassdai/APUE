#include <apue.h>

int main(){
    uid_t uid;
    uid_t euid;
    uid = getuid();
    euid = geteuid();
    printf("uid = %ld\n", uid);
    printf("euid = %ld\n", euid);
    setuid(euid);
    uid = getuid();
    euid = geteuid();
    printf("uid = %ld\n", uid);
    printf("euid = %ld\n", euid);
    return 0;
}
