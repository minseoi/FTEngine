//
//  GameMaster.hpp
//  PraticeApp
//
//  Created by minseoi on 2022/01/31.
//

#ifndef GameMaster_hpp
#define GameMaster_hpp

#include "Object.hpp"
#include "DataStructure/Queue.hpp"
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
    
    static Queue<int> objectIndexesToRecycle;
    
public:
    static GameMaster* GetInstance();
    
    static bool ApplyDamage(const Object& damagedObject, const Object& damageCauser, int damage);
    
    static void DestroyObject(Object* object);
    
    template <typename T>
    static T* CreateObject(const std::string name)
    {
        //if(!GetInstance()) return nullptr;
        
        auto newObject = new T();
        std::cout<<"GameMaster::CreateObejct -> New Object: "<<name<<"("<<typeid(newObject).name()<<")"<<std::endl;
        
        //T가 Object의 자식클래스임을 확인하고, 스폰을 확정
        Object* spawnedObject = static_cast<Object*>(newObject);
        if(spawnedObject == nullptr) return nullptr;
        
        int indexForSpawn = -1;
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
            
            indexForSpawn = currentWorldObjectCount;
        }
        else
        {
            if(objectIndexesToRecycle.Num() > 0)
            {
                objectIndexesToRecycle.Pop(indexForSpawn);
            }
        }
        
        worldObjects[indexForSpawn] = spawnedObject;
        spawnedObject->InitializeObject(name, indexForSpawn);
        ++currentWorldObjectCount;
        
        std::cout<<"GameMaster::CreateObject -> "<<"CC/MC: "<< currentWorldObjectCount<<"/"<<maxWorldObjectsCount<<" | indexForSpawn: "<<indexForSpawn<< std::endl;
        
        spawnedObject->OnCreate();
        return (T*)spawnedObject;
    }
};

#endif /* GameMaster_hpp */
