#ifndef HORSE_WARRIOR_H
#define HORSE_WARRIOR_H
#include "Abstract_Factory_Warrior.h"


class Horse_Warrior : public Warrior {
private:
    class Spear : public Equipment {
    public:
        Spear() : Equipment(SPEAR_W, SPEAR_D) {}

        std::string getType() const override {
            return SPEAR_TYPE;
        }
    };
public:
    Horse_Warrior();

    bool isAlive() override {return alive;}

    int getForceToll() override {return force_toll;}

    std::string getType() override {return type;}

    int getCost() override {return cost;}

    int getForce() override {return force;}

    int getHealth() override {return health;}
};


#endif//HORSE_WARRIOR_H
