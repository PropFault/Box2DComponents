#ifndef BOXFIXTURECOMPONENT_H
#define BOXFIXTURECOMPONENT_H
#include "physicsfixturecomponent.h"
#include <string>
#include <Box2D/Box2D.h>
class BoxFixtureComponent : public PhysicsFixtureComponent
{
private:
    b2PolygonShape shape;
public:
    BoxFixtureComponent();

    // Component interface
public:
    Component *clone() override;
    static const std::string INIT_PARAM_WIDTH;
    static const std::string INIT_PARAM_HEIGHT;
    // PhysicsFixtureComponent interface
private:
    void addExtrasToDefinition(b2FixtureDef &defintion) override;

    // Component interface
protected:
    void _init(nlohmann::json json) override;
};

#endif // BOXFIXTURECOMPONENT_H
