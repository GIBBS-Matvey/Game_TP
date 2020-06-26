#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<memory>


enum HEALTH{HORSE_WARRIOR_H = 100, INFANTRY_WARRIOR_H = 200, NINJA_WARRIOR_H = 300};
enum COST{HORSE_WARRIOR_C = 1000, INFANTRY_WARRIOR_C = 800, NINJA_WARRIOR_C = 900};
enum FORCE{HORSE_WARRIOR_F = 2000, INFANTRY_WARRIOR_F = 1200, NINJA_WARRIOR_F = 1600};
enum FORCE_TOLL_AFTER_ACTION{HORSE_WARRIOR_F_T = 300, INFANTRY_WARRIOR_F_T = 200, NINJA_WARRIOR_F_T = 100};

enum WEIGHT{SPEAR_W = 50, SWORD_W = 35, STICK_W = 10};
enum DAMAGE{SPEAR_D = 20, SWORD_D = 15, STICK_D = 5};


///..........exceptionClasses...........///


///..........geometryClasses...........///


class Point {
private:
   int x;
   int y;

public:
   Point(const int &x, const int &y) : x(x), y(y) {}

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
      ~Equipment() = default;
   };
   std::unique_ptr<Equipment> weapon_ptr;

public:
   virtual void description() const;
   virtual void usingWeapon(Warrior *enemy);
   virtual void change_position(const Point &new_point);
   virtual bool isAlive() const = 0;
   virtual int getForceToll() const= 0;
   virtual std::string getType() const = 0;
   virtual int getCost() const = 0;
   virtual int getForce() const = 0;
   virtual int getHealth() const = 0;
};


///..............Warrior_Implementation.h................///


class Horse_Warrior : public Warrior {
private:

   class Spear : public Equipment {
   public:
      explicit Spear(const int &value) : Equipment(value, value) {}
      Spear() : Equipment(SPEAR_W, SPEAR_D) {}
      std::string getType() const override {
         return "Spear";
      }
   };

public:
   Horse_Warrior();

   bool isAlive() const override {return alive;}

   int getForceToll() const override {return force_toll;}

   std::string getType() const override {return type;}

   int getCost() const override {return cost;}

   int getForce() const override {return force;}

   int getHealth() const override {return health;}


};



class Infantry_Warrior : public Warrior {

private:
   class Sword : public Equipment {
   public:
      Sword() : Equipment(SWORD_W, SWORD_D) {}
      std::string getType() const override {
         return "Sword";
      }
   };

public:
   Infantry_Warrior();

   bool isAlive() const override {return alive;}

   int getForceToll() const override {return force_toll;}

   std::string getType() const override {return type;}

   int getCost() const override {return cost;}

   int getForce() const override {return force;}

   int getHealth() const override {return health;}
};


class Ninja_Warrior : public Warrior {

private:
   class Stick : public Equipment {
   public:
      Stick() : Equipment(STICK_W, STICK_D) {}
      std::string getType() const override {
         return "Stick";
      }
   };

public:
   Ninja_Warrior();

   bool isAlive() const override {return alive;}

   int getForceToll() const override {return force_toll;}

   std::string getType() const override {return type;}

   int getCost() const override {return cost;}

   int getForce() const override {return force;}

   int getHealth() const override {return health;}
};


///....................Squad_class_Definition................///


class Squad {
private:
   std::vector<Warrior*> v;
   size_t size = 0;
   size_t cost = 0;
public:
   Squad() = delete;

   explicit Squad(const int &size) : size(size) {
      v.reserve(size);
   }

   explicit Squad(const int &number, Warrior *first, ...) : size(number) {
      v.reserve(number);
      Warrior **ptr = &first;
      for (int i = 0; i < number; ++i, ++ptr) {
         v.push_back(*ptr);
         cost += (*ptr)->getCost();
      }
   }

   void description() {
      for (const auto &w_ptr : v) {
         w_ptr->description();
      }
   }

   void distribute() {
      std::sort(v.begin(), v.end(), [](const Warrior *left_ptr, const Warrior *right_ptr) {
         return left_ptr->getHealth() < right_ptr->getHealth();
      });
   };

   int getCost() {
      return cost;
   }

   ~Squad() {
      for (const auto &elem : v) {
         delete elem;
      }
   }

};



///....................Player_class................///


class Player {
private:
   int money = 0;
   std::vector<Squad*> army;
   int armyCost = 0;
   std::ofstream fout;
   std::string file_name;

   void BuySquad(Squad *squad_ptr) {
      if (money >= squad_ptr->getCost()) {
         army.emplace_back(squad_ptr);
         money -= squad_ptr->getCost();
      } else {
         std::cout << "Not enough money" << std::endl;
      }
      // TODO

   }

public:
   explicit Player(const int &money, const std::string &fileName) : money(money), file_name(fileName) {
      fout.open(fileName);
      fout << "create " << fileName << std::endl;
      fout.close();
   }

   void CreateBigSquad(const int &number, Squad *first, ...) {
      army.reserve(number);
      Squad **ptr = &first;
      for (int i = 0; i < number; ++i, ++ptr) {
         BuySquad(*ptr);
      }
      // TODO
   }

   void ArmyDescription() const {
      std::cout << std::endl << "Army description:" << std::endl;
      for (const auto &sq_ptr : army) {
         sq_ptr->description();
      }
      // TODO
   }

   ~Player() {
      for (const auto &sq_ptr : army) {
         delete sq_ptr;
      }
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
      enemy->health -= weapon_ptr->damage;
      force -= force_toll;
   }
}


void Warrior::change_position(const Point &new_point) {
   if (this->force <= 0) {
      this->alive = false;
   } else {
      position = new_point;
      force -= force_toll * Vector({0, 0}, new_point).getLength();
   }
}


Horse_Warrior::Horse_Warrior() {
   type = "Horse Warrior";
   health = HORSE_WARRIOR_H;
   cost = HORSE_WARRIOR_C;
   force = HORSE_WARRIOR_F;
   force_toll = HORSE_WARRIOR_F_T;
   weapon_ptr = std::make_unique<Spear>();
}


Infantry_Warrior::Infantry_Warrior() {
   type = "Infantry Warrior";
   health = INFANTRY_WARRIOR_H;
   cost = INFANTRY_WARRIOR_C;
   force = INFANTRY_WARRIOR_F;
   force_toll = INFANTRY_WARRIOR_F_T;
   weapon_ptr = std::make_unique<Sword>();
}


Ninja_Warrior::Ninja_Warrior() {
   type = "Ninja Warrior";
   health = NINJA_WARRIOR_H;
   cost = NINJA_WARRIOR_C;
   force = NINJA_WARRIOR_F;
   force_toll = NINJA_WARRIOR_F_T;
   weapon_ptr = std::make_unique<Stick>();
}

///................main.................///


int main() {
   {
      Player me(50000, "file.txt");
      me.CreateBigSquad(3, new Squad(2, new Horse_Warrior, new Infantry_Warrior),
                        new Squad(2, new Infantry_Warrior, new Ninja_Warrior),
                        new Squad(2, new Ninja_Warrior, new Horse_Warrior));
      me.ArmyDescription();
   }

   std::cout << "valgrind checking - "<< _CrtDumpMemoryLeaks();
   return 0;
}
