#ifndef STATICBODYCOMPONENT_H
#define STATICBODYCOMPONENT_H
#include "../BlastCompany/component.h"
#include "physicsbodycomponent.h"

class StaticBodyComponent : public PhysicsBodyComponent
{
public:
    StaticBodyComponent();

    // Component interface
protected:
    void _init(nlohmann::json json) override;
    void _deinit() override;

public:
    Component *clone() override;

    // PhysicsBody interface
public:
    b2BodyDef getBodyDefinition() override;
};

#endif // STATICBODYCOMPONENT_H
