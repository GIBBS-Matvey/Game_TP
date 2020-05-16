#include "Horse_Warrior.h"

Horse_Warrior::Horse_Warrior() {
    phrase = "I'm ready to fight!";
    type = HORSE_WARRIOR;
    health = HORSE_WARRIOR_H;
    cost = HORSE_WARRIOR_C;
    force = HORSE_WARRIOR_F;
    force_toll = HORSE_WARRIOR_F_T;
    this->weapon = new Spear();
}

