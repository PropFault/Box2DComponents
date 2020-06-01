#ifndef BOX2DSYSTEM_H
#define BOX2DSYSTEM_H
#include "../BlastCompany/system.h"
#include <Box2D/Box2D.h>
class Box2dSystem : public System
{
private:
    b2World world;
    int32 velocityIterations;
    int32 positionIterations;
    float timeStep;
    clock_t lastExec;
public:
    Box2dSystem(const b2Vec2 gravity,float timeStep,int32 velocityIterations,int32 positionIterations);

    // System interface
public:
    void think(EntityComponentManager &ecs, const std::unordered_set<Component::CID> &typedComponents, DataPack &dataPack) override;
};

#endif // BOX2DSYSTEM_H
