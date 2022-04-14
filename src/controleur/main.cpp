#include <iostream>


int main(int argc, char const *argv[])
{
    auto t { 10 };
    int i = 10;
    std::cout << sizeof(t) << std::endl << sizeof(i);

    return 0;
}
