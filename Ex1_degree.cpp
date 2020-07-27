#include <iostream>

int Degree(int num)
{
    int count = 0;
    {
        while (num)
        {
            if (num != 1)
            {
                ++count;
            }
            num >>= 1;
        }
        return count;
    }
}

int main()
{
    int num = 20;
    std::cout << Degree(num) << std::endl;
}
