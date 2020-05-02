#include "Abstract_Factory_Equipment.h"
#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H

class Spear : public Equipment {
    int getWeight() override;
    int getDamage() override;
};
class Sword : public Equipment {
    int getWeight() override;
    int getDamage() override;
};
class Stick : public Equipment {
    int getWeight() override;
    int getDamage() override;
};

#endif //UNIT_TYPE_H
