//
//  CharacterStateComponent.hpp
//  FTE
//
//  Created by minseoi on 2022/02/13.
//

#ifndef CharacterStateComponent_hpp
#define CharacterStateComponent_hpp

#include <stdio.h>

struct Stats
{
    int health;
    int attack;
    int defence;
};

class CharacterStateComponent
{
    Stats characterStats;
    
public:
    virtual void InitializeState(const Stats stats);
    virtual bool IsDead();
    
    int AddHealth(int delta);
    
    int GetAttackValue();
    int GetDefenceValue();
};

#endif /* CharacterStateComponent_hpp */
