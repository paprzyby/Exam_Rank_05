#include "bigint.hpp"

bigint::bigint() : str("0")
{

}

bigint::bigint(const unsigned int i) : str(std::to_string(i))
{

}

bigint::bigint(const bigint &other) : str(other.str)
{

}

bigint::~bigint()
{

}

bigint bigint::operator+(const bigint &other) const
{
    bigint result = bigint();

    result.str = std::to_string(std::stoul(this->str) + std::stoul(other.str));
    return (result);
}

bigint bigint::operator+=(const bigint &other)
{
    this->str = std::to_string(std::stoul(this->str) + std::stoul(other.str));
    return (*this);
}

bigint bigint::operator++()
{
    this->str = std::to_string(std::stoul(this->str) + 1);
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint result = bigint(*this);

    this->str = std::to_string(std::stoul(this->str) + 1);
    return (result);
}

bigint bigint::operator<<(const unsigned int i) const
{
    bigint result = bigint();

    result.str = std::to_string(std::stoul(this->str) << i);
    return (result);
}

bigint bigint::operator<<=(const unsigned int i)
{
    this->str = std::to_string(std::stoul(this->str) << i);
    return (*this);
}

bigint bigint::operator>>=(const bigint &other)
{
    this->str = std::to_string(std::stoul(this->str) >> std::stoul(other.str));
    return (*this);
}

bool bigint::operator<(const bigint &other) const
{
    return (std::stoul(this->str) < std::stoul(other.str));
}

bool bigint::operator<=(const bigint &other) const
{
    return (std::stoul(this->str) <= std::stoul(other.str));
}

bool bigint::operator>(const bigint &other) const
{
    return (std::stoul(this->str) > std::stoul(other.str));
}

bool bigint::operator>=(const bigint &other) const
{
    return (std::stoul(this->str) >= std::stoul(other.str));
}

bool bigint::operator==(const bigint &other) const
{
    return (std::stoul(this->str) == std::stoul(other.str));
}

bool bigint::operator!=(const bigint &other) const
{
    return (std::stoul(this->str) != std::stoul(other.str));
}

std::ostream &operator<<(std::ostream &output, const bigint &obj)
{
    output << obj.str;
    return (output);
}
