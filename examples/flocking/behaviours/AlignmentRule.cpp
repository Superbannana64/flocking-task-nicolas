#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood

    int countCloseFlockmates = 0;

    Vector2 distance;
    if (!neighborhood.empty())
    {
        countCloseFlockmates = neighborhood.size();

        for (int i = 0; i < countCloseFlockmates; i++)
        {
            distance = boid->getPosition() - neighborhood[i]->getPosition();
            averageVelocity.x = neighborhood[i]->velocity.x;
            averageVelocity.y = neighborhood[i]->velocity.y;
        }
    }

    return Vector2::normalized(averageVelocity);
}