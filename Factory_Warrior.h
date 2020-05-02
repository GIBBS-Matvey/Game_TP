#include "Abstract_Factory_Warrior.h"
#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H

class Horse_Warrior : public Warrior {
public:
    void getType() override;
    void getHealth() override;
    void getCost() override;
    void getForce() override;
    void usingWeapon(Warrior &enemy) override;
    void SpeedIncrease();
};
class Infantry_Warrior : public Warrior {
public:
    void getType() override;
    void getHealth() override;
    void getCost() override;
    void getForce() override;
    void usingWeapon(Warrior &enemy) override;
};
class Ninja_Warrior : public Warrior {
public:
    void getType() override;
    void getHealth() override;
    void getCost() override;
    void getForce() override;
    void usingWeapon(Warrior &enemy) override;
    void usingMagic();
};

#endif //UNIT_TYPE_H
