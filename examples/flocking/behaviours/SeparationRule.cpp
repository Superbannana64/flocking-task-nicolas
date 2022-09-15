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
        distance = Vector2::getDistance(boid->transform.position, neighborhood[i]->transform.position);
        if (distance < desiredMinimalDistance && distance > 0)
        {
            offset = Vector2{ boid->transform.position.x - neighborhood[i]->transform.position.x, boid->transform.position.y - neighborhood[i]->transform.position.y };
            offset = Vector2::normalized(offset);
            force = { offset.x /= distance, offset.y /= distance };
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
