#include "staticbodycomponent.h"

StaticBodyComponent::StaticBodyComponent()
    :PhysicsBodyComponent ("staticbody")
{

}

void StaticBodyComponent::_init(nlohmann::json json)
{
    PhysicsBodyComponent::_init(json);
}

void StaticBodyComponent::_deinit()
{
    PhysicsBodyComponent::_deinit();
}

Component *StaticBodyComponent::clone()
{
    return new StaticBodyComponent(*this);
}

b2BodyDef StaticBodyComponent::getBodyDefinition()
{
    b2BodyDef bodyDef;
    return bodyDef;
}
