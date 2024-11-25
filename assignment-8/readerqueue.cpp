#include <stdio.h>  // For printf, sprintf
#include <stdlib.h> // For exit
#include <string.h> // For strlen
#include <fcntl.h>  // For shm_open, O_CREAT, O_RDWR
// #include <sys/mman.h>   // For mmap, PROT_WRITE, MAP_SHARED
#include <unistd.h>
#DEFINE MAX 100;

struct m
{
    long type;
    char text[100];
} message;

int main()
{
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // can display after this;

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}