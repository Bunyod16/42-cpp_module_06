#include <iostream>

int    displayOutput(std::string char_val, std::string int_val, std::string float_val, std::string double_val)
{
    std::cout << "char: " << char_val << std::endl;
    std::cout << "int: " << int_val << std::endl;
    std::cout << "float: " << float_val << std::endl;
    std::cout << "double: " << double_val << std::endl;
    return 1;
}

std::string identifyType(std::string str)
{
    int i;
    int dot_count;
    double num;

    i = -1;
    dot_count = 0;
    while (++i < (int)str.length() && dot_count <= 1)
    {
        if (std::isdigit(str[i]) == 0) {
            if (str[i] == '.')
                dot_count++;
            else if (i + 1 == (int)str.length() && dot_count == 1 && str[i] == 'f')
                return "float";
            else
                return "char";
        }
    }
    num = std::stod(str);
    if ((num >= INT_MIN && num <= INT_MAX) && dot_count == 0)
        return "int";
    return "double";
}

int     handle_nan_inf(std::string str)
{
    if (str == "-inff")
        return (displayOutput(str, "Non displayable", "-inff", "-inf"));
    if (str == "+inff")
        return (displayOutput(str, "Non displayable", "+inff", "+inf"));
    if (str == "-inf")
        return (displayOutput(str, "Non displayable", "-inff", "-inf"));
    if (str == "+inf")
        return (displayOutput(str, "Non displayable", "+inff", "+inf"));
    if (str == "nanf")
        return (displayOutput(str, "Non displayable", "nanf", "nan"));
    if (str == "nan")
        return (displayOutput(str, "Non displayable", "nanf", "nan"));
    return 0;
}

void    handle_char(std::string str)
{
    if (str.length() == 1 && str[0] >= 32 && str[0] <= 127) {
        std::cout << "char: " << "'" + str + "'" << std::endl;
        std::cout << "int: " << (int)str[0] << std::endl;
        std::cout << "float: " << (float)str[0] << ".0f" << std::endl;
        std::cout << "double: " << (double)str[0] << ".0" << std::endl;
    }
    else
        displayOutput(str, "impossible", "impossible" , "impossible");
}

void    handle_int(int num)
{
    if (num >= 32 && num <= 127)
        std::cout << "char: " << "'" << (char)num << "'" << std::endl;
    else
        std::cout << "char: " <<  "Non displayable" << std::endl;
    
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << (float)num  << ".0f" << std::endl;
    std::cout << "double: " << (double)num << ".0" << std::endl;
}

void    handle_float(float num)
{
    if (num >= 32 && num <= 127 && num - int(num) == 0)
        std::cout << "char: " << "'" << (char)num << "'" << std::endl;
    else
        std::cout << "char: " <<  "Non displayable" << std::endl;

    std::cout << "int: " << int(num) << std::endl;
    if (num - int(num) == 0) {
        std::cout << "float: " << (float)num << ".0f" << std::endl;
        std::cout << "double: " << (double)num << ".0" << std::endl;
    }
    else {
        std::cout << "float: " << (float)num << "f" << std::endl;
        std::cout << "double: " << (double)num << std::endl;
    }
}

void    handle_double(double num)
{

    if (num >= 32 && num <= 127 && num - int(num) == 0)
        std::cout << "char: " << "'" << (char)num << "'" << std::endl;
    else
        std::cout << "char: " <<  "Non displayable" << std::endl;

    std::cout << "int: " << int(num) << std::endl;
    if (num - int(num) == 0) {
        std::cout << "float: " << (float)num << ".0f" << std::endl;
        std::cout << "double: " << (double)num << ".0" << std::endl;
    }
    else {
        std::cout << "float: " << (float)num << "f" << std::endl;
        std::cout << "double: " << (double)num << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::string type;

    if (argc != 2)
        return 0;
    type = std::string(argv[1]);
    if (handle_nan_inf(argv[1]) == 1)
        return 1;
    else
        type = identifyType(argv[1]);

    if (type == "char")
        handle_char(argv[1]);
    if (type == "int")
        handle_int(std::stoi(argv[1]));
    if (type == "float")
        handle_float(std::stof(argv[1]));
    if (type == "double")
        handle_double(std::stod(argv[1]));
    return 1;
}
