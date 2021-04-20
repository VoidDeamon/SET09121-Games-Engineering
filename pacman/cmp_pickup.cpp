#include "cmp_pickup.h"

PickupComponent::PickupComponent(Entity* p) : Component(p) {}

void PickupComponent::update(double) {
    //for (auto& e : getEnts()) {       //every entity in the scene
    //    if (...) {      //within 30.f unit of me
    //        ...               //get the entity ActorMovementComponent, if it has one
    //            if (...) {        //if it has one
    //              // nom nom
    //                ...                      //speed the entity up
    //                    _parent->setForDelete(); //delete myself
    //                break;                   //stop looking
    //            }
    //    }
    //}
}