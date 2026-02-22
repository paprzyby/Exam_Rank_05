#pragma once

# include <iostream>
# include <sstream>
# include <string>

class   bigint
{
    public:
        bigint();
        bigint(unsigned int num);
        bigint &operator=(const bigint &other);
        bigint(const bigint &other);
        ~bigint();

        std::string getStr() const;

        bigint  operator+(const bigint &other) const;
        bigint  &operator+=(const bigint &other);
        bigint  operator++();
        bigint  operator++(int);
        bigint  operator<<(unsigned int num) const;
        bigint  operator<<=(unsigned int num);
        bigint  operator>>(unsigned int num) const;
        bigint  operator>>=(const bigint &other);

        bool    operator<(const bigint &other) const;
        bool    operator<=(const bigint &other) const;
        bool    operator==(const bigint &other) const;
        bool    operator>(const bigint &other) const;
        bool    operator>=(const bigint &other) const;
        bool    operator!=(const bigint &other) const;

    private:
        std::string str;
};

std::ostream    &operator<<(std::ostream &output, const bigint &other);
std::string     addition(const bigint &a, const bigint &b);
std::string     reverse(const std::string &str);
unsigned int    stringTo_UnsignedInt(std::string str);
