#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char const *argv[])
{
    int k, n=10, id;
    double x=0, z;
    

    for (k=0; k <n; k++) {
        id = fork();
        if (id < 0) {
            printf(1, "%d failed in fork!\n", getpid());
        }
        else if (id > 0) {
            printf(1, "Parent %d creating child %d!\n", getpid(), id);
        } else { //child
            printf(1, "Child %d created\n", getpid());
            for (z = 0; z < 8000000; z++) {
                x = x * 3.14 * 90;
            }
            break;
        }
    }
    
    exit();
}
