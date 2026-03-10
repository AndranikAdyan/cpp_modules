#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <class T>
void    swap(T& a, T& b) {
    T tmp;
    
    tmp = a;
    a = b;
    b = tmp;
};

template <class T>
const T& min(T& a, T& b) {
    if (a < b)
        return a;
    return b;
}

template <class T>
const T& max (T& a, T& b) {
    if (a > b)
        return a;
    return b;
}

#endif