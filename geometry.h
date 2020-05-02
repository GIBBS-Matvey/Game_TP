#ifndef GEOMETRY_H
#define GEOMETRY_H

///..........geometryClasses...........///


class Point {
private:
    int64_t x;
    int64_t y;
public:
    Point(const int64_t &x, const int64_t &y) : x(x), y(y) {}
    Point(const Point &point) = default;
    Point& operator=(const Point &point) = default;
    friend class Vector;
};

class Vector {
private:
    Point p1;
    Point p2;
public:
    Vector(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}
    int getLength() const {
        return pow(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2), 0.5);
    }
};

#endif//GEOMETRY_H
