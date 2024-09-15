#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPointValue = 0;
}

Fixed::Fixed(const int value)
{
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

int Fixed::getRawBits(void) const
{
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->fixedPointValue / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->fixedPointValue >> this->fractionalBits;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    return (fixed1 < fixed2) ? fixed1 : fixed2; 
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1 < fixed2) ? fixed1 : fixed2; 
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    return (fixed1 > fixed2) ? fixed1 : fixed2; 
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1 > fixed2) ? fixed1 : fixed2; 
}



std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    this->fixedPointValue = fixed.getRawBits();
    return *this;
}

//comparison

bool Fixed::operator<(const Fixed &fixed) const
{
    return this->fixedPointValue < fixed.fixedPointValue;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return this->fixedPointValue > fixed.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return this->fixedPointValue <= fixed.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return this->fixedPointValue >= fixed.fixedPointValue;
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return this->fixedPointValue == fixed.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return this->fixedPointValue != fixed.fixedPointValue;
}


// arithmetic

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed result;
    result.setRawBits((this->fixedPointValue * other.getRawBits()) >> this->fractionalBits);
    return result;
}


Fixed Fixed::operator/(const Fixed &fixed)
{
    return this->fixedPointValue / fixed.fixedPointValue;
}

Fixed Fixed::operator-(const Fixed &fixed)
{
    return this->fixedPointValue - fixed.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &fixed)
{
    return this->fixedPointValue + fixed.fixedPointValue;
}

// increment/decrement

Fixed& Fixed::operator++() {
    ++this->fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --this->fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

