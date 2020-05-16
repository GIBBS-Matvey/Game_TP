
//....................Squad_class_Implementation................///

#include "Squad.h"


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