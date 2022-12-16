#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Base {
    public:
        Base(std::string type) : type(type) {}
        virtual ~Base() {}
        std::string type;
};

class A: public Base {
    public:
        A() : Base("A") {}
        ~A() {}
};

class B: public Base {
    public:
        B() : Base("B") {}
        ~B() {}
};

class C: public Base {
    public:
        C() : Base("C") {}
        ~C() {}
};

Base *generate(void) {
    int num;
 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    num = dis(gen) % 3;
    if (num == 0)
        return (new A());
    else if (num == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    Base *test;

    test = dynamic_cast<A *>(p);
    std::cout << "Type: " << p->type << std::endl;
}

void identify(Base& p)
{
    std::cout << "Type: " << p.type << std::endl;
}

int main(void)
{
    Base *ptr;

    ptr = generate();
    identify(*ptr);
}