#include "vect2.hpp"

vect2::vect2() : num1(0), num2(0)   {}

vect2::vect2(int num1, int num2)
{
    this->num1 = num1;
    this->num2 = num2;
}

vect2::vect2(const vect2 &other)
{
    this->num1 = other.num1;
    this->num2 = other.num2;
}

vect2 &vect2::operator=(const vect2 &other)
{
    if (this != &other)
    {
        this->num1 = other.num1;
        this->num2 = other.num2;
    }
    return (*this);
}

vect2::~vect2() {}

int vect2::operator[](int i) const
{
    if (i == 0)
        return (this->num1);
    return (this->num2);
}

vect2   vect2::operator++(int)
{
    vect2   tmp(*this);

    this->num1 = this->num1 + 1;
    this->num2 = this->num2 + 1;
    return (tmp);
}

vect2   &vect2::operator++()
{
    this->num1 = this->num1 + 1;
    this->num2 = this->num2 + 1;
    return (*this);
}

vect2   vect2::operator--(int)
{
    vect2   tmp(*this);

    this->num1 = this->num1 - 1;
    this->num2 = this->num2 - 1;
    return (tmp);
}

vect2   &vect2::operator--()
{
    this->num1 = this->num1 - 1;
    this->num2 = this->num2 - 1;
    return (*this);
}

vect2   &vect2::operator+=(const vect2 &other)
{
    this->num1 = this->num1 + other.num1;
    this->num2 = this->num2 + other.num2;
    return (*this);
}

vect2   &vect2::operator-=(const vect2 &other)
{
    this->num1 = this->num1 - other.num1;
    this->num2 = this->num2 - other.num2;
    return (*this);
}

int vect2::getNum(int i) const
{
    if (i == 0)
        return (this->num1);
    return (this->num2);
}

vect2   &vect2::operator*=(int num)
{
    this->num1 = this->num1 * num;
    this->num2 = this->num2 * num;
    return (*this);
}

vect2   vect2::operator+(const vect2 &other) const
{
    vect2   tmp(*this);

    tmp.num1 = tmp.num1 + other.num1;
    tmp.num2 = tmp.num1 + other.num2;
    return (tmp);
}

vect2   vect2::operator*(int num) const
{
    vect2   tmp(*this);

    tmp.num1 = tmp.num1 * num;
    tmp.num2 = tmp.num1 * num;
    return (tmp);
}

vect2   operator*(const vect2 &other, int num)
{
    vect2 tmp(other);

    tmp *= num;
    return (tmp);
}

std::ostream   &operator<<(std::ostream &os, const vect2 &other)
{
    std::cout << "{" << other[0] << ", " << other[1] << "}";
    return (os);
}

// int main()
// {
//     vect2 v1; // 0, 0
//     vect2 v2(1, 2); // 1, 2
//     const vect2 v3(v2); // 1, 2
//     vect2 v4 = v2; // 1, 2

//     (void)v1;
//     (void)v2;
//     (void)v3;
//     (void)v4;
//     std::cout << "v1: " << v1 << std::endl;
//     std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
//     std::cout << "v2: " << v2 << std::endl;
//     std::cout << "v3: " << v3 << std::endl;
//     std::cout << "v4: " << v4 << std::endl;
//     std::cout << v4++ << std::endl; // 2, 3
//     std::cout << ++v4 << std::endl; // 3, 4
//     std::cout << v4-- << std::endl; // 2, 3
//     std::cout << --v4 << std::endl; // 1, 2
//     v2 += v3; // 2, 4
//     v1 -= v2; // -2, -4
//     // v2 = v3 + v3 * 2; // 3, 6
//     // v2 = 3 * v2; // 9, 18
//     // // v2 += v2 += v3; // 20, 40
//     // // v1 *= 42; // -84, -168
//     // // v1 = v1 - v1 +v1;
//     // std::cout << "v1: " << v1 << std::endl;
//     // std::cout << "v2: " << v2 << std::endl;
//     // std::cout << "-v2: " << -v2 << std::endl;
//     // std::cout << "v1[1]: " << v1[1] << std::endl;
//     // v1[1] = 12;
//     // std::cout << "v1[1]: " << v1[1] << std::endl;
//     // std::cout << "v3[1]: " << v3[1] << std::endl;
//     // std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
//     // std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
//     // std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
//     // std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
// }
