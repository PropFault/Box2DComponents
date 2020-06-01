#include "boxfixturecomponent.h"
const std::string BoxFixtureComponent::INIT_PARAM_WIDTH = "width";
const std::string BoxFixtureComponent::INIT_PARAM_HEIGHT = "height";
BoxFixtureComponent::BoxFixtureComponent()
    :PhysicsFixtureComponent ("boxfixture")
{

}

Component *BoxFixtureComponent::clone()
{
    return new BoxFixtureComponent(*this);
}

void BoxFixtureComponent::addExtrasToDefinition(b2FixtureDef &defintion)
{
    defintion.shape = &this->shape;
}

void BoxFixtureComponent::_init(nlohmann::json json)
{
    PhysicsFixtureComponent::_init(json);
    float width = json[INIT_PARAM_WIDTH].get<float>();
    float height = json[INIT_PARAM_HEIGHT].get<float>();
    this->shape.SetAsBox(width/2.0, height/2.0);
}


