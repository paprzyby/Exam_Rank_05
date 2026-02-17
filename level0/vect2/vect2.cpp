#include "vect2.hpp"

vect2::vect2() : _n1(0), _n2(0)
{
    
}

vect2::vect2(int n1, int n2)
{
    this->_n1 = n1;
    this->_n2 = n2;
}

vect2::vect2(vect2 &other)
{
    this->_n1 = other._n1;
    this->_n2 = other._n2;
}

vect2::~vect2()
{
    
}

vect2 vect2::operator=(vect2 &other)
{
    if (this != &other)
    {
        this->_n1 = other._n1;
        this->_n2 = other._n2;
    }
    return (*this);
}

int vect2::operator[](int i) const
{
    if (i == 0)
        return (this->_n1);
    else if (i == 1)
        return (this->_n2);
    return (0);
}

int vect2::operator[](int i)
{
    if (i == 0)
        return (this->_n1);
    else if (i == 1)
        return (this->_n2);
    return (0);
}

vect2 &vect2::operator++(int)
{
    this->_n1++;
    this->_n2++;
    return (*this);
}

vect2 vect2::operator++()
{
    vect2 tmp = *this;
    this->_n1++;
    this->_n2++;
    return (tmp);
}

vect2 &vect2::operator--(int)
{
    this->_n1--;
    this->_n2--;
    return (*this);
}

vect2 vect2::operator--()
{
    vect2 tmp = *this;
    this->_n1--;
    this->_n2--;
    return (tmp);
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
    std::cout << "{" << v[0] << ", " << v[1] << "}";
    return (os);
}
