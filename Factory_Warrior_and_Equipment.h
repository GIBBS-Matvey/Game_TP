#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H
#include "Abstract_Factory_Warrior.h"

///..............Warrior_Class.h................///

class Horse_Warrior : public Warrior {
private:
    class Spear : public Equipment {
    public:
        Spear() : Equipment(SPEAR_W, SPEAR_D) {}
    };
public:
    Horse_Warrior();
    bool isAlive() override {return alive;}
    std::string getPhrase() override {return phrase;}
    virtual int getForceToll() override {return force_toll;}
    int getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};



class Infantry_Warrior : public Warrior {
private:
    class Sword : public Equipment {
    public:
        Sword() : Equipment(SWORD_W, SWORD_D) {}
    };
public:
    Infantry_Warrior();
    std::string getPhrase() override {return phrase;}
    int getForceToll() override {return force_toll;}
    bool isAlive() override {return alive;}
    int getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};


class Ninja_Warrior : public Warrior {
private:
    class Stick : public Equipment {
    public:
        Stick() : Equipment(STICK_W, STICK_D) {}
    };
public:
    Ninja_Warrior();
    bool isAlive() override {return alive;}
    std::string getPhrase() override {return phrase;}
    int getForceToll() override {return force_toll;}
    int getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};


#endif //UNIT_TYPE_H
