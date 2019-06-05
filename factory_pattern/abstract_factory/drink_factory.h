#ifndef DRINK_FACTORY_H
#define DRINK_FACTORY_H
#include "hot_drink_factory.h"
#include <map>

class DrinkFactory
{
public:
    DrinkFactory() {
        drink_factorys_["coffee"] = unique_ptr<CoffeeFactory>(new CoffeeFactory);
        drink_factorys_["tea"] = unique_ptr<TeaFactory>(new TeaFactory);
    }

    unique_ptr<HotDrink> make(string str, int volume) {
        auto drink = drink_factorys_[str]->make();
        drink->Prepare(volume);
        return drink;
    }

private:
    map<string, unique_ptr<HotDrinkFactory>> drink_factorys_;
};

#endif // DRINK_FACTORY_H
