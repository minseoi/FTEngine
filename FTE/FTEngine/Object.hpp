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

#define DECLARE_FTE_OBJECT(objectName) \
    friend GameMaster; \
protected: \
    objectName(); \
    virtual void InitializeObject(const std::string name, uint worldIndex) override;

class Object
{
    friend GameMaster;
protected:
    Object();
    virtual void InitializeObject(const std::string name, uint worldIndex);
    
private:
    uint m_worldIndex;
    std::string m_name;
    
    virtual void OnDestroy();
    
protected:
    virtual int TakeDamage(int damage, const Object& damageCauser);
    
public:
    void Destroy();
};

#endif /* Object_hpp */
