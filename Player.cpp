#include <iostream>
#include <vector>
#include "Factory_Warrior_and_Equipment.h"

class Player {
private:
    int64_t money;
    std::vector<Warrior*> army;
public:
    Player(const int64_t &money) : money(money) {}
    
    void BuyWarrior(Warrior *warrior_ptr) {
        if (money >= warrior_ptr->getCost()) {
            army.emplace_back(warrior_ptr);
            money -= army.back()->getCost();
        } else {
            std::cout << "Not enough money" << std::endl;
        }
    }
    
    int64_t GetArmyCost() {
        int64_t sum(0);
        for (Warrior *w_ptr : army) {
            sum += w_ptr->getCost();
        }
        return sum;
    }
    
    void PrintArmy() {
        for (Warrior *w_ptr : army) {
            std::cout << w_ptr->getType() << ' ';
        }
        std::cout << std::endl;
    }
};
