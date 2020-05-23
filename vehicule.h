#ifndef HEADER_VEHICULE
#define HEADER_VEHICULE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "defs.h"
#include "sharedmem.h"

   typedef struct {
    int pid;
    int positionX;
    int positionY;
    } Vehicule;

    Vehicule generateVehicule();
    void moveVehicule(Vehicule vehicule);
#endif