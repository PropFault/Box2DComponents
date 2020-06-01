#include "physicsbodycomponent.h"


const std::string PhysicsBodyComponent::INIT_PARAM_TRANSFORM = "transform";

b2Body *PhysicsBodyComponent::getBody() const
{
    return body;
}

void PhysicsBodyComponent::setBody(b2Body *value)
{
    body = value;
}



Component::CID PhysicsBodyComponent::getTransform() const
{
    return transform;
}

void PhysicsBodyComponent::_init(nlohmann::json json)
{
    this->transform = json.at(INIT_PARAM_TRANSFORM).get<Component::CID>();
}

void PhysicsBodyComponent::_deinit()
{
    this->transform = 0;
}

PhysicsBodyComponent::PhysicsBodyComponent(const std::string &name)
    :Component(name),body(NULL)
{
}

void PhysicsBodyComponent::addFixture(b2FixtureDef* fixture)
{
    if(body == NULL)
        throw new std::runtime_error("Body is null! Cant add fixture");
    body->CreateFixture(fixture);
}
