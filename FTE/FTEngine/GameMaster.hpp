//
//  GameMaster.hpp
//  PraticeApp
//
//  Created by minseoi on 2022/01/31.
//

#ifndef GameMaster_hpp
#define GameMaster_hpp

#include "Object.hpp"
#include <iostream>
#include <string>

class GameMaster
{
private:
    GameMaster(){}
    ~GameMaster();
    static GameMaster* instance;
    
    static Object** worldObjects;
    static uint currentWorldObjectCount;
    static uint maxWorldObjectsCount;
    
public:
    static GameMaster* GetInstance();
    
    static bool ApplyDamage(const Object& damagedObject, const Object& damageCauser, int damage);
    
    template <typename T>
    static T* CreateObject(const std::string name)
    {
        //if(!GetInstance()) return nullptr;
        
        auto newObject = new T();
        std::cout<<"GameMaster::CreateObejct -> New Object: "<<name<<"("<<typeid(newObject).name()<<")"<<std::endl;
        
        //T가 Object의 자식클래스임을 확인하고, 스폰을 확정
        Object* spawnedObject = static_cast<Object*>(newObject);
        if(spawnedObject == nullptr) return nullptr;
        
        
        if(currentWorldObjectCount+1 > maxWorldObjectsCount)
        {
            ++maxWorldObjectsCount;
            Object** tempObjects = new Object*[maxWorldObjectsCount];
            if(worldObjects != nullptr)
            {
                for (int i=0; i<currentWorldObjectCount; i++)
                {
                    tempObjects[i] = worldObjects[i];
                }
                delete[] worldObjects;
            }
            worldObjects = tempObjects;
        }
        worldObjects[currentWorldObjectCount] = spawnedObject;
        spawnedObject->InitializeObject(name, currentWorldObjectCount);
        ++currentWorldObjectCount;
        
        std::cout<<"GameMaster::CreateObject -> "<<"CC/MC : "<< currentWorldObjectCount<<"/"<<maxWorldObjectsCount<< std::endl;
        
        return (T*)spawnedObject;
    }
};

#endif /* GameMaster_hpp */
