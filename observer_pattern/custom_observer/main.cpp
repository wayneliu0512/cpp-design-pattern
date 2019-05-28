#include <iostream>
#include <observable.h>
#include <observer.h>

using namespace std;

class Person : public Observable<Person>
{
    int age{0};
public:
    Person(){}
    Person(int age) : age(age) {}

    int get_age() const
    {
        return age;
    }

    void set_age(int age)
    {
        if (this->age == age)
            return;
        this->age = age;
        Notify(*this, "age");
    }
};

class ConsolePersonObserver : public Observer<Person>
{
public:
    void FieldChanged(Person& source, const std::string& field_name) override {
        cout << "FieldChanged: " << field_name << "." << source.get_age() << endl;
    }
};

int main()
{
    Person man;
    ConsolePersonObserver cpo1;
    ConsolePersonObserver cpo2;
    man.Subscribe(cpo1);
    man.Subscribe(cpo2);
    man.set_age(10);
    man.set_age(12);
    man.UnSubscribe(cpo1);
    man.set_age(13);
    return 0;
}
