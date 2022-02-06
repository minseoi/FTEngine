//
//  Character.hpp
//  PraticeApp
//
//  Created by minseoi on 2022/02/02.
//

#ifndef Character_hpp
#define Character_hpp

#include "Object.hpp"

struct Stats
{
    int health;
    int attack;
    int defence;
};

class Character:public Object
{
    DECLARE_FTE_OBJECT(Character)
    
private:    
    int m_health;
    int m_attack;
    int m_defence;

//protected:
public:
    virtual int TakeDamage(int damage, const Object& damageCauser) override;
    
public:
    void InitializeState(const Stats stats);
    
    int GetAttackValue();
    int GetDefenceValue();
};

#endif /* Character_hpp */
