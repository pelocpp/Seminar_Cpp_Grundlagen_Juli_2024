// Parameter

#include <iostream>

void malZwei(int x)    // Parameter // Stellvertreter
{
    x = 2 * x;
}

void test_mal_Zwei()
{
    int n;

    n = 10;
    std::printf("n=%d\n", n);

    malZwei(n);
    std::printf("n=%d\n", n);
}
