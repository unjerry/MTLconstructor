#ifndef NUMBER_THEORY_ALGORITHM_H
#define NUMBER_THEORY_ALGORITHM_H

/*
G is a group
a is in G
b is a realization of Z(integerring) must have == % /
G_1 is  the identity in G
multiplication is the operator* in G
*/
auto fast_power = [](auto a, auto b, auto _1, auto multiplication)
{
    auto ans = _1;
    auto res = a;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = multiplication(ans, res);
        }
        res = multiplication(res, res);
        b = b / 2;
    }
    return ans;
};

/*
E is euclidean ring
a,b,x,y in E
_0 is the zero in E
_1 is the one in E
*/
auto extended_euclidean = [](auto a, auto b, auto &x, auto &y, auto _0, auto _1)
{
    if (b == _0)
    {
        x = _1;
        y = _0;
        return a;
    }
    auto d = extended_euclidean(b, a % b, y, x, _0, _1);
    y = y - ((a / b) * x);
    return d;
};

#endif
