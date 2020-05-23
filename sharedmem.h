#ifndef HEADER_SHARED_MEM
#define HEADER_SHARED_MEM

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include "intersection.h"
#include "defs.h"

    struct intersection * createSharedMemory();

#endif