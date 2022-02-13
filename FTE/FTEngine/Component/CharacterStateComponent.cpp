//
//  CharacterStateComponent.cpp
//  FTE
//
//  Created by minseoi on 2022/02/13.
//

#include "CharacterStateComponent.hpp"
#include "../Math/Math.hpp"

void CharacterStateComponent::InitializeState(const Stats stats)
{
    characterStats = stats;
}

bool CharacterStateComponent::IsDead()
{
    if(characterStats.health > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int CharacterStateComponent::AddHealth(int delta)
{
    Math::IntigerClamp(characterStats.health, 0, 100);
    
    return characterStats.health;
}

int CharacterStateComponent::GetAttackValue()
{
    return characterStats.attack;
}

int CharacterStateComponent::GetDefenceValue()
{
    return characterStats.defence;
}
