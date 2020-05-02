#include "gtest/gtest.h"
#include "Factory_Equipment.h"
#include "Factory_Warrior.h"

TEST(Factory_Equipment_Test, Create_Spear) {
    Spear sp;
    EXPECT_EQ(sp.getWeight(), SPEAR_W);
    EXPECT_EQ(sp.getDamage(), SPEAR_D);
}

TEST(Factory_Equipment_Test, Create_Sword) {
    Sword sw;
    EXPECT_EQ(sw.getWeight(), SWORD_W);
    EXPECT_EQ(sw.getDamage(), SWORD_D);
}

TEST(Factory_Equipment_Test, Create_Stick) {
    Stick st;
    EXPECT_EQ(st.getWeight(), STICK_W);
    EXPECT_EQ(st.getDamage(), STICK_D);
}

//Warrior_test

TEST(Factory_Warrior_Test, Create_Horse_Warrior) {
    Horse_Warrior war_h;
    EXPECT_EQ(war_h.getPhrase, "I'm ready to fight!");
    EXPECT_EQ(war_h.getType, HORSE_WARRIOR);
    EXPECT_EQ(war_h.getHealth, HORSE_WARRIOR_H);
    EXPECT_EQ(war_h.getCost, HORSE_WARRIOR_C);
    EXPECT_EQ(war_h.getForce, HORSE_WARRIOR_F);
}

TEST(Factory_Warrior_Test, Create_Infantry_Warrior) {
    Infantry war_i;
    EXPECT_EQ(war_i.getPhrase, "Let's go!");
    EXPECT_EQ(war_i.getType, INFANTRY_WARRIOR);
    EXPECT_EQ(war_i.getHealth, INFANTRY_WARRIOR_H);
    EXPECT_EQ(war_i.getCost, INFANTRY_WARRIOR_C);
    EXPECT_EQ(war_i.getForce, INFANTRY_WARRIOR_F);
}

TEST(Factory_Warrior_Test, Create_Ninja_Warrior) {
    Ninja war_n;
    EXPECT_EQ(war_n.getPhrase, "I'll kill you!");
    EXPECT_EQ(war_n.getType, NINJA_WARRIOR);
    EXPECT_EQ(war_n.getHealth, NINJA_WARRIOR_H);
    EXPECT_EQ(war_n.getCost, NINJA_WARRIOR_C);
    EXPECT_EQ(war_n.getForce, NINJA_WARRIOR_F);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
