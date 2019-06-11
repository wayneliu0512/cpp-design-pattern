#include <iostream>
#include <cmath>

using namespace std;

//example 1
//struct Point {
//private:
//    Point(float x, float y): x_(x), y_(y) {}

//    float x_;
//    float y_;

//public:
//    friend ostream& operator<<(ostream& os, const Point& point) {
//        return os << "x:" << point.x_ << ", y:" << point.y_;
//    }

//    struct PointFactory {
//        static Point NewCartesian(float x, float y) {
//            return {x, y};
//        }

//        static Point NewPoly(float r, float theta) {
//            return {r * cos(theta), r * sin(theta)};
//        }
//    };
//};

//example 2
//struct Point {
//private:
//    Point(float x, float y): x_(x), y_(y) {}

//    float x_;
//    float y_;

//    struct PointFactory {
//        Point NewCartesian(float x, float y) {
//            return {x, y};
//        }

//        Point NewPoly(float r, float theta) {
//            return {r * cos(theta), r * sin(theta)};
//        }
//    };

//public:
//    friend ostream& operator<<(ostream& os, const Point& point) {
//        return os << "x:" << point.x_ << ", y:" << point.y_;
//    }

//    static PointFactory factory;
//};

//Point::PointFactory Point::factory;

int main()
{
//    auto p = Point::PointFactory::NewCartesian(10, 20);
//    auto p1 = Point::PointFactory::NewPoly(2, 3.14159f);

//    auto p = Point::factory.NewCartesian(10, 20);
//    auto p1 = Point::factory.NewPoly(2, 3.14159f);

//    cout << p << endl;
//    cout << p1 << endl;
    return 0;
}
