#ifndef UNIT_TYPE_H
#define UNIT_TYPE_H
#include <vector>
 
enum TYPE{HORSE_WARRIOR = 1, INFANTRY_WARRIOR, NINJA_WARRIOR};
enum HEALTH{HORSE_WARRIOR_H = 100, INFANTRY_WARRIOR_H = 200, NINJA_WARRIOR_H = 150};
enum COST{HORSE_WARRIOR_C = 1000, INFANTRY_WARRIOR_C = 800, NINJA_WARRIOR_C = 900};
enum FORCE{HORSE_WARRIOR_F = 2000, INFANTRY_WARRIOR_F = 1200, NINJA_WARRIOR_F = 1600};
enum SIDE{BAD, GOOD};
 
///Abstract_Class
 
class Warrior {
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
};
 
///Type_Division
 
class Horse_Warrior : public Warrior {
public:
    virtual int getType() override;
    virtual int getHealth() override;
    virtual int getCost() override;
    virtual int getForce() override;
};
class Infantry_Warrior : public Warrior {
public:
    virtual int getType() override;
    virtual int getHealth() override;
    virtual int getCost() override;
    virtual int getForce() override;
};
class Ninja_Warrior : public Warrior {
public:
    virtual int getType() override;
    virtual int getHealth() override;
    virtual int getCost() override;
    virtual int getForce() override;
};
 
///Side_division
 
class Good_Horse_Warrior : public Horse_Warrior {
public:
    virtual int getSide() override;
};
class Good_Infantry_Warrior : public Infantry_Warrior {
public:
    virtual int getSide() override;
};
class Good_Ninja_Warrior : public Ninja_Warrior {
public:
    virtual int getSide() override;
};
 
///Bad_division
class Bad_Horse_Warrior : public Horse_Warrior {
public:
    virtual int getSide() override;
};
class Bad_Infantry_Warrior : public Infantry_Warrior {
public:
    virtual int getSide() override;
};
class Bad_Ninja_Warrior : public Ninja_Warrior {
public:
    virtual int getSide() override;
};
 

#endif //UNIT_TYPE_H
