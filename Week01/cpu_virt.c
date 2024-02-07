#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    int i = 0;
    while (i++ < 5)
    {
        sleep(1);
        printf("(%d) %s\n", getpid(), str);
    }
    return 0;
}