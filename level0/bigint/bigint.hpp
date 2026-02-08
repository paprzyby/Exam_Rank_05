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

        bigint operator +(const bigint &other) const;
        bigint operator +=(const bigint &other);
    
    public:
        std::string str;
};

std::ostream &operator<<(std::ostream &output, const bigint &obj);

#endif
