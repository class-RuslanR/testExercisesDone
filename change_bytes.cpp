#include "iostream"

void ChangeBytes(uint16_t& num)
{
    const int byte = 8;
    num = (num >> byte) | ((num & 0xff) << byte);
}

int main()
{
    uint16_t num = 10000;
    ChangeBytes(num);
    std::cout << num << std::endl;
}