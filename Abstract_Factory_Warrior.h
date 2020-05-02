#ifndef Abstract_Factory_Warrior_H
#define Abstract_Factory_Warrior_H
#include <string>
#include <Abstract_Factory_Equipment.h>

enum TYPE{HORSE_WARRIOR = 1, INFANTRY_WARRIOR, NINJA_WARRIOR};
enum HEALTH{HORSE_WARRIOR_H = 100, INFANTRY_WARRIOR_H = 200, NINJA_WARRIOR_H = 300};
enum COST{HORSE_WARRIOR_C = 1000, INFANTRY_WARRIOR_C = 800, NINJA_WARRIOR_C = 900};
enum FORCE{HORSE_WARRIOR_F = 2000, INFANTRY_WARRIOR_F = 1200, NINJA_WARRIOR_F = 1600};

///Abstract_Warrior_Class

class Warrior {
protected:
    Point location = {0, 0};
    std::string phrase;
    int type;
    int cost;
    int force;
    int health;
    Equipment* weapon;
public:
    virtual void usingWeapon(Warrior &enemy);
    virtual void move(const Point &new_point) = 0;
    friend class Equipment;
    friend class Horse_Warrior;
    friend class Infantry_Warrior;
    friend class Ninja_Warrior;
    friend class Spear;
    friend class Sword;
    friend class Stick;
};

#endif //Abstract_Factory_Warrior_H
