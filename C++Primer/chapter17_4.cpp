#include <iostream>
#include <random>
using namespace std;

void random_engine()
{
    default_random_engine e;
    for (size_t i = 0; i < 10; ++i)
        cout << e() << " ";
}

void distribution()
{
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine e;
    for (size_t i = 0; i < 10; ++i)
        cout << u(e) << " ";
}

int main()
{
    distribution();
}