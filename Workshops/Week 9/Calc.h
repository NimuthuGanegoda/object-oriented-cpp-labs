#ifndef CALC_H
#define CALC_H

template <class T>
class Calc {
public:
    T multiply(T x, T y) {
        return x * y;
    }

    T add(T x, T y) {
        return x + y;
    }
};

#endif
