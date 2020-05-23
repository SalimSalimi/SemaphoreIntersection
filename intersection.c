#include "intersection.h"

// Intersection * init(){}

void showTerrain(Intersection* intersection){
    for(int i = 0; i < sizeof(intersection->vehicules)/sizeof(intersection->terrain[0]); i++){
        int positionX = intersection->vehicules[i]->positionX;
        int positionY = intersection->vehicules[i]->positionY;
        intersection->terrain[positionX][positionY] = "*";
    }   
}

