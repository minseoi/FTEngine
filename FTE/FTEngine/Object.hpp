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

class GameMaster;

#define DECLARE_FTE_OBJECT(thisClass, parentClass) \
    friend GameMaster; \
    typedef parentClass Super;\
protected: \
    thisClass(){} \

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
    
protected:
    virtual void OnCreate();
    virtual void OnDestroy();
    virtual int TakeDamage(int damage, const Object& damageCauser);
    
public:
    void Destroy();
    bool IsPendingKill();
};

#endif /* Object_hpp */
