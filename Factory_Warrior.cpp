#include "Factory_Warrior.h"
#include "Factory_Equipment.h"
 
void Warrior::usingWeapon(Warrior &enemy) {
    if (this->force <= 0) {
        this->health = 0;
    } else {
        enemy.health -= this->weapon->damage;
        enemy.usingWeapon(*this);
    }
}


Horse_Warrior::Horse_Warrior() {
    phrase = "I'm ready to fight!";
    type = HORSE_WARRIOR;
    health = HORSE_WARRIOR_H;
    cost = HORSE_WARRIOR_C;
    force = HORSE_WARRIOR_F;
    this->weapon = new Spear();
}

void Horse_Warrior::move(const Point &new_point) {
    if (this->force <= 0) {
        this->health = 0;
    } else {
        location = new_point;
        this->force -= 30;
    }
}

Infantry_Warrior::Infantry_Warrior() {
    phrase = "Let's go!";
    type = INFANTRY_WARRIOR;
    health = INFANTRY_WARRIOR_H;
    cost = INFANTRY_WARRIOR_C;
    force = INFANTRY_WARRIOR_F;
    this->weapon = new Sword();
}

void Infantry_Warrior::move(const Point &new_point) {
    if (this->force <= 0) {
        this->health = 0;
    } else {
        location = new_point;
        this->force -= 200;
    }
}

Ninja_Warrior::Ninja_Warrior() {
    phrase = "I'll kill you!";
    type = NINJA_WARRIOR;
    health = NINJA_WARRIOR_H;
    cost = NINJA_WARRIOR_C;
    force = NINJA_WARRIOR_F;
    this->weapon = new Stick();
}

void Ninja_Warrior::move(const Point &new_point) {
    if (this->force <= 0) {
        this->health = 0;
    } else {
        location = new_point;
        this->force -= 80;
    }
}

#endif//UNIT_TYPE_H
