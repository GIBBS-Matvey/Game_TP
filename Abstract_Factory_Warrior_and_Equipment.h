#ifndef Abstract_Factory_Warrior_H
#define Abstract_Factory_Warrior_H
#include "geometry.h"
#include <string>
#include <vector>

const std::string HORSE_WARRIOR_TYPE = "Horse Warrior";
const std::string INFANTRY_WARRIOR_TYPE = "Infantry Warrior";
const std::string NINJA_WARRIOR_TYPE = "Ninja Warrior";
const std::string SPEAR_TYPE = "Spear";
const std::string SWORD_TYPE = "Sword";
const std::string STICK_TYPE = "Stick";
enum TYPE{HORSE_WARRIOR = 1, INFANTRY_WARRIOR, NINJA_WARRIOR};
enum HEALTH{HORSE_WARRIOR_H = 100, INFANTRY_WARRIOR_H = 200, NINJA_WARRIOR_H = 300};
enum COST{HORSE_WARRIOR_C = 1000, INFANTRY_WARRIOR_C = 800, NINJA_WARRIOR_C = 900};
enum FORCE{HORSE_WARRIOR_F = 2000, INFANTRY_WARRIOR_F = 1200, NINJA_WARRIOR_F = 1600};
enum FORCE_TOLL_AFTER_ACTION{HORSE_WARRIOR_F_T = 300, INFANTRY_WARRIOR_F_T = 200, NINJA_WARRIOR_F_T = 100};

enum WEIGHT{SPEAR_W = 50, SWORD_W = 35, STICK_W = 10};
enum DAMAGE{SPEAR_D = 20, SWORD_D = 15, STICK_D = 5};


///..............Abstract_Warrior_Class...............///


class Warrior {
protected:
    Point position = {0, 0};

    std::string type;

    int cost;

    int force;

    int health;

    int force_toll;

    bool alive = true;

    class Equipment {
    public:
        int weight;

        int damage;

        Equipment(const int &w, const int &d) : weight(w), damage(d) {}

        virtual std::string getType() const = 0;
    };

    Equipment* weapon;
    
public:
    virtual void description() const;

    virtual void usingWeapon(Warrior *enemy);

    virtual void move(const Point &new_point);

    virtual bool isAlive() = 0;

    virtual int getForceToll() = 0;

    virtual std::string getType() = 0;

    virtual int getCost() = 0;

    virtual int getForce() = 0;

    virtual int getHealth() = 0;
};



#endif//Abstract_Factory_Warrior_H
