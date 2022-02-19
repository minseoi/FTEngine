//
//  GameStorage.cpp
//  FTE
//
//  Created by minseoi on 2022/02/19.
//

#include "GameStorage.hpp"

GameStorage::GameStorage()
{
    MagicNumber = 3.14;
}

static GameStorage* Self;
GameStorage* GameStorage::GetStorageInstance()
{
    if(Self == nullptr)
    {
        Self = new GameStorage();
    }
    
    return Self;
}
