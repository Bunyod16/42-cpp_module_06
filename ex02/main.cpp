#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Base.hpp"


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
    Base *test;
    int i;

    std::cout << "Running identify(Base& p)" << std::endl;
    i = 0;
    try {
        test = &(dynamic_cast<A &>(p));
        i = 1;
    }
    catch (std::exception &e) {
    }
    try {
        test = &(dynamic_cast<B &>(p));
        i = 2;
    }
    catch (std::exception &e) {
    }
    try {
        test = &(dynamic_cast<C &>(p));
        i = 3;
    }
    catch (std::exception &e) {
    }
    switch (i) {
        case 1:
            std::cout << "Type: " << "A" << std::endl;
            break;
        case 2:
            std::cout << "Type: " << "B" << std::endl;
            break;
        case 3:
            std::cout << "Type: " << "C" << std::endl;
            break;
    }
}

int main(void)
{
    Base *ptr;

    ptr = generate();
    identify(*ptr);
    identify(ptr);
}