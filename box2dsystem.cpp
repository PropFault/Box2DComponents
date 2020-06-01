#include "box2dsystem.h"
#include <set>
#include "physicsbodycomponent.h"
#include "../BlastCompany/transform.h"
#include <vector>
#include "physicsfixturecomponent.h"
#include <ctime>

Box2dSystem::Box2dSystem(const b2Vec2 gravity,float timeStep,int32 velocityIterations,int32 positionIterations)
    :System(""), world(gravity), timeStep(timeStep), velocityIterations(velocityIterations), positionIterations(positionIterations), lastExec(clock())
{

}

std::vector<PhysicsFixtureComponent*> findFixturesInEntity(Entity::EID entity, EntityComponentManager &ecs){
    std::vector<PhysicsFixtureComponent*> fixtures;
    for(auto cid : ecs.lookupCIDsForEntity(entity)){
        Component* comp = ecs.lookupCID<Component>(cid);
        if(comp->getTypeName() == "circlefixture" || comp->getTypeName() == "boxfixture"){
            fixtures.push_back(dynamic_cast<PhysicsFixtureComponent*>(comp));
        }
    }
    return fixtures;
}


void Box2dSystem::think(EntityComponentManager &ecs, const std::unordered_set<Component::CID> &typedComponents, System::DataPack &dataPack)
{
    std::set<Component::CID> cids;
    const auto & staticbodies = ecs.lookupCIDsForType("staticbody");
    const auto & dynamicbodies = ecs.lookupCIDsForType("dynamicbody");
    cids.insert(staticbodies.begin(), staticbodies.end());
    cids.insert(dynamicbodies.begin(), dynamicbodies.end());

    bool simNeeded = true;

    for(auto cid : cids){
        PhysicsBodyComponent *body = ecs.lookupCID<PhysicsBodyComponent>(cid);
        std::cout<<"HANDLING PHYSICS FOR ENTITY " << body->getEntity() << std::endl;
        Transform *transform = ecs.lookupCID<Transform>(body->getTransform());

        if(body->getBody() == NULL)
        {
            b2BodyDef bodyDef(body->getBodyDefinition());
            bodyDef.position.Set(transform->getPosition().getX(), transform->getPosition().getY());
            body->setBody(this->world.CreateBody(&bodyDef));
            for(PhysicsFixtureComponent* fixture:findFixturesInEntity(body->getEntity(), ecs)){
                auto def = fixture->getFixtureDefinition();
                body->getBody()->CreateFixture(&def);
            }
        }
        if(((clock()-lastExec)/(double)CLOCKS_PER_SEC)>=this->timeStep){
            if(simNeeded){
                this->world.Step(this->timeStep, this->velocityIterations, this->positionIterations);
                simNeeded = false;
            }
            lastExec = clock();
        }
        b2Vec2 position = body->getBody()->GetPosition();
        transform->setPosition(Vec2(position.x, position.y));
        std::cout<<"SETTING POS TO " << transform->getPosition() << std::endl;
    }
}
