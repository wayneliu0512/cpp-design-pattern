#include <iostream>
#include <boost/signals2.hpp>

using namespace std;

template <typename T>
class Observable
{
public:
    boost::signals2::signal<void (T&, const string&)> Notify;
};

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

int main( int argc, char** argv )
{
    Person man;

    auto conn = man.Notify.connect([](Person& p, const string& field_name)
                                   {
                                       cout << "field_name: " << field_name
                                            << "." << p.get_age() << endl;
                                   });
    man.set_age(20);
    man.set_age(30);
    conn.disconnect();

  return 0;
}
