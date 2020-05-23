#ifndef INTERSECTION_H_
#define INTERSECTION_H_
    
#include <stdbool.h>

#include "defs.h"
#include "vehicule.h"
#include "sharedmem.h"

    typedef struct intersection {
        struct Vehicule* vehicules[VEHICULE_NUMBER_SIZE];
        char* terrain[MATRICE_SIZE][MATRICE_SIZE];
        struct Vehicule* vehiculeSection[VEHICULE_INTERSECTION_SIZE];
        bool isIntersectionFree;
        int sharedSemaphoreId; 
    } Intersection;
    
    Intersection* init();
    void addVehiculesToTerrain(Intersection*);
    void fillTerrain(Intersection*);
    void generateHorizontalRoad(Intersection*);
    void generateVerticalRoad(Intersection*);
    void showTerrain(Intersection*);
#endif