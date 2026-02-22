#include "bigint.hpp"

bigint::bigint() : str("0")    {}

bigint::bigint(unsigned int num)
{
    std::stringstream   ss;

    ss << num;
    this->str = ss.str();
}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
    {
        this->str = other.str;
    }
    return (*this);
}

bigint::bigint(const bigint &other)
{
    (*this) = other;
}

bigint::~bigint()    {}

std::string bigint::getStr() const
{
    return (this->str);
}

std::string reverse(const std::string &str)
{
    std::string result;

    for (size_t i = str.length(); i > 0; i--)
    {
        result.push_back(str[i - 1]);
    }
    return (result);
}

std::string addition(const bigint &a, const bigint &b)
{
    std::string reverse_a = reverse(a.getStr());
    std::string reverse_b = reverse(b.getStr());
    std::string result;
    size_t      len_a = reverse_a.length();
    size_t      len_b = reverse_b.length();

    if (len_a > len_b)
    {
        int diff = len_a - len_b;
        
        while (diff > 0)
        {
            reverse_b.push_back('0');
            diff--;
        }
    }
    else if (len_a < len_b)
    {
        int diff = len_b - len_a; 
        
        while (diff > 0)
        {
            reverse_a.push_back('0');
            diff--;
        }
    }

    int carry = 0;
    int digit_1;
    int digit_2;
    size_t len = reverse_a.length();
    size_t i = 0;
    int sum = 0;

    while (i < len)
    {
        digit_1 = reverse_a[i] - '0';
        digit_2 = reverse_b[i] - '0';
        sum = digit_1 + digit_2 + carry;
        if (sum > 9)
        {
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
        else
        {
            result.push_back(sum + '0');
        }
        i++;
    }
    if (carry != 0)
    {
        result.push_back(carry + '0');
    }
    return (reverse(result));
}

bigint  bigint::operator+(const bigint &other) const
{
    bigint      tmp;
    std::string result;

    result = addition(*this, other);
    tmp.str = result;
    return (tmp);
}

bigint  &bigint::operator+=(const bigint &other)
{
    (*this) = (*this) + other;
    return (*this);
}

bigint  bigint::operator++()
{
    bigint  tmp(1);

    (*this) = (*this) + tmp;
    return (*this);
}

bigint  bigint::operator++(int)
{
    bigint  tmp(*this);

    (*this) = (*this) + bigint(1);
    return (tmp);
}

bigint  bigint::operator<<(unsigned int num) const
{
    bigint  tmp = *this;

    tmp.str.insert(tmp.str.end(), num, '0');
    return (tmp);
}

bigint  bigint::operator<<=(unsigned int num)
{
    (*this) = (*this) << num;
    return (*this);
}

bigint  bigint::operator>>(unsigned int num) const
{
    bigint  tmp = *this;
    size_t  len = tmp.str.length();

    if (num >= len)
    {
        tmp.str = '0';
    }
    else
    {
        tmp.str.erase(tmp.str.length() - num, num);
    }
    return (tmp);
}

unsigned int    stringTo_UnsignedInt(std::string str)
{
    std::stringstream   ss(str);
    unsigned int        result;

    ss >> result;
    return (result);
}

bigint  bigint::operator>>=(const bigint &other)
{
    (*this) = (*this) >> stringTo_UnsignedInt(other.str);
    return (*this);
}

bool    bigint::operator<(const bigint &other) const
{
    std::string str_a = this->str;
    std::string str_b = other.getStr();
    size_t      len_a = str_a.length();
    size_t      len_b = str_b.length();

    if (len_a != len_b)
    {
        return (len_a < len_b);
    }
    else
    {
        return (str_a < str_b);
    }
}

bool    bigint::operator==(const bigint &other) const
{
    if (this->getStr() == other.getStr())
        return(true);
    return (false);
}

bool    bigint::operator<=(const bigint &other) const
{
    return ((*this < other) || (*this == other));
}

bool    bigint::operator>(const bigint &other) const
{
    return (!(*this < other));
}

bool    bigint::operator>=(const bigint &other) const
{
    return ((*this > other) || (*this == other));
}

bool    bigint::operator!=(const bigint &other) const
{
    return (!(*this == other));
}

std::ostream    &operator<<(std::ostream &output, const bigint &other)
{
    return (output << other.getStr());
}

// int main()
// {
//     const bigint a(42);
//     bigint b(21), c, d(1337), e(d);

//     (void)a;
//     (void)b;
//     (void)c;
//     (void)d;
//     (void)e;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "c = " << c << std::endl;
//     std::cout << "d = " << d << std::endl;
//     std::cout << "e = " << e << std::endl;

//     std::cout << "a + b = " << a + b << std::endl;
//     std::cout << "(c += a) = " << (c += a) << std::endl;

//     std::cout << "b = " << b << std::endl;
//     std::cout << "++b = " << ++b << std::endl;
//     std::cout << "b++ = " << b++ << std::endl;

//     std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
//     std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
//     std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

//     std::cout << "a = " << a << std::endl;
//     std::cout << "d = " << d << std::endl;

//     std::cout << "(d < a) = " << (d < a) << std::endl;
//     std::cout << "(d <= a) = " << (d <= a) << std::endl;
//     std::cout << "(d > a) = " << (d > a) << std::endl;
//     std::cout << "(d >= a) = " << (d >= a) << std::endl;
//     std::cout << "(d == a) = " << (d == a) << std::endl;
//     std::cout << "(d != a) = " << (d != a) << std::endl;
// }
