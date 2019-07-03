#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char const *argv[])
{
    if (argc == 0)
        invoke(0);
    else {
        int x = atoi(argv[1]);
        invoke(x);
    }
    exit();
}

