#include "Ninja_Warrior.h"

Ninja_Warrior::Ninja_Warrior() {
    phrase = "I'll kill you!";
    type = NINJA_WARRIOR;
    health = NINJA_WARRIOR_H;
    cost = NINJA_WARRIOR_C;
    force = NINJA_WARRIOR_F;
    force_toll = NINJA_WARRIOR_F_T;
    this->weapon = new Stick();
}

