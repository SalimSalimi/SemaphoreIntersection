#include "vehicule.h"

Vehicule genererVehicule() {
    Vehicule vehicule;    
    switch (fork()) {
    case -1:
        puts("Can't create a new car");
        break;
    case 0:
        int n = rand() % 2;
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
    if (vehicule.positionX <= 6 && vehicule.positionY <= 6) {
        if (vehicule.positionY == 3) {
            vehicule.positionX = vehicule.positionX + 1;
        }
        if (vehicule.positionX == 3) {
            vehicule.positionY = vehicule.positionY - 1;
        }
    }
}