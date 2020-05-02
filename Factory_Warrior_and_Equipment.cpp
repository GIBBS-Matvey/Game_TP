#include "Factory_Warrior_and_Equipment.h"
 
Horse_Warrior::Horse_Warrior() {
    phrase = "I'm ready to fight!";
    type = HORSE_WARRIOR;
    health = HORSE_WARRIOR_H;
    cost = HORSE_WARRIOR_C;
    force = HORSE_WARRIOR_F;
    force_toll = HORSE_WARRIOR_F_T;
    this->weapon = new Spear();
}

Infantry_Warrior::Infantry_Warrior() {
    phrase = "Let's go!";
    type = INFANTRY_WARRIOR;
    health = INFANTRY_WARRIOR_H;
    cost = INFANTRY_WARRIOR_C;
    force = INFANTRY_WARRIOR_F;
    force_toll = INFANTRY_WARRIOR_F_T;
    this->weapon = new Sword();
}


Ninja_Warrior::Ninja_Warrior() {
    phrase = "I'll kill you!";
    type = NINJA_WARRIOR;
    health = NINJA_WARRIOR_H;
    cost = NINJA_WARRIOR_C;
    force = NINJA_WARRIOR_F;
    force_toll = NINJA_WARRIOR_F_T;
    this->weapon = new Stick();
}
