#ifndef DYNAMICBODYCOMPONENT_H
#define DYNAMICBODYCOMPONENT_H
#include "../BlastCompany/component.h"
#include "physicsbodycomponent.h"
#include <string>

class DynamicBodyComponent : public PhysicsBodyComponent
{
private:
    bool lockRotation;
public:
    DynamicBodyComponent();

    // Component interface
protected:
    static const std::string INIT_PARAM_LOCK_ROTATION;
    void _init(nlohmann::json json) override;
    void _deinit() override;

public:
    Component *clone() override;

    // PhysicsBody interface
public:
    b2BodyDef getBodyDefinition() override;
};

#endif // DYNAMICBODYCOMPONENT_H
