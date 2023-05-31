#ifndef HARMONIC_TRANSFORM_H
#define HARMONIC_TRANSFORM_H

#include "number_theory_algorithm.h"
#include <stddef.h>
#include <iostream>

/*
R is a ring with "addition" "multiplication" "cyclic_root(N) gengerate prime unit root zeta which zeta^N=one in R"
LIST is a list of R with "LEN return the length of LIST" "RELEN resize the length of LIST"
Z is a realization of integer ring with + - * / == = < ++ == = /(Z,size_t) *(Z,size_t) < ++

P is a LIST
N _0 _1 are int Z
*/
auto harmonic_transform_of_power_two = [](const auto &P, auto _0, auto _1, const auto &LEN, const auto &RELEN, const auto &cyclic_root, const auto &addition, const auto &multiplication)
{
    auto N = LEN(P);
    if (N == _1)
    {
        return P;
    }
    auto HALF = N / 2;
    auto zeta = cyclic_root(N);
    auto Pe = P, Po = P;
    RELEN(Pe, HALF);
    RELEN(Po, HALF);
    for (auto i = _0; i < HALF; i = i + _1)
    {
        Pe[i] = P[i * 2 + _0];
        Po[i] = P[i * 2 + _1];
    }
    auto ye = harmonic_transform_of_power_two(Pe, _0, _1, LEN, RELEN, cyclic_root, addition, multiplication);
    auto yo = harmonic_transform_of_power_two(Po, _0, _1, LEN, RELEN, cyclic_root, addition, multiplication);
    auto y = P;
    RELEN(y, N);
    for (auto i = _0; i < HALF; i = i + _1)
    {
        y[i + _0 * N / 2] = addition(ye[i], multiplication(fast_power(zeta, i + _0 * N / 2, cyclic_root(1), multiplication), yo[i]));
        y[i + _1 * N / 2] = addition(ye[i], multiplication(fast_power(zeta, i + _1 * N / 2, cyclic_root(1), multiplication), yo[i]));
    }
    return y;
};

#endif
