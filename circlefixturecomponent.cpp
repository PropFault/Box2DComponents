#include "circlefixturecomponent.h"
#include <iostream>
const std::string CircleFixtureComponent::INIT_PARAM_RADIUS = "radius";
const std::string CircleFixtureComponent::INIT_PARAM_POSITION = "position";


CircleFixtureComponent::CircleFixtureComponent()
    :PhysicsFixtureComponent ("circlefixture")
{

}

void CircleFixtureComponent::addExtrasToDefinition(b2FixtureDef &defintion)
{
    defintion.shape = &this->circleShape;
}

Component *CircleFixtureComponent::clone()
{
    return new CircleFixtureComponent(*this);
}

void CircleFixtureComponent::_init(nlohmann::json json)
{
    PhysicsFixtureComponent::_init(json);
    std::cout<<"INIT CIRCLE FIXTURE. " << INIT_PARAM_RADIUS << " | " << INIT_PARAM_POSITION << std::endl;
    this->circleShape.m_radius = json[INIT_PARAM_RADIUS].get<float>();
    std::cout<<"INIT RADIUS WITH " << this->circleShape.m_radius << std::endl;
    this->circleShape.m_p.Set(json[INIT_PARAM_POSITION]["x"].get<float32>(), json[INIT_PARAM_POSITION]["y"].get<float32>());
}

void CircleFixtureComponent::_deinit()
{
    PhysicsFixtureComponent::_deinit();
}
