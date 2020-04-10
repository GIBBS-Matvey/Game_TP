#include "Abstract_Factory_Equipment.h"
#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H

class Spear : public Equipment {
    void getWeight() override;
    void getDamage() override;
};
class Sword : public Equipment {
    void getWeight() override;
    void getDamage() override;
};
class Stick : public Equipment {
    void getWeight() override;
    void getDamage() override;
};

#endif //UNIT_TYPE_H
