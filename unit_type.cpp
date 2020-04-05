#include "unit_type.h"
#include <vector>
 
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
 
void Good_Horse_Warrior::getSide() {
    this->side = GOOD;
}
void Good_Infantry_Warrior::getSide() {
    this->side = GOOD;
}
void Good_Ninja_Warrior::getSide() {
    this->side = GOOD;
}
 
void Bad_Horse_Warrior::getSide() {
    this->side = BAD;
}
void Bad_Infantry_Warrior::getSide() {
    this->side = BAD;
}
void Bad_Ninja_Warrior::getSide() {
    this->side = BAD;
}
