#include <iostream>
#include <string>

class Color {
public:
    virtual std::string getColor() const = 0;
    virtual ~Color() = default;
};

class Red : public Color {
public:
    std::string getColor() const override {
        return "Red";
    }
};

class Blue : public Color {
public:
    std::string getColor() const override {
        return "Blue";
    }
};

class Shape {
protected:
    Color* color;
public:
    Shape(Color* c) : color(c) {}

    virtual void draw() const = 0;
    virtual void resize(double factor) = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    explicit Circle(Color* c) : Shape(c) {}

    void draw() const override {
        std::cout << "Drawing a Circle in " << color->getColor() << "\n";
    }
    void resize(double factor) override {
        std::cout << "Resizing Circle by factor: " << factor << "\n";
    }
};

class Square : public Shape {
public:
    explicit Square(Color* c) : Shape(c) {}

    void draw() const override {
        std::cout << "Drawing a Square in " << color->getColor() << "\n";
    }
    void resize(double factor) override {
        std::cout << "Resizing Square by factor: " << factor << "\n";
    }
};

int main() {
    Red red;
    Blue blue;

    Circle redCircle(&red);
    Square blueSquare(&blue);

    std::cout << "Red Circle:\n";
    redCircle.draw();
    redCircle.resize(1.5);

    std::cout << "\nBlue Square:\n";
    blueSquare.draw();
    blueSquare.resize(2.0);

    return 0;
}
