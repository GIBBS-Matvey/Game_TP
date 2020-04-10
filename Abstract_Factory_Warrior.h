#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H

enum TYPE{HORSE_WARRIOR = 1, INFANTRY_WARRIOR, NINJA_WARRIOR};
enum HEALTH{HORSE_WARRIOR_H = 100, INFANTRY_WARRIOR_H = 200, NINJA_WARRIOR_H = 300};
enum COST{HORSE_WARRIOR_C = 1000, INFANTRY_WARRIOR_C = 800, NINJA_WARRIOR_C = 900};
enum FORCE{HORSE_WARRIOR_F = 2000, INFANTRY_WARRIOR_F = 1200, NINJA_WARRIOR_F = 1600};
enum SIDE{BAD, GOOD};

///Abstract_Warrior_Class

class Warrior {
protected:
    int health;
    int cost;
    int force;
    int side;
public:
    virtual int getType() = 0;
    virtual int getHealth() = 0;
    virtual int getCost() = 0;
    virtual int getForce() = 0;
    virtual int getSide() = 0;
    virtual void usingWeapon(Warrior &enemy) = 0;
};

#endif //UNIT_TYPE_H
