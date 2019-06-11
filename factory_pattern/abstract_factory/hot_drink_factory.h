#ifndef HOT_DRINK_FACTORY_H
#define HOT_DRINK_FACTORY_H
#include <memory>
#include "hot_drink.h"

class HotDrinkFactory
{
public:
    virtual ~HotDrinkFactory() = default;
    virtual unique_ptr<HotDrink> make() = 0;
};

class TeaFactory : public HotDrinkFactory {
public:
    unique_ptr<HotDrink> make() {
        return unique_ptr<HotDrink>(new Tea);
    }
};

class CoffeeFactory : public HotDrinkFactory {
public:
    unique_ptr<HotDrink> make() {
        return unique_ptr<HotDrink>(new Coffee);
    }
};

#endif // HOT_DRINK_FACTORY_H
