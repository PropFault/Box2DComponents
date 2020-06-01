#ifndef CIRCLEFIXTURECOMPONENT_H
#define CIRCLEFIXTURECOMPONENT_H
#include "physicsfixturecomponent.h"
#include <string>
#include "../BlastCompany/vec2.h"
class CircleFixtureComponent : public PhysicsFixtureComponent
{
private:
    b2CircleShape circleShape;
public:
    static const std::string INIT_PARAM_RADIUS;
    static const std::string INIT_PARAM_POSITION;
    CircleFixtureComponent();

    // PhysicsFixtureComponent interface
private:
    void addExtrasToDefinition(b2FixtureDef &defintion) override;

    // Component interface
public:
    Component *clone() override;

    // Component interface
protected:
    void _init(nlohmann::json json) override;
    void _deinit() override;
};

#endif // CIRCLEFIXTURECOMPONENT_H
