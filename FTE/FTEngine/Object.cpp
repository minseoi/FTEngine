//
//  Object.cpp
//  PraticeApp
//
//  Created by minseoi on 2022/02/02.
//

#include "Object.hpp"
#include "GameMaster.hpp"

Object::Object()
{}

void Object::InitializeObject(const std::string name, uint worldIndex)
{
    m_name = name;
    m_worldIndex = worldIndex;
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
