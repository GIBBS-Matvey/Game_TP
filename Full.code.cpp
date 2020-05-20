#include <iostream>
#include <string>
#include <vector>
#include "cmath"
const std::string HORSE_WARRIOR_TYPE = "Horse Warrior";
const std::string INFANTRY_WARRIOR_TYPE = "Infantry Warrior";
const std::string NINJA_WARRIOR_TYPE = "Ninja Warrior";
const std::string SPEAR_TYPE = "Spear";
const std::string SWORD_TYPE = "Sword";
const std::string STICK_TYPE = "Stick";
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


///..............Warrior_Implementation.h................///

class Horse_Warrior : public Warrior {
private:
    class Spear : public Equipment {
    public:
        Spear() : Equipment(SPEAR_W, SPEAR_D) {}
        std::string getType() const override {
            return SPEAR_TYPE;
        }
    };
public:
    Horse_Warrior();
    bool isAlive() override {return alive;}
    int getForceToll() override {return force_toll;}
    std::string getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};



class Infantry_Warrior : public Warrior {
private:
    class Sword : public Equipment {
    public:
        Sword() : Equipment(SWORD_W, SWORD_D) {}
        std::string getType() const override {
            return SWORD_TYPE;
        }
    };
public:
    Infantry_Warrior();
    bool isAlive() override {return alive;}
    int getForceToll() override {return force_toll;}
    std::string getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};


class Ninja_Warrior : public Warrior {
private:
    class Stick : public Equipment {
    public:
        Stick() : Equipment(STICK_W, STICK_D) {}
        std::string getType() const override {
            return STICK_TYPE;
        }
    };
public:
    Ninja_Warrior();
    bool isAlive() override {return alive;}
    int getForceToll() override {return force_toll;}
    std::string getType() override {return type;}
    int getCost() override {return cost;}
    int getForce() override {return force;}
    int getHealth() override {return health;}
};


///....................Squad_class_Definition................///


class Squad : public Warrior {
private:
    std::vector<Warrior*> v;
    size_t maxSize = 0;
public:
    Squad() = delete;

    explicit Squad(const size_t &size) : maxSize(size) {
        v.reserve(maxSize);
    }

    void addOneComponent(Warrior *war_ptr);

    void addSeveral(const std::string &warriorType, const size_t &number);

    bool isAlive() override;

    int getForceToll() override;

    std::string getType() override;

    int getCost() override;

    int getForce() override;

    int getHealth() override;

    void description() const override;
};


///....................Squad_class_Implementation................///




void Squad::addOneComponent(Warrior *war_ptr) {
    if (v.size() == maxSize) {
        std::cout << "Squad is full" << '\n';
    } else {
        v.push_back(war_ptr);
        std::cout << war_ptr->getType() << " added" << '\n';
    }
}

void Squad::addSeveral(const std::string &warriorType, const size_t &number) {
    if (warriorType == HORSE_WARRIOR_TYPE) {
        for (size_t i = 0; i < number; ++i) {
            this->addOneComponent(new Horse_Warrior);
            if (v.size() == maxSize) {
                return;
            }
        }
    }
    else if (warriorType == INFANTRY_WARRIOR_TYPE) {
        for (size_t i = 0; i < number; ++i) {
            this->addOneComponent(new Infantry_Warrior);
            if (v.size() == maxSize) {
                return;
            }
        }
    }
    else if (warriorType == NINJA_WARRIOR_TYPE) {
        for (size_t i = 0; i < number; ++i) {
            this->addOneComponent(new Ninja_Warrior);
            if (v.size() == maxSize) {
                return;
            }
        }
    }
}

bool Squad::isAlive() {
    for (const auto &elem : v) {
        if (elem->isAlive()) {
            return true;
        }
    }
    return false;
}

int Squad::getForceToll() {
    int result = 0;
    for (const auto &elem : v) {
        result += elem->getForceToll();
    }
    return result;
}

std::string Squad::getType() {
    return ("It is a squad");
}


int Squad::getCost() {
    int result = 0;
    for (const auto &elem : v) {
        result += elem->getCost();
    }
    return result;
}

int Squad::getForce()  {
    int result = 0;
    for (const auto &elem : v) {
        result += elem->getForce();
    }
    return result;
}

int Squad::getHealth()  {
    int result = 0;
    for (const auto &elem : v) {
        result += elem->getHealth();
    }
    return result;
}

void Squad::description() const {
    for (const auto &elem : v) {
        elem->description();
    }
}



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

Horse_Warrior::Horse_Warrior() {
    type = HORSE_WARRIOR_TYPE;
    health = HORSE_WARRIOR_H;
    cost = HORSE_WARRIOR_C;
    force = HORSE_WARRIOR_F;
    force_toll = HORSE_WARRIOR_F_T;
    this->weapon = new Spear;
}

Infantry_Warrior::Infantry_Warrior() {
    type = INFANTRY_WARRIOR_TYPE;
    health = INFANTRY_WARRIOR_H;
    cost = INFANTRY_WARRIOR_C;
    force = INFANTRY_WARRIOR_F;
    force_toll = INFANTRY_WARRIOR_F_T;
    this->weapon = new Sword;
}


Ninja_Warrior::Ninja_Warrior() {
    type = NINJA_WARRIOR_TYPE;
    health = NINJA_WARRIOR_H;
    cost = NINJA_WARRIOR_C;
    force = NINJA_WARRIOR_F;
    force_toll = NINJA_WARRIOR_F_T;
    this->weapon = new Stick;
}



///................main.................///


int main() {
    Horse_Warrior h_w;
    Infantry_Warrior i_w;
    Ninja_Warrior n_w;

    Squad littleSquad(4);
    Squad middleSquad(5);
    Squad bigSquad(10);

    littleSquad.addOneComponent(new Horse_Warrior);
    littleSquad.addSeveral(INFANTRY_WARRIOR_TYPE, 3);
    littleSquad.addSeveral(NINJA_WARRIOR_TYPE, 2);

    middleSquad.addOneComponent(&littleSquad);
    littleSquad.description();


    return 0;
}
