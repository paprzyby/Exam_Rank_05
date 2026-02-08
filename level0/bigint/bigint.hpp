#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>

class bigint
{
    public:
        bigint();
        bigint(const unsigned int i);
        bigint(const bigint &other);
        ~bigint();

        bigint operator+(const bigint &other) const;
        bigint &operator+=(const bigint &other);
        bigint &operator++();
        bigint operator++(int);
        bigint operator<<(const unsigned int i) const;
        bigint &operator<<=(const unsigned int i);
        bigint &operator>>=(const bigint &other);

        bool operator<(const bigint &other) const;
        bool operator<=(const bigint &other) const;
        bool operator>(const bigint &other) const;
        bool operator>=(const bigint &other) const;
        bool operator==(const bigint &other) const;
        bool operator!=(const bigint &other) const;
    
    public:
        std::string str;
};

std::ostream &operator<<(std::ostream &output, const bigint &obj);

#endif
