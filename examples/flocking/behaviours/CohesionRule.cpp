#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    
    Vector2 cohesionForce;
    Vector2 totalPos = Vector2::zero();
    Vector2 direction = Vector2::zero();
    double strength = 0;
    if (!neighborhood.empty()) 
    {
        Vector2 position = boid->transform.position;
        //totalPos += position;
        int countCloseFlockmates = neighborhood.size();
        
        for (int i = 0; i < countCloseFlockmates; i++)
        {
            totalPos += neighborhood[i]->getPosition();
        }
        totalPos = totalPos / countCloseFlockmates;
        direction = totalPos - position;
        float distance = direction.getDistance(position, totalPos);
        strength = fmin(10 / (distance * distance), 10);

    }

    cohesionForce = strength * direction;

    cohesionForce = Vector2::normalized(cohesionForce);
    return cohesionForce;
}