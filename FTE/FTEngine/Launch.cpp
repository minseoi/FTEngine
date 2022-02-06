#include "GameMaster.hpp"
#include "Character.hpp"

int main()
{
    Character* hero = GameMaster::CreateObject<Character>("Hero");
    Character* mob = GameMaster::CreateObject<Character>("Mob");
    
    Stats heroStats;
    heroStats.health = 30;
    heroStats.attack = 10;
    heroStats.defence = 5;
    hero->InitializeState(heroStats);

    Stats mobStats;
    mobStats.health = 10;
    mobStats.attack = 3;
    mobStats.defence = 1;
    mob->InitializeState(mobStats);
    
    GameMaster::ApplyDamage(*mob, *hero, 1);
    GameMaster::ApplyDamage(*hero, *mob, 2);
    
    GameMaster::DestroyObject(mob);
    GameMaster::DestroyObject(hero);
}
