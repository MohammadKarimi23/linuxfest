#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char** argv) {
    char* arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };

    pid_t child_pid;
    child_pid = fork();

    if (child_pid == 0) {
        sleep(100000);
        execvp ("ls", arg_list);
        fprintf(stderr, "an error occured in ecexvp\n");
        abort();
    }
    printf("done with main");
    return 0;
}
