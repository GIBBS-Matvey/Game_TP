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
    int64_t GetArmyCost() {
        return armyCost;
    }
    void PrintArmy() {
        for (Warrior *w_ptr : army) {
            std::cout << "Warrior_type is "<< w_ptr->getType() << ' ' << std::endl;
            std::cout << "Health is " << w_ptr->getHealth() << ' ' << std::endl;
            std::cout << "Force is " << w_ptr->getForce() << ' ' << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};
