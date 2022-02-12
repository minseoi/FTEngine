//
//  Character.cpp
//  PraticeApp
//
//  Created by minseoi on 2022/02/02.
//

#include "Character.hpp"
#include "Math/Math.hpp"

Character::Character()
{}

void Character::InitializeObject(const std::string name, uint worldIndex)
{
    Object::InitializeObject(name, worldIndex);
}

int Character::TakeDamage(int damage, const Object &damageCauser)
{
    int finalDamage = Object ::TakeDamage(damage, damageCauser);
    
    finalDamage -= this->m_defence;
    
    if(finalDamage <= 0) return 0;
    m_health = Math::IntigerClamp(m_health - finalDamage, 0, 100);
    
    if(m_health <= 0)
    {
        //OnDeath();
    }
    
    return finalDamage;
}

void Character::InitializeState(const Stats stats)
{
    m_health = stats.health;
    m_attack = stats.attack;
    m_defence = stats.defence;
}

int Character::GetAttackValue()
{
    return m_attack;
}

int Character::GetDefenceValue()
{
    return m_defence;
}
