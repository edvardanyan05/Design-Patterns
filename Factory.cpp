#include <iostream>
#include <cmath>

class Point{
    private:
        Point(float x, float y) : x(x), y(y) {}

        class PointFactory{
            private:
                PointFactory() = default;
            public:
                static Point NewCartesianPoint(float x, float y){
                    return {x, y};
                }

                static Point NewPolarPoint(float r, float theta){
                    return {r * cos(theta), r * sin(theta)};
                }
        };
    public:
        float x, y;

        static PointFactory Factory;
};
