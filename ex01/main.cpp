#include <iostream>
#include <stdint.h>

struct Data_t 
{
    std::string val;
    float       small_val;
};

uintptr_t serialize(Data_t* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data_t* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data_t *>(raw));
}

int main(void)
{
    Data_t  dat;
    Data_t  dat_2;
    uintptr_t srl;

    dat.val = "something";
    dat.small_val = 15.5455555;
    srl = serialize(&dat);
    std::cout << "Serialized value: " << srl << std::endl;
    dat_2 = *(deserialize(srl));
    dat.val = "ERROR";
    dat.small_val = 99.9;
    std::cout << dat_2.val << std::endl;
    std::cout << dat_2.small_val << std::endl;
}