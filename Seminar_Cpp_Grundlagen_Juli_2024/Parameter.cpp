// Parameter

#include <iostream>

void malZwei(int x)    // Parameter // Stellvertreter
{
    x = 2 * x;
}

//void malZweiEx(int* ip)    // Parameter // Stellvertreter
//{
//    int tmp;
//
//    tmp = *ip;       // Wert hinter der Adresse lesen
//
//    tmp = 2 * tmp;
//
//    *ip = tmp;       // Wert an die Adresse zurückschreiben
//}

void malZweiEx(int* const ip)    // Parameter // Stellvertreter
{
    int tmp;

    // ++ip;

    tmp = *ip;       // Wert hinter der Adresse lesen
    tmp = 2 * tmp;
    *ip = tmp;       // Wert an die Adresse zurückschreiben
    // oder kürzer
    *ip = 2 * (*ip);
}

void malZweiExEx(int& x)
{
    x = 2 * x;
}


void test_mal_Zwei()
{
    int n;
    double d;

    n = 10;
    d = 123.456;

    std::printf("n=%d\n", n);

    malZwei(n);                // Übergabe einer Kopie eines Werts
    std::printf("n=%d\n", n);

    malZweiEx(&n);             // Übergabe der Adresse einer Variablen
    std::printf("n=%d\n", n);

    malZweiExEx(n);            // Übergabe der Referenz einer Variablen
    std::printf("n=%d\n", n);

   // malZweiEx( (int*) &d);
}

// ==============================================

