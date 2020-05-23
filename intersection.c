#include "intersection.h"

Intersection* init() {
    Intersection* intersection = createSharedMemory();
    fillTerrain(intersection);
    generateHorizontalRoad(intersection);
    generateVerticalRoad(intersection);
    int semid = semget((key_t) SEMAPHORE_KEY, 2, IPC_CREAT | S_IRUSR | S_IWUSR);
    intersection->sharedSemaphoreId = semid;
    return intersection;
}

void addVehiculesToTerrain(Intersection* intersection) {
    for(int i = 0; i < sizeof(intersection->vehicules)/sizeof(intersection->vehicules[0]); i++){
        int positionX = intersection->vehicules[i]->positionX;
        int positionY = intersection->vehicules[i]->positionY;
        intersection->terrain[positionX][positionY] = "*";
    }   
}

void fillTerrain(Intersection* intersection){
    for (int i = 0; i < MATRICE_SIZE; i++) {
        for (int j = 0; j < MATRICE_SIZE; j++) {
            intersection->terrain[i][j] = " ";       
        }
    }
}

void generateHorizontalRoad(Intersection* intersection){
    for (int i = 2; i <= 4; i+=2) {
        for (int j = 0; j < MATRICE_SIZE; j++) {
            intersection->terrain[i][j] = "-";   
        }
    }    
}

void generateVerticalRoad(Intersection* intersection){
    for (int i = 0; i <= MATRICE_SIZE; i++) {
        for (int j = 2; j <= 4; j+=2) {
            intersection->terrain[i][j] = "|";   
        }
    }
}

void showTerrain(Intersection* intersection){
    for (int i = 0; i < MATRICE_SIZE; i++) {
        for (int j = 0; j < MATRICE_SIZE; j++) {
            printf("%s", intersection->terrain[i][j]);   
        }
        printf("\n");       
    }   
}