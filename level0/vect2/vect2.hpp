#pragma once

# include <iostream>
# include <sstream>
# include <string>

class vect2
{
    public:
        vect2();
        vect2(int num1, int num2);
        vect2(const vect2 &other);
        vect2 &operator=(const vect2 &other);
        ~vect2();

        int getNum(int i) const;

        int     operator[](int i) const;
        vect2   operator++(int);
        vect2   &operator++();
        vect2   operator--(int);
        vect2   &operator--();
        vect2   &operator+=(const vect2 &other);
        vect2   &operator-=(const vect2 &other);
        vect2   &operator*=(int num);
        vect2   operator+(const vect2 &other) const;
        vect2   operator*(int num) const;

    private:
        int num1;
        int num2;
};

std::ostream   &operator<<(std::ostream &os, const vect2 &other);
vect2           operator*(const vect2 &other, int num);
