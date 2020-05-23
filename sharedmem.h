#ifndef HEADER_SHARED_MEM
#define HEADER_SHARED_MEM

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include "intersection.h"
#include "defs.h"

    struct intersection * createSharedMemory();
    static struct sembuf sP = {0, 1, 0};	
    static struct sembuf sV = {0, -1, 0};	
#endif