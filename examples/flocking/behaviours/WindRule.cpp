#include "WindRule.h"
#include <imgui.h>
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 WindRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    // todo: add a wind force here
    Vector2 windForce = Vector2::zero();
    float speed = sqrt(pow(boid->getVelocity().x, 2) + pow(boid->getVelocity().y, 2));
    windForce.x = speed * cos(windAngle);
    windForce.y = speed * sin(windAngle);
    // hint: use the windAngle variable
    return windForce;
}

bool WindRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valueHasChanged = false;

    if (ImGui::SliderAngle("Wind Direction", &windAngle, 0)) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}