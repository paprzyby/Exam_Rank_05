#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class   vect2
{
    public:
        vect2();
        vect2(int n1, int n2);
        vect2(vect2 &other);
        ~vect2();

        vect2 operator=(vect2 &other);
        int operator[](int i) const;
        int operator[](int i);
        vect2 &operator++(int);
        vect2 operator++();
        vect2 &operator--(int);
        vect2 operator--();

    private:
        int _n1;
        int _n2;
};

std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif