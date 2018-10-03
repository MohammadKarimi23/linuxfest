#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char** argv){
    pid_t child_pid;
    printf("the pid of the main process is: %d\n", (int) getpid());

    child_pid = fork();
    if (child_pid != 0) {
        printf("parent: parent pid: %d\n", (int) getpid());
        printf("parent: child's pid: %d,\n",(int) child_pid);
    } else {
        printf("child: pid: %d\n", (int) getpid());
    }
    return 0;
}
