#include "vehicule.h"

Vehicule genererVehicule() {
    Vehicule vehicule;    
    int n;
    switch (fork()) {
    case -1:
        printf("Couldn't create a new car");
        break;
    case 0:
        n = rand() % 2;
        vehicule.pid = getpid();
        if (n == 0) {
            vehicule.positionX = 0;
            vehicule.positionY = 3;
        }
        else {
            vehicule.positionX = 3;
            vehicule.positionY = 0;
        }
        break;
    default:
        break;
    }
    return vehicule;
}

void deplacerVehicule(Vehicule vehicule) {
    if (vehicule.positionX < MATRICE_SIZE || vehicule.positionY < MATRICE_SIZE) {
        if (vehicule.positionY == 3) {
            vehicule.positionX++;
        }
        if (vehicule.positionX == 3) {
            vehicule.positionY++;
        }
    }
}