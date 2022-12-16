#include <iostream>
#include <stdint.h>

struct Data_t 
{
    std::string val;
    float       small_val;
};

uintptr_t serialize(Data_t* ptr)
{
    return ((uintptr_t)(void *)ptr);
}

Data_t* deserialize(uintptr_t raw)
{
    return ((Data_t *) raw);
}

// int main(void)
// {
//     Data_t  dat;
//     uintptr_t srl;

//     dat.val = "something";
//     dat.small_val = 15.5555;
//     std::cout << "start" << std::endl;
//     srl = serialize(&dat);
//     std::cout << srl << std::endl;
//     dat = *(deserialize(srl));
//     std::cout << dat.val << std::endl;
//     std::cout << dat.small_val << std::endl;
// }