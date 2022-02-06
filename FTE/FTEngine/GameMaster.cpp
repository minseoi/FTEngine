//
//  GameMaster.cpp
//  PraticeApp
//
//  Created by minseoi on 2022/01/31.
//

#include "GameMaster.hpp"

GameMaster* GameMaster::instance = nullptr;

Object** GameMaster::worldObjects = nullptr;
uint GameMaster::currentWorldObjectCount=0;
uint GameMaster::maxWorldObjectsCount =0;

GameMaster::~GameMaster()
{
    if(worldObjects != nullptr)
    {
        delete[] worldObjects;
    }
}

GameMaster* GameMaster::GetInstance()
{
    if(instance == nullptr)
    {
        instance = new GameMaster();
        instance->currentWorldObjectCount=0;
        instance->maxWorldObjectsCount=0;
        std::cout<<"GameMaster::GetInstance -> Create GameMaster Instance"<<std::endl;
    }
    return instance;
}

bool GameMaster::ApplyDamage(const Object& damagedObject, const Object& damageCauser, int damage)
{
    if(damage <= 0) return false;
    int returnVal=-1;
    //return final damage
    if(worldObjects[damagedObject.m_worldIndex] != nullptr)
    {
        returnVal = worldObjects[damagedObject.m_worldIndex]->TakeDamage(damage, damageCauser);
    }
    return returnVal;
}
