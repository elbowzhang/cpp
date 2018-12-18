#include <iostream>
using namespace std;

uint32_t Gcd(uint32_t M, uint32_t N)
{
    uint32_t rem;

    while (N > 0)
    {
        rem = M % N;
        M = N;
        N = rem;
    }
    return M;
}

int main()
{

}