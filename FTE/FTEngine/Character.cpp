//
//  Character.cpp
//  PraticeApp
//
//  Created by minseoi on 2022/02/02.
//

#include "Character.hpp"
#include "Math/Math.hpp"

void Character::OnCreate()
{
    Super::OnCreate();
    
    characterStateComp = new CharacterStateComponent();
}

void Character::OnDestroy()
{
    delete characterStateComp;
}

int Character::TakeDamage(int damage, const Object &damageCauser)
{
    int finalDamage = Super::TakeDamage(damage, damageCauser);
    
    if(characterStateComp != nullptr)
    {
        finalDamage -= characterStateComp->GetDefenceValue();
        
        if(finalDamage <= 0) return 0;
        characterStateComp->AddHealth(-finalDamage);
        
        if(characterStateComp->IsDead())
        {
            Destroy();
        }
    }
    
    return finalDamage;
}
