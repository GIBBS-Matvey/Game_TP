#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H
#include "Factory_Warrior.h"
#include "Factory_Equipment.h"
 
class Unit {
private:
    Warrior* unit_configuration;
    static int amount_of_units;
public:
    explicit Unit(const Warrior *unit_type);
    Unit(const Unit &other);
    ~Unit() = default;
    void attack(Unit &other);
    void move();
};
