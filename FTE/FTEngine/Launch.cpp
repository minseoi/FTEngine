#include "GameMaster.hpp"
#include "Character.hpp"

int main()
{
    Character* hero = GameMaster::CreateObject<Character>("Hero");
    Character* mob = GameMaster::CreateObject<Character>("Mob");
    
    std::cout<<hero->GetObjectLocation().ToString()<<std::endl;
    hero->SetObjectLocation(vector2(3, -3));
    std::cout<<hero->GetObjectLocation().ToString()<<std::endl;

    std::cout<<mob->GetObjectLocation().ToString()<<std::endl;
    mob->SetObjectLocation(vector2(0, 3));
    std::cout<<mob->GetObjectLocation().ToString()<<std::endl;
    
    vector2 heroLoc = hero->GetObjectLocation();
    vector2 mobLoc = mob->GetObjectLocation();
    heroLoc.Normalize();
    mobLoc.Normalize();
    std::cout<<heroLoc.dot(mobLoc)<<std::endl;
    
    Stats heroStats;
    heroStats.health = 30;
    heroStats.attack = 10;
    heroStats.defence = 5;
    hero->characterStateComp->InitializeState(heroStats);
    
    Stats mobStats;
    mobStats.health = 10;
    mobStats.attack = 3;
    mobStats.defence = 1;
    hero->characterStateComp->InitializeState(mobStats);

    GameMaster::ApplyDamage(*mob, *hero, 100);
    GameMaster::ApplyDamage(*hero, *mob, 2);

    GameMaster::DestroyObject(mob);

    Object* tempObj = GameMaster::CreateObject<Object>("TempObj");
    tempObj->Destroy();

    GameMaster::DestroyObject(hero);
}
