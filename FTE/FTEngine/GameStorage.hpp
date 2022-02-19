//
//  GameStorage.hpp
//  FTE
//
//  Created by minseoi on 2022/02/19.
//

#ifndef GameStorage_hpp
#define GameStorage_hpp

#include "Engine/GameStorageBase.h"

class GameStorage
{
private:
    GameStorage();
    static GameStorage* GetStorageInstance();

    //Recommended that the first letter of the data name be capitalized
    READONLY_DATA(float, MagicNumber)
    WRITEONLY_DATA(int, AccumDamage)
    READWRITE_DATA(int, Score)
};

#endif /* GameStorage_hpp */
