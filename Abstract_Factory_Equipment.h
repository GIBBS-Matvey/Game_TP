#ifndef Abstract_Factory_Equipment_H
#define Abstract_Factory_Equipment_H

enum WEIGHT{SPEAR_W = 50, SWORD_W = 35, STICK_W = 10};
enum DAMAGE{SPEAR_D = 20, SWORD_D = 15, STICK_D = 5};

class Equipment;
class Warrior;
class Point;
class Spear;
class Sword;
class Stick;
class Horse_Warrior;
class Infantry_Warrior;
class Ninja_Warrior;

///Abstract_Equipment_class

class Equipment {
protected:
    int weight;
    int damage;
public:
    friend class Warrior;
    friend class Horse_Warrior;
    friend class Infantry_Warrior;
    friend class Ninja_Warrior;
    friend class Spear;
    friend class Sword;
    friend class Stick;
};

class Point {
private:
    int64_t x;
    int64_t y;
public:
    Point(const int64_t &x, const int64_t &y) : x(x), y(y) {}
    Point(const Point &point) = default;
    Point& operator=(const Point &point) = default;
};

#endif //Abstract_Factory_Equipment_H
