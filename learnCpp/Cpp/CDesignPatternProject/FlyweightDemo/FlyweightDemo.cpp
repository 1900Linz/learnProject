#include <iostream>
#include <map>
#include <ctime>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};
class Circle : public Shape {
private:
    string color;
    int x;
    int y;
    int radius;
public:
    Circle(string color) : color(color), x(0), y(0), radius(0) {}

    void setX(int newx) {
        x = newx;
    }

    void setY(int newy) {
        y = newy;
    }

    void setRadius(int newradius) {
        radius = newradius;
    }

    void draw() {
        cout << "Circle: Draw() [Color : " << color
            << ", x : " << x << ", y :" << y << ", radius :" << radius
            << endl;
    }
};
class ShapeFactory {
public:
    static map<string, Shape*> circleMap;

    static Shape* getCircle(string color) {
        if (circleMap.count(color) > 0) {
            return circleMap[color];
        }
        auto shape = new Circle(color);
        circleMap[color] = shape;
        cout << "Creating circle of color : " << color << endl;
        return shape;
    }

    static void cleanup() {
        for (auto e : circleMap) {
            delete e.second;
        }
    }
};

// 生成随机数
double random() {
    return (rand() % 10) * 0.1;
}

string colors[] = { "Red", "Green", "Blue", "White", "Black" };
string getRandomColor() {
    return colors[(int)(random() * sizeof(colors) / sizeof(colors[0]))];
}
int getRandomX() {
    return (int)(random() * 100);
}
int getRandomY() {
    return (int)(random() * 100);
}

// 定义circleMap
map<string, Shape*> ShapeFactory::circleMap;

int main() {
    srand(time(0));
    for (int i = 0; i < 20; ++i) {
        Circle circle = *(Circle*)ShapeFactory::getCircle(getRandomColor());
        circle.setX(getRandomX());
        circle.setY(getRandomY());
        circle.setRadius(100);
        circle.draw();
    }
    ShapeFactory::cleanup();
    return 0;
}