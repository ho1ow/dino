#include "Random.h"
int Random::random()
{
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    static std::uniform_int_distribution<int> rand(0, INT32_MAX);

    return rand(gen);
}

int Random::random(int begin, int end)
{
    static std::random_device rd;
    static std::mt19937_64 gen(rd());

    std::uniform_int_distribution<int> cusRand(begin, end);
    return cusRand(gen);
}