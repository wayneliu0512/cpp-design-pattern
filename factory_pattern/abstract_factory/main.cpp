#include <iostream>
#include "drink_factory.h"

unique_ptr<HotDrink> make_drink(string type) {
    unique_ptr<HotDrink> drink;
    if (type == "coffee") {
        drink = unique_ptr<Coffee>(new Coffee);
        drink->Prepare(100);
    } else {
        drink = unique_ptr<Tea>(new Tea);
        drink->Prepare(100);
    }
    return drink;
}

int main()
{
    auto tea1 = make_drink("tea");
    auto coffee1 = make_drink("coffee");

    DrinkFactory df;
    auto tea = df.make("tea", 20);
    auto coffee = df.make("coffee", 30);
    return 0;
}
