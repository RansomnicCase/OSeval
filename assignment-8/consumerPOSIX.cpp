#include <iostream>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int shm_fd;
    void *ptr;

    const int SIZE = 4096;
    const char *name = "OS";
    shm_fd = shm_open(name, O_RDONLY, 0666);
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    printf("%s", char *ptr);
    shm_unlink(name);
    return 0;
}

/*Compile: gcc producer.c –lrt –o producer
Run: ./producer
Compile: gcc consumer.c –lrt –o consumer
Run: ./consumer*/
