#ifndef SQUAD_H
#define SQUADE_H
#include "Abstract_Factory_Warrior_and_Equipment.h"

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


#endif//SQUAD_H

