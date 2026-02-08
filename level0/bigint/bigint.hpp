#ifndef BIGINT_HPP
# define BIGINT_HPP

class bigint
{
    public:
        bigint();
        bigint(const unsigned int i);
        bigint(const bigint &other);
        ~bigint();
    
    public:
        const unsigned int num;
};

#endif
