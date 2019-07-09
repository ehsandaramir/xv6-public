#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char const *argv[])
{
    int k, n, id;
    double x=0, z;
    
    if (argc != 3){
        printf(1, "please enter 'c' or 'i' & pid\n");
    }
    else
    {
        n = atoi(argv[2]);

        for (k=0; k <n; k++) {
            id = fork();
            if (id < 0) {
                printf(1, "%d failed in fork!\n", getpid());
            }
            else if (id > 0) {
                printf(1, "Parent %d creating child %d!\n", getpid(), id);
                // wait();
            } else { //child
                printf(1, "Child %d created\n", getpid());
                for (z = 0; z < 8000000; z++) {
                    x = x * 3.14 * 90;
                }
                // printf(1, "FFFF");
                break;
            }
        }
    }
    printf(1, "exec done!\n");
    exit();
}


        // fork();
        // fork();
        // fork();
        // fork();


        // int pid = getpid();
        // if (strcmp(argv[1],"c") == 0)
        // {
        //     printf(1, "exec cpu intesive proc\n");

        //     int startTicks = uptime();
            
        //     int i = 2;
        //     for (int j = 0; j < 1000000; j++)
        //         i = i * i;

        //     int endTicks = uptime();
        //     int seconds = (endTicks - startTicks)/100;
        //     int partial_seconds = (endTicks - startTicks)%100;
            
        //     printf(1, " %d: ran in %d.%d", pid, seconds, partial_seconds);
        // }
        // else if (strcmp(argv[1],"i") == 0)
        // {
        //     printf(1, "exec i/o intesive proc\n");
        //     int startTicks = uptime();

        //     int fd;
        //     char *buf = "testtest";
        //     for (int i=0; i < 1000; i++) {
        //         fd = open("x/y", O_RDWR);
        //         write (fd, buf, 8);
        //         close (fd);
        //     }

        //     int endTicks = uptime();
        //     int seconds = (endTicks - startTicks)/100;
        //     int partial_seconds = (endTicks - startTicks)%100;
        //     printf(1, " %d: ran in %d.%d", pid, seconds, partial_seconds);
        // }