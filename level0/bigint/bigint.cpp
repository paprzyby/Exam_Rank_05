#include "bigint.hpp"

bigint::bigint() : num(0)
{

}

bigint::bigint(const unsigned int i) : num(i)
{

}

bigint::bigint(const bigint &other) : num(other.num)
{

}

bigint::~bigint()
{

}
