#ifndef HEADER_INTERSECTION
#define HEADER_INTERSECTION
    
#include <stdbool.h>

#include "defs.h"
#include "vehicule.h"

    typedef struct {
        Vehicule* vehicules[VEHICULE_NUMBER_SIZE];
        char terrain[MATRICE_SIZE][MATRICE_SIZE];
        Vehicule* vehiculeSection[VEHICULE_INTERSECTION_SIZE];
        bool isInstersectionFree;
    } Intersection;
    extern Intersection * intersection;  
    
    Intersection* init();

    void showIntersection();

#endif