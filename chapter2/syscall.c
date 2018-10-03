#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


void permit (char* path, int user_id) {
    int rval = chown (path, user_id, -1);
    fprintf(stderr, "error code: %d\n", rval);
    if (rval != 0) {
        int error_code = errno;
        assert (rval = -1);
        switch (error_code) {
            case EPERM: //permission denied
            case EROFS: //path is on a readonly filesystem
            case ENAMETOOLONG: //path is too long
            case ENOENT: //path does not exist
            case ENOTDIR: //a component of path is not a directory
            case EACCES:// a component of path is not accessible
                fprintf(stderr, "error chown of %s: %s\n",
                        path, strerror(error_code));
                break;
            case EFAULT: //path contains an invalid memory address. this is probabely a bug
                abort();

            case ENOMEM:
                // ran out of kernel memory :/
                fprintf(stderr, "%s\n", strerror(error_code));
                exit(1);
            default:
                abort();
        };
    }
}

int main (int argc, char** argv) {
    int uid = 501;
    permit("/Users/moolica/test",uid);
    return 0;
}
