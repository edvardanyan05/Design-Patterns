#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Component
class Course {
public:
    virtual ~Course() = default;
    virtual int get_members() const = 0;
    virtual void print(int indent = 0) const = 0;
};

// Leaf
class SingleCourse : public Course {
    std::string name;
    int members;
public:
    SingleCourse(std::string n, int m) : name(std::move(n)), members(m) {}

    int get_members() const override { return members; }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << " (" << members << ")\n";
    }
};

// Composite
class Department : public Course {
    std::string name;
    std::vector<std::unique_ptr<Course>> courses;
public:
    explicit Department(std::string n) : name(std::move(n)) {}

    void add(std::unique_ptr<Course> course) {
        courses.push_back(std::move(course));
    }

    int get_members() const override {
        int total = 0;
        for (const auto& c : courses) total += c->get_members();
        return total;
    }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << " [" << get_members() << "]\n";
        for (const auto& c : courses) c->print(indent + 2);
    }
};

int main() {
    auto it = std::make_unique<Department>("IT");
    it->add(std::make_unique<SingleCourse>("C++", 20));
    it->add(std::make_unique<SingleCourse>("Algorithms", 15));

    auto math = std::make_unique<Department>("Math");
    math->add(std::make_unique<SingleCourse>("Calculus", 30));

    Department university("University");
    university.add(std::move(it));
    university.add(std::move(math));
    university.add(std::make_unique<SingleCourse>("English", 10));

    university.print();
    std::cout << "Total: " << university.get_members() << '\n';
}
