#include <iostream>
#include <cmath>

using namespace std;

struct Points {
    friend ostream& operator << (ostream& os, const Points& point) {
        return os << "x:" << point.x_ << ", y:" << point.y_;
    }

    Points(float x, float y): x_(x), y_(y) {}

    float x_;
    float y_;
};

struct PointsFactory {
    virtual ~PointsFactory() = default;
    virtual Points createPoints(float a, float b) = 0;
};

struct CartesianPointsFactory : PointsFactory {
    Points createPoints(float a, float b) override {
        return {a, b};
    }
};

struct PolyPointsFactory : PointsFactory {
    Points createPoints(float a, float b) override {
        return {a * cos(b), a * sin(b)};
    }
};


int main()
{
    CartesianPointsFactory cfactory;
    auto p = cfactory.createPoints(10,20);

    PolyPointsFactory pfactory;
    auto p1 = pfactory.createPoints(2, 3.14159f);

    cout << p << endl;
    cout << p1 << endl;
    return 0;
}
