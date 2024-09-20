#include "Fixed.hpp"


int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;


    /*this is extra tests*/

    Fixed c(50);
    Fixed d(20);

    if (d < c)
        std::cout << "this is < operation" << std::endl;

    if (c > d)
        std::cout << "this is > operation" << std::endl;

    if (d != c)
        std::cout << "this is != operation" << std::endl;

    d = Fixed(50);
    if (d == c)
        std::cout << "this is == operation" << std::endl;


    return 0;
}