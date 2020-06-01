#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include <Box2D/Box2D.h>
#include <nlohmann/json.hpp>
#include "../BlastCompany/component.h"
#include <string>

class PhysicsBodyComponent : public Component
{
private:
    b2Body* body;
    Component::CID transform;
public:
    static const std::string INIT_PARAM_TRANSFORM;
    PhysicsBodyComponent(const std::string &name);
    virtual b2BodyDef getBodyDefinition()=0;
    virtual void addFixture(b2FixtureDef* fixture);
    virtual ~PhysicsBodyComponent(){
    }
    b2Body *getBody() const;
    void setBody(b2Body *value);

    // Component interface
    Component::CID getTransform() const;

protected:
    void _init(nlohmann::json json) override;
    void _deinit() override;

};

#endif // PHYSICSCOMPONENT_H
