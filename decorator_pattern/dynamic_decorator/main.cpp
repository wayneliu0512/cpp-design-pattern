#include <iostream>
#include <sstream>

using namespace std;

struct Shape {
    virtual string str() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    string str() const override{
        ostringstream oss;
        oss << "it's circle";
        return oss.str();
    }
};

struct Square : Shape {
    string str() const override{
        ostringstream oss;
        oss << "it's Square";
        return oss.str();
    }
};

struct ColoredShape : Shape {
    Shape& shape_;

    ColoredShape(Shape& shape): shape_(shape) {}

    string str() const override{
        ostringstream oss;
        oss << shape_.str() << " add color";
        return oss.str();
    }
};

struct TransparentShape : Shape {
    Shape& shape_;

    TransparentShape(Shape& shape): shape_(shape) {}

    string str() const override{
        ostringstream oss;
        oss << shape_.str() << " add transparent";
        return oss.str();
    }
};

int main()
{
    Circle c;
    Square s;

    cout << c.str() << endl;
    cout << s.str() << endl;

    ColoredShape cs(s);

    cout << cs.str() << endl;

    TransparentShape ts(cs);

    cout << ts.str() << endl;

    return 0;
}
