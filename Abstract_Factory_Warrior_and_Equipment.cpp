#include "Abstract_Factory_Warrior_and_Equipment.h"

void Warrior::description() const {
    std::cout << type << '\n';
    std::cout << "Health - " << health << '\n';
    std::cout << "Forces - " << force << '\n';
    std::cout << '\n';
}

void Warrior::usingWeapon(Warrior *enemy) {
    if (force <= 0) {
        alive = false;
    } else {
        enemy->health -= weapon->damage;
        force -= force_toll;
    }
}

void Warrior::move(const Point &new_point) {
    if (this->force <= 0) {
        this->alive = false;
    } else {
        position = new_point;
        force -= force_toll * Vector({0, 0}, new_point).getLength();
    }
}
