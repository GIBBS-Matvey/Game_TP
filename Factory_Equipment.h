#include "Abstract_Factory_Equipment.h"
#ifndef Factory_Equipment_H
#define Factory_Equipment_H

class Spear : public Equipment {
public:
    Spear() {
        weight = SPEAR_W;
        damage = SPEAR_D;
    }
};

class Sword : public Equipment {
public:
    Sword() {
        weight = SWORD_W;
        damage = SWORD_D;
    }
};

class Stick : public Equipment {
public:
    Stick() {
        weight = STICK_W;
        damage = STICK_D;
    }
};

#endif //Factory_Equipment_H
