//
//  Character.hpp
//  PraticeApp
//
//  Created by minseoi on 2022/02/02.
//

#ifndef Character_hpp
#define Character_hpp

#include "Object.hpp"
#include "Component/CharacterStateComponent.hpp"

class Character:public Object
{
    DECLARE_FTE_OBJECT(Character, Object)
    
public:
    CharacterStateComponent* characterStateComp;
    
    virtual void OnCreate() override;
    virtual void OnDestroy() override;
    
    virtual int TakeDamage(int damage, const Object& damageCauser) override;
};

#endif /* Character_hpp */
