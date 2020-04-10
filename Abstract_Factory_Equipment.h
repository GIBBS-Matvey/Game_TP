#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H

enum WEIGHT{SPEAR_W = 50, SWORD_W = 35, STICK_W = 10};
enum DAMAGE{SPEAR_D = 20, SWORD_D = 15, STICK_D = 5};

///Abstract_Equipment_class

class Equipment {
protected:
    int weight;
    int damage;
public:
    virtual void getWeight() = 0;
    virtual void getDamage() = 0;
};

#endif //UNIT_TYPE_H
