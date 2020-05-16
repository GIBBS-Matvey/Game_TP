#ifndef INFANTRY_WARRIOR_H
#define INFANTRY_WARRIOR_H
#include "Abstract_Factory_Warrior.h"


class Infantry_Warrior : public Warrior {
private:
    class Sword : public Equipment {
    public:
        Sword() : Equipment(SWORD_W, SWORD_D) {}
        std::string getType() const override {
            return SWORD_TYPE;
        }
    };
public:
    Infantry_Warrior();
    bool isAlive() override {return alive;}

    int getForceToll() override {return force_toll;}

    std::string getType() override {return type;}

    int getCost() override {return cost;}

    int getForce() override {return force;}

    int getHealth() override {return health;}
};


#endif//INFANTRY_WARRIOR_H
