#include "Infantry_Warrior.h"

Infantry_Warrior::Infantry_Warrior() {
    phrase = "Let's go!";
    type = INFANTRY_WARRIOR;
    health = INFANTRY_WARRIOR_H;
    cost = INFANTRY_WARRIOR_C;
    force = INFANTRY_WARRIOR_F;
    force_toll = INFANTRY_WARRIOR_F_T;
    this->weapon = new Sword();
}

