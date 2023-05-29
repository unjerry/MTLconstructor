#ifndef NUMBER_THEORY_ALGORITHM_H
#define NUMBER_THEORY_ALGORITHM_H

auto fast_power = [](auto a, size_t b, auto one, auto multiplication)
{
    auto ans = one;
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

auto extended_euclidean = [](auto a, auto b, auto &x, auto &y, auto zero, auto one)
{
    if (b == zero)
    {
        x = one;
        y = zero;
        return a;
    }
    auto d = extended_euclidean(b, a % b, y, x, zero, one);
    y = y - ((a / b) * x);
    return d;
};

#endif
