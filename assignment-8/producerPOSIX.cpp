#include <stdio.h>  // For printf, sprintf
#include <stdlib.h> // For exit
#include <string.h> // For strlen
#include <fcntl.h>  // For shm_open, O_CREAT, O_RDWR
// #include <sys/mman.h>   // For mmap, PROT_WRITE, MAP_SHARED
#include <unistd.h> // For ftruncate

int main()
{
    const int SIZE = 4096;
    const char *NAME = "OS";
    const char *message1 = "HELLO";
    const char *message2 = "HEYO";

    int shm_fd;
    void *ptr;

    shm_fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);

    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);

    sprintf(ptr, "%s", message2);
    ptr += strlen(message2);

    return 0;
}