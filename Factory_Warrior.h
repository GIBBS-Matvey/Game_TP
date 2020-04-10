#include "Abstract_Factory_Warrior.h"
#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H

class Horse_Warrior : public Warrior {
public:
    int getType() override;
    int getHealth() override;
    int getCost() override;
    int getForce() override;
    void usingWeapon(Warrior &enemy) override;
    void SpeedIncrease();
};
class Infantry_Warrior : public Warrior {
public:
    int getType() override;
    int getHealth() override;
    int getCost() override;
    int getForce() override;
    void usingWeapon(Warrior &enemy) override;
};
class Ninja_Warrior : public Warrior {
public:
    int getType() override;
    int getHealth() override;
    int getCost() override;
    int getForce() override;
    void usingWeapon(Warrior &enemy) override;
    void usingMagic();
};

#endif //UNIT_TYPE_H
