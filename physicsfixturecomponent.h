#ifndef FIXTURE_H
#define FIXTURE_H
#include "../BlastCompany/component.h"
#include <string>
#include <Box2D/Box2D.h>
class PhysicsFixtureComponent : public Component
{
private:
    float density;
    float friction;
    float restitution;
    virtual void addExtrasToDefinition(b2FixtureDef &defintion) = 0;
public:
    static const std::string INIT_PARAM_DENSITY;
    static const std::string INIT_PARAM_FRICTION;
    static const std::string INIT_PARAM_RESTITUTION;
    PhysicsFixtureComponent(const std::string &name);
    b2FixtureDef getFixtureDefinition();
    virtual ~PhysicsFixtureComponent(){};

    // Component interface
protected:
    void _init(nlohmann::json json) override;
    void _deinit() override;

};

#endif // FIXTURE_H
