#include "dynamicbodycomponent.h"

const std::string DynamicBodyComponent::INIT_PARAM_LOCK_ROTATION = "lockRotation";
DynamicBodyComponent::DynamicBodyComponent()
    :PhysicsBodyComponent ("dynamicbody"), lockRotation(false)
{

}

void DynamicBodyComponent::_init(nlohmann::json json)
{
    PhysicsBodyComponent::_init(json);
    try {
        this->lockRotation = json.at(INIT_PARAM_LOCK_ROTATION).get<bool>();
    } catch (const nlohmann::detail::out_of_range &ex) {
        this->lockRotation = false;
    }{}
}

void DynamicBodyComponent::_deinit()
{
    PhysicsBodyComponent::_deinit();
}

Component *DynamicBodyComponent::clone()
{
    return new DynamicBodyComponent(*this);
}

b2BodyDef DynamicBodyComponent::getBodyDefinition()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = this->lockRotation;
    return bodyDef;
}
