#include "intersection.h"
#include "vehicule.h"

int main() {
    Intersection* intersection = init();
    showTerrain(intersection);
    while (true) {
        Vehicule* vehicule = generateVehicule();
    }
    
    return 0;
}