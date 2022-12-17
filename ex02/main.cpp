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
    if (num == 0) {
        std::cout << "Generated type: A" << std::endl;
        return (new A());
    }
    else if (num == 1){
        std::cout << "Generated type: B" << std::endl;
        return (new B());
    }
    else {
        std::cout << "Generated type: C" << std::endl;
        return (new C());
    }
}

void identify(Base* p)
{
    Base *test;

    std::cout << "Running identify(Base* p)" << std::endl;
    test = dynamic_cast<A *>(p);
    if (test != NULL)
        std::cout << "Type: " << "A" << std::endl;
    test = dynamic_cast<B *>(p);
    if (test != NULL)
        std::cout << "Type: " << "B" << std::endl;
    test = dynamic_cast<C *>(p);
    if (test != NULL)
        std::cout << "Type: " << "C" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Running identify(Base& p)" << std::endl;
    std::cout << "Type: " << p.type << std::endl;
}

int main(void)
{
    Base *ptr;

    ptr = generate();
    identify(*ptr);
    identify(ptr);
}