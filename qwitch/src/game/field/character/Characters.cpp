﻿//---------------------------------------------------------------------
// 
//  
// 
//
#include "Characters.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Characters::Characters()
    : mCharacters()
{
    Character player;
    player.setPos(Vector3d(768, 768, 32));
    player.setSize(Vector3d(32, 32, 64));
    player.setRelation(Character::Relation_Friend);
    mCharacters.push_back(player);

    Character character1;
    character1.setPos(Vector3d(512, 512, 32));
    character1.setSize(Vector3d(32, 32, 64));
    character1.setRelation(Character::Relation_Enemy);
    mCharacters.push_back(character1);
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Characters::isCollision(const FieldObject& aObject) const
{
    int count = countCharacter();
    for (int i = 0; i < count; i++) {
        if (mCharacters[i].isEqual(aObject)) { continue; }
        if (mCharacters[i].isCollision(aObject)) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::move(int aIndex, const Vector3d& aPos)
{
    mCharacters[aIndex].move(aPos);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::jump(int aIndex)
{
    double jumpPower = 10;
    mCharacters[aIndex].addForce(Vector3d(0, 0, jumpPower));
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::addForce(int aIndex, const Vector3d& aForce)
{
    mCharacters[aIndex].addForce(aForce);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::setForceX(int aIndex, double aX)
{
    mCharacters[aIndex].setForceX(aX);
}
//---------------------------------------------------------------------
void Characters::setForceY(int aIndex, double aY)
{
    mCharacters[aIndex].setForceY(aY);
}
//---------------------------------------------------------------------
void Characters::setForceZ(int aIndex, double aZ)
{
    mCharacters[aIndex].setForceZ(aZ);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Characters::countCharacter() const
{
    return (int)mCharacters.size();
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Character& Characters::character(int aIndex) const
{
    return mCharacters[aIndex];
}
//---------------------------------------------------------------------
const Character& Characters::player() const
{
    return mCharacters[0];
}

} // namespace game
} // namespace qwitch