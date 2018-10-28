//---------------------------------------------------------------------
// 
//  
// 
//
#include "Characters.hpp"
#include "game/field/FieldParameter.hpp"

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
    player.setPos(Vector3d(64, 64, 32));
    player.setSize(Vector3d(32, 32, 64));
    player.setRelation(FieldObject::Relation_Friend);
    player.setKind(0);
    mCharacters.push_back(player);
    /*
    Character character1;
    character1.setPos(Vector3d(512, 512, 32));
    character1.setSize(Vector3d(32, 32, 64));
    character1.setRelation(FieldObject::Relation_Enemy);
    character1.setKind(1);
    mCharacters.push_back(character1);*/
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::update(const Camera& aCamera)
{
    //----- アニメーションの更新
    int count = countCharacter();
    for (int i = 0; i < count; i++) {
        mCharacters[i].update();
    }

    //----- 死亡処理
    for (int i = count - 1; i >= 0; i--) {
        if (mCharacters[i].status().isDeath()) {
            mCharacters.erase(mCharacters.begin() + i);
        }
    }

    //----- 描画キャラの設定
    mDisplayCharacters.clear();

    double cx = aCamera.fieldPos().x();
    double cy = aCamera.fieldPos().y();
    double cz = aCamera.fieldPos().z();

    count = countCharacter();
    for (int i = 0; i < count; i++) {
        double px = mCharacters[i].pos().x();
        double py = mCharacters[i].pos().y();
        double pz = mCharacters[i].pos().z();
        double size = 0;
        size += abs(cx - px);
        size += abs(cy - py);
        size += abs(cz - pz);
        if (size >= FieldParameter::RenderAreaSize) { continue; }
        mDisplayCharacters.push_back(mCharacters[i]);
    }
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
    double jumpPower = mCharacters[aIndex].status().jumpPower();
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
void Characters::receiveDamage(int aIndex, int aDamage)
{
    mCharacters[aIndex].receiveDamage(aDamage);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::reduceMp(int aIndex, int aValue)
{
    mCharacters[aIndex].reduceMp(aValue);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::setAnimation(int aIndex, Animation::Kind aKind)
{
    mCharacters[aIndex].setAnimation(aKind);
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
void Characters::setDirection(int aIndex, int aX, int aY, int aZ)
{
    mCharacters[aIndex].setDirection(aX, aY, aZ);
}
//---------------------------------------------------------------------
void Characters::setDirection(int aIndex, double aX, double aY, double aZ)
{
    setDirection(aIndex, (int)aX, (int)aY, (int)aZ);
}
//---------------------------------------------------------------------
void Characters::setMagicIndex(int aCharaIndex, int aMagicIndex)
{
    mCharacters[aCharaIndex].setMagicIndex(aMagicIndex);
}
//---------------------------------------------------------------------
void Characters::setAnimeSpeed(int aIndex, int aSpeed)
{
    mCharacters[aIndex].setAnimeSpeed(aSpeed);
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
int Characters::countDisplayCharacter() const
{
    return (int)mDisplayCharacters.size();
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
//---------------------------------------------------------------------
const Character& Characters::displayCharacter(int aIndex) const
{
    return mDisplayCharacters[aIndex];
}

} // namespace game
} // namespace qwitch