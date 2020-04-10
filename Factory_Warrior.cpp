#include "Factory_Warrior.h"
#include "Factory_Equipment.h"
 
void Horse_Warrior::getType() {
    this->type = HORSE_WARRIOR;
}
void Horse_Warrior::getHealth() {
    this->health = HORSE_WARRIOR_H;
}
void Horse_Warrior::getCost() {
    this->cost = HORSE_WARRIOR_C;
}
void Horse_Warrior::getForce() {
    this->force = HORSE_WARRIOR_F;
}
void Horse_Warrior::usingWeapon(Warrior &enemy) {
    Spear spear;
    spear.getDamage();
    spear.getWeight();
    enemy.health -= spear.damage;
}

void Infantry_Warrior::getType() {
    this->type = INFANTRY_WARRIOR;
}
void Infantry_Warrior::getHealth() {
    this->health = INFANTRY_WARRIOR_H;
}
void Infantry_Warrior::getCost() {
    this->cost = INFANTRY_WARRIOR_C;
}
void Infantry_Warrior::getForce() {
    this->force = INFANTRY_WARRIOR_F;
}
void Infantry_Warrior::usingWeapon(Warrior &enemy) {
    Sword sword;
    sword.getDamage();
    sword.getWeight();
    enemy.health -= sword.damage;
}
 
void Ninja_Warrior::getType() {
    this->type = NINJA_WARRIOR;
}
void Ninja_Warrior::getHealth() {
    this->health = NINJA_WARRIOR_H;
}
void Ninja_Warrior::getCost() {
    this->cost = NINJA_WARRIOR_C;
}
void Ninja_Warrior::getForce() {
    this->force = NINJA_WARRIOR_F;
}
void Ninja_Warrior::usingWeapon(Warrior &enemy) {
    Stick stick;
    steak.getDamage();
    steak.getWeight();
    enemy.health -= sword.damage;
}

