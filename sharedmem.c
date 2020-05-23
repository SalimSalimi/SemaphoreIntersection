#include "sharedmem.h"

void P(int semid){
    semop(semid,&sP,1);
}
void V(int semid) {
    semop(semid,&sV,1);
}

struct intersection* createSharedMemory(){
    Intersection* sharedIntersection;
    int shmid = shmget((key_t) SHARED_MEMORY_KEY, SHARED_MEMORY_SIZE, IPC_CREAT | S_IRUSR | S_IWUSR);
    sharedIntersection = (Intersection*) shmat(shmid, (void*) 0, 0);
    return sharedIntersection;
}