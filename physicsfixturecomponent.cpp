#include "physicsfixturecomponent.h"
#include <iostream>
const std::string PhysicsFixtureComponent::INIT_PARAM_DENSITY = "density";
const std::string PhysicsFixtureComponent::INIT_PARAM_FRICTION = "friction";
const std::string PhysicsFixtureComponent::INIT_PARAM_RESTITUTION = "restitution";

PhysicsFixtureComponent::PhysicsFixtureComponent(const std::string &name)
    :Component (name), density(1.0f), friction(1.0f), restitution(0.0f){

}

b2FixtureDef PhysicsFixtureComponent::getFixtureDefinition()
{
    b2FixtureDef fixtureDef;
    fixtureDef.density = this->density;
    fixtureDef.friction =  this->friction;
    fixtureDef.restitution = this->restitution;
    this->addExtrasToDefinition(fixtureDef);
    return fixtureDef;
}

void PhysicsFixtureComponent::_init(nlohmann::json json)
{
    this->density = json[INIT_PARAM_DENSITY].get<float>();
    this->friction = json[INIT_PARAM_FRICTION].get<float>();
    try {
        this->restitution = json.at(INIT_PARAM_RESTITUTION).get<float>();
    } catch (const nlohmann::detail::out_of_range &ex) {
        this->restitution = 0.0f;
    }{}
}

void PhysicsFixtureComponent::_deinit()
{
    this->density = 1.0f;
    this->friction = 1.0f;
    this->restitution = 0.0f;
}
