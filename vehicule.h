#ifndef HEADER_VEHICULE
#define HEADER_VEHICULE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

   typedef struct {
    int pid;
    int positionX;
    int positionY;
    } Vehicule;

    Vehicule genererVehicule();
    void deplacerVehicule(Vehicule vehicule);
#endif