#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    char* server_name = getenv("SERVER_NAME");
    if (server_name == NULL)
        server_name = "server.my-company.com";
    printf("accessing server %s\n", server_name);
    return 0;
}
