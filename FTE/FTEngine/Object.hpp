//
//  Object.hpp
//  PraticeApp
//
//  Created by minseoi on 2022/02/02.
//

#ifndef Object_hpp
#define Object_hpp

#include <iostream>
#include <string>
#include "Engine/ObjectBase.h"
#include "Math/Vector2.h"

class GameMaster;

class Object
{
    friend GameMaster;
private:
    void InitializeObject(const std::string name, uint worldIndex);

protected:
    Object(){}
    
private:
    uint m_worldIndex;
    std::string m_name;
    bool pendingKill;
    vector2 location;
    
protected:
    virtual void OnCreate();
    virtual void OnDestroy();
    virtual int TakeDamage(int damage, const Object& damageCauser);
    
public:
    void Destroy();
    bool IsPendingKill();
    vector2 GetObjectLocation()const;
    void SetObjectLocation(const vector2& location);
};

#endif /* Object_hpp */
