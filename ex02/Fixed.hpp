#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>


class Fixed
{
private:
    int fixedPointValue;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    Fixed(const Fixed &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;  
    Fixed &operator=(const Fixed &fixed);

    bool operator<(const Fixed &fixed) const;
    bool operator>(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;

    Fixed operator*(const Fixed &fixed);
    Fixed operator/(const Fixed &fixed);
    Fixed operator-(const Fixed &fixed);
    Fixed operator+(const Fixed &fixed);

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    
    static  Fixed& min(Fixed &fixed1, Fixed &fixed2);
    static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
    static  Fixed& max(Fixed &fixed1, Fixed &fixed2);
    static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);





#endif