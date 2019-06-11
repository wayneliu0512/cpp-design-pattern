#include <iostream>
#include <cmath>

using namespace std;
//example 1
//struct Point {
//    friend ostream& operator<<(ostream& os, const Point& point) {
//        return os << "x:" << point.x_ << ", y:" << point.y_;
//    }

//private:
//    Point(float x, float y): x_(x), y_(y) {}

//    float x_;
//    float y_;
//};

//struct PointFactory {
//    static Point NewCartesian(float x, float y) {
//        return {x, y};
//    }

//    static Point NewPoly(float r, float theta) {
//        return {r * cos(theta), r * sin(theta)};
//    }
//};

//example 2
//struct Point {
//    friend struct PointFactory; // OCP

//    friend ostream& operator<<(ostream& os, const Point& point) {
//        return os << "x:" << point.x_ << ", y:" << point.y_;
//    }

//private:
//    Point(float x, float y): x_(x), y_(y) {}

//    float x_;
//    float y_;
//};

//struct PointFactory {
//    static Point NewCartesian(float x, float y) {
//        return {x, y};
//    }

//    static Point NewPoly(float r, float theta) {
//        return {r * cos(theta), r * sin(theta)};
//    }
//};

//example 3
//struct Point {
//    friend ostream& operator<<(ostream& os, const Point& point) {
//        return os << "x:" << point.x_ << ", y:" << point.y_;
//    }

//    Point(float x, float y): x_(x), y_(y) {}

//    float x_;
//    float y_;
//};

//struct PointFactory {
//    static Point NewCartesian(float x, float y) {
//        return {x, y};
//    }

//    static Point NewPoly(float r, float theta) {
//        return {r * cos(theta), r * sin(theta)};
//    }
//};

int main()
{
//    auto p = PointFactory::NewCartesian(10, 20);
//    Point p1 {10, 20};

//    cout << p << endl;
//    cout << p1 << endl;
    return 0;
}
