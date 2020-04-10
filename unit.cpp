#include "unit.h"

class Unit {
private:
    Warrior* unit_configuration;
    static int amount_of_units;
    int health;
public:
    explicit Unit(const Warrior *unit_type);
    Unit(const Unit &other);
    ~Unit() = default;
    void attack(Unit &other);
    void move();
    bool alive();
};
bool Unit::alive() {
    return this->health == 0;
}
///Остальное реализуется на след.этапах
