#ifndef NINJA_WARRIOR_H
#define NINJA_WARRIOR_H
#include "Abstract_Factory_Warrior.h"


class Ninja_Warrior : public Warrior {
private:
    class Stick : public Equipment {
    public:
        Stick() : Equipment(STICK_W, STICK_D) {}

        std::string getType() const override {
            return STICK_TYPE;
        }
    };
public:
    Ninja_Warrior();

    bool isAlive() override {return alive;}

    int getForceToll() override {return force_toll;}

    std::string getType() override {return type;}

    int getCost() override {return cost;}

    int getForce() override {return force;}

    int getHealth() override {return health;}
};


#endif//NINJA_WARRIOR_H
