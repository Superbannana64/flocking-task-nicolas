#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    Vector2 separatingForce;
    float distance;
    Vector2 offset;
    Vector2 force;

    for (int i = 0; i < neighborhood.size(); i++)
    {
        offset = boid->getPosition() - neighborhood[i]->getPosition();
        distance = offset.getMagnitude();

        if (distance < desiredMinimalDistance && distance > 0)
        {
            force = offset / distance;
            separatingForce.x += force.x;
            separatingForce.y += force.y;
        }
    }
    return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
