#include <stdlib.h>
#include <stralign.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <types.h>

int main()
{
    int fd[2], n;
    char buffer[100];
    pid_t p;

    pipe(fd);

    p = fork();

    if (p > 0)
    {
        printf("parent writing to child");
        write(fd[1], "hello/n", 6);
        sleep(3);
    }
    else
    {
        printf("child reading");
        n = read(fd[0], buffer, 100);
        printf("%s", buffer);
        write(1, buffer, n);
    }
}
