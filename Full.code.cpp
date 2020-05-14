#include <iostream>
#include <string>
#include <utility>
#include <vector>
enum TYPE{HORSE_WARRIOR = 1, INFANTRY_WARRIOR, NINJA_WARRIOR};
enum HEALTH{HORSE_WARRIOR_H = 100, INFANTRY_WARRIOR_H = 200, NINJA_WARRIOR_H = 300};
enum COST{HORSE_WARRIOR_C = 1000, INFANTRY_WARRIOR_C = 800, NINJA_WARRIOR_C = 900};
enum FORCE{HORSE_WARRIOR_F = 2000, INFANTRY_WARRIOR_F = 1200, NINJA_WARRIOR_F = 1600};
enum FORCE_TOLL_AFTER_ACTION{HORSE_WARRIOR_F_T = 300, INFANTRY_WARRIOR_F_T = 200, NINJA_WARRIOR_F_T = 100};

enum WEIGHT{SPEAR_W = 50, SWORD_W = 35, STICK_W = 10};
enum DAMAGE{SPEAR_D = 20, SWORD_D = 15, STICK_D = 5};



///..........geometryClasses...........///


class Point {
private:
    int64_t x;
    int64_t y;
public:
    Point(const int64_t &x, const int64_t &y) : x(x), y(y) {}
    Point(const Point &point) = default;
    Point& operator=(const Point &point) = default;
    friend class Vector;
};

class Vector {
private:
    Point p1;
    Point p2;
public:
    Vector(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}
    int getLength() const {
        return pow(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2), 0.5);
    }
};

///..............Abstract_Warrior_Class...............///


class Warrior {
protected:
    Point position = {0, 0};
    std::string phrase;
    int type;
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
    };
    Equipment* weapon;
public:
    virtual void usingWeapon(Warrior *enemy);
    virtual void move(const Point &new_point);
    virtual bool isAlive() = 0;
    virtual std::string getPhrase() = 0;
    virtual int getForceToll() = 0;
    virtual int getType() = 0;
    virtual int getCost() = 0;
    virtual int getForce() = 0;
    virtual int getHealth() = 0;
};


///..............Warrior_Class.h................///

class Horse_Warrior : public Warrior {
private:
    class Spear : public Equipment {
    public:
        Spear() : Equipment(SPEAR_W, SPEAR_D) {}
    };
public:
    Horse_Warrior();
    bool isAlive() override {return alive;}
    std::string getPhrase() override {return phrase;}
    int getForceToll() override {return force_toll;}
    int getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};



class Infantry_Warrior : public Warrior {
private:
    class Sword : public Equipment {
    public:
        Sword() : Equipment(SWORD_W, SWORD_D) {}
    };
public:
    Infantry_Warrior();
    bool isAlive() override {return alive;}
    std::string getPhrase() override {return phrase;}
    int getForceToll() override {return force_toll;}
    int getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};


class Ninja_Warrior : public Warrior {
private:
    class Stick : public Equipment {
    public:
        Stick() : Equipment(STICK_W, STICK_D) {}
    };
public:
    Ninja_Warrior();
    bool isAlive() override {return alive;}
    std::string getPhrase() override {return phrase;}
    int getForceToll() override {return force_toll;}
    int getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};



///....................Player_class................///
class Player {
private:
    int64_t money;
    std::vector<Warrior*> army;
    int64_t armyCost = 0;
public:
    explicit Player(const int64_t &money) : money(money) {}

    void BuyWarrior(Warrior *warrior_ptr) {
        if (money >= warrior_ptr->getCost()) {
            army.emplace_back(warrior_ptr);
            money -= army.back()->getCost();
            armyCost += warrior_ptr->getCost();
        } else {
            std::cout << "Not enough money" << std::endl;
        }
    }
    int64_t GetArmyCost() const {
        return armyCost;
    }
    void PrintArmy() {
        for (Warrior *w_ptr : army) {
            if (!army.empty()) {
                std::cout << "Warrior_type is " << w_ptr->getType() << ' ' << std::endl;
                std::cout << "Health is " << w_ptr->getHealth() << ' ' << std::endl;
                std::cout << "Force is " << w_ptr->getForce() << ' ' << std::endl;
                std::cout << std::endl;
            } else {
                std::cout << "There is no warriors in your army" << std::endl;
            }
        }
        std::cout << std::endl;
    }
};


///...............definition..................///



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

Horse_Warrior::Horse_Warrior() {
    phrase = "I'm ready to fight!";
    type = HORSE_WARRIOR;
    health = HORSE_WARRIOR_H;
    cost = HORSE_WARRIOR_C;
    force = HORSE_WARRIOR_F;
    force_toll = HORSE_WARRIOR_F_T;
    this->weapon = new Spear();
}

Infantry_Warrior::Infantry_Warrior() {
    phrase = "Let's go!";
    type = INFANTRY_WARRIOR;
    health = INFANTRY_WARRIOR_H;
    cost = INFANTRY_WARRIOR_C;
    force = INFANTRY_WARRIOR_F;
    force_toll = INFANTRY_WARRIOR_F_T;
    this->weapon = new Sword();
}


Ninja_Warrior::Ninja_Warrior() {
    phrase = "I'll kill you!";
    type = NINJA_WARRIOR;
    health = NINJA_WARRIOR_H;
    cost = NINJA_WARRIOR_C;
    force = NINJA_WARRIOR_F;
    force_toll = NINJA_WARRIOR_F_T;
    this->weapon = new Stick();
}



int main() {
    Horse_Warrior h_w;
    Infantry_Warrior i_w;
    Ninja_Warrior n_w;



    Player Me(10000);
    Me.BuyWarrior(&h_w);
    Me.BuyWarrior(&i_w);
    Me.BuyWarrior(&n_w);
    Me.PrintArmy();


}

