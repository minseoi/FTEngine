//
//  Object.cpp
//  PraticeApp
//
//  Created by minseoi on 2022/02/02.
//

#include "Object.hpp"
#include "GameMaster.hpp"


void Object::InitializeObject(const std::string name, uint worldIndex)
{
    m_name = name;
    m_worldIndex = worldIndex;
    pendingKill = false;
}

void Object::OnCreate()
{
    std::cout<<this->m_name<<"::Object OnCreate"<<std::endl;
}

void Object::OnDestroy()
{
    std::cout<<this->m_name<<"::Object OnDestroy"<<std::endl;
}

int Object::TakeDamage(int damage, const Object& damageCauser)
{
    std::cout<<m_name<<" Object Take '"<< damage <<"'Damage From "<< damageCauser.m_name<<std::endl;
    return damage;
}

void Object::Destroy()
{
    GameMaster::DestroyObject(this);
}

bool Object::IsPendingKill()
{
    return pendingKill;
}
