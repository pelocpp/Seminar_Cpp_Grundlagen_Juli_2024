#include <iostream>

extern void main_time();  // Linker
extern void test_mal_Zwei();
extern void test_pointer_reference();

int main_hello_world ()  // main muss so sein.
{
    int a,  b, c;

    a = 1;
    b = 2;
    c = a + b;

    std::cout << "Hello World" << std::endl;  // C++
    // printf

    return 0;
}


int main()  // main muss so sein.
{
    main_time();
}
