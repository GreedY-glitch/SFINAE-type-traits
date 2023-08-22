#include "SFINAE.hpp"
#include <iostream>



const int foo(int, int) {}

auto main(int argc, char** argv) -> int
{
    f(1, 2);

    const int&& x = foo(1, 2);
    decltype(auto) y = foo(1, 2);

    std::cout << y << std::endl;
    return EXIT_SUCCESS;
}