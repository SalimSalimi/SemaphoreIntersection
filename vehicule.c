#include "vehicule.h"

Vehicule* generateVehicule() {
    Vehicule* vehicule;    
    int n;
    switch (fork()) {
    case -1:
        printf("Couldn't create a new car");
        break;
    case 0:
        n = rand() % 2;
        vehicule->pid = getpid();
        if (n == 0) {
            vehicule->positionX = 0;
            vehicule->positionY = 3;
        }
        else {
            vehicule->positionX = 3;
            vehicule->positionY = 0;
        }
        break;
    default:
        break;
    }
    return vehicule;
}

void moveVehicule(Vehicule* vehicule) {
    if (vehicule->positionX < MATRICE_SIZE || vehicule->positionY < MATRICE_SIZE) {
        if (vehicule->positionY == 3) {
            vehicule->positionX++;
        }
        if (vehicule->positionX == 3) {
            vehicule->positionY++;
        }
    }
}

void manageCriticalArea(Vehicule* vehicule, Intersection* intersection) {
    int semid = intersection->sharedSemaphoreId;
    if ((vehicule->positionX == 3 && vehicule->positionY == 2) || (vehicule->positionX == 2 && vehicule->positionY == 3)) {
        while (intersection->isIntersectionFree == false) {
            sleep(1);   
        }
        P(semid);
        moveVehicule(vehicule);
        V(semid);
    }
}