#include <iostream>
#include <cmath>

using namespace std;

struct Point {

    static Point NewCartesian(float x, float y) {
        return {x, y};
    }

    static Point NewPoly(float r, float theta) {
        return {r * cos(theta), r * sin(theta)};
    }

    friend ostream& operator<<(ostream& os, const Point& point) {
        return os << "x:" << point.x_ << ", y:" << point.y_;
    }

private:
    Point(float x, float y): x_(x), y_(y) {}

    float x_;
    float y_;
};

int main()
{
    cout << "Hello World!" << endl;

    auto p = Point::NewCartesian(10, 20);
    auto p1 = Point::NewPoly(5, 3.14159f);

    cout << p << endl;
    cout << p1 << endl;
    return 0;
}
