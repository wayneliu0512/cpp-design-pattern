#ifndef HOT_DRINK_H
#define HOT_DRINK_H
#include <iostream>

using namespace std;

class HotDrink
{
public:
    virtual ~HotDrink() = default;
    virtual void Prepare(int volume) const = 0;
};

class Tea : public HotDrink {
public:
    void Prepare(int volume) const override {
        cout << "Tea: " << volume << "ml" << endl;
    }
};

class Coffee : public HotDrink {
public:
    void Prepare(int volume) const override {
        cout << "Coffee: " << volume << "ml" << endl;
    }
};

#endif // HOT_DRINK_H
