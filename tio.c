#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char const *argv[])
{
    int k, n=6, id;

    for (k=0; k <n; k++) {
        id = fork();
        if (id < 0) {
            printf(1, "%d failed in fork!\n", getpid());
        }
        else if (id > 0) {
            printf(1, "Parent %d creating child %d!\n", getpid(), id);
        } else { //child
            printf(1, "Child %d created\n", getpid());
            int fd;
            char *buf = "testtesttesttest";
            for (int i=0; i < 100; i++) {
                char* file_name = (char*)malloc(20 * sizeof(char));
                file_name[0] = id + 57;
                fd = open(file_name, O_WRONLY);
                write (fd, buf, 16);
                close (fd);
            }
            break;
        }
    }
    
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