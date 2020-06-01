#include <iostream>
#include "../BlastCompany/componentplugin.h"
#include "staticbodycomponent.h"
#include "dynamicbodycomponent.h"
#include "circlefixturecomponent.h"
#include "../BlastCompany/window.h"
#include <boost/config.hpp>
#include <iostream>
#include "box2dsystem.h"
#include "boxfixturecomponent.h"
using namespace std;

namespace plugins {
class PhyiscsComponentPlugin : public ComponentPlugin{
public:


    // ComponentPlugin interface
public:


    // ComponentPlugin interface
public:
    void onRegisterComponents(const Window &window, const SDLRenderer &renderer, EntityComponentManager &ecm) override{
        ecm.registerBlueprint(new StaticBodyComponent);
        ecm.registerBlueprint(new DynamicBodyComponent);
        ecm.registerBlueprint(new CircleFixtureComponent);
        ecm.registerBlueprint(new BoxFixtureComponent);
    }
    void onRegisterSystems(SystemPipeline &pipeline) override{
        pipeline.add(new Box2dSystem(b2Vec2(0.0f,10.0f), 1.0f/60.0f, 8,3));
    }
};
extern "C" BOOST_SYMBOL_EXPORT PhyiscsComponentPlugin plugin;
PhyiscsComponentPlugin plugin;
}
