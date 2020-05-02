#include "Abstract_Factory_Warrior.h"
#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H

///_Warrior_Class.h

class Horse_Warrior : public Warrior {
public:
    Horse_Warrior();
    void move(const Point &new_point) override;
};

class Infantry_Warrior : public Warrior {
public:
    Infantry_Warrior();
    void move(const Point &new_point) override;
};

class Ninja_Warrior : public Warrior {
public:
    Ninja_Warrior();
    void move(const Point &new_point) override;
};

#endif //UNIT_TYPE_H
