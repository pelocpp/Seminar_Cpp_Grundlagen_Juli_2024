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
//    *ip = tmp;       // Wert an die Adresse zur�ckschreiben
//}

void malZweiEx(int* const ip)    // Parameter // Stellvertreter
{
    int tmp;

    // ++ip;

    tmp = *ip;       // Wert hinter der Adresse lesen
    tmp = 2 * tmp;
    *ip = tmp;       // Wert an die Adresse zur�ckschreiben
    // oder k�rzer
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

    malZwei(n);                // �bergabe einer Kopie eines Werts
    std::printf("n=%d\n", n);

    malZweiEx(&n);             // �bergabe der Adresse einer Variablen
    std::printf("n=%d\n", n);

    malZweiExEx(n);            // �bergabe der Referenz einer Variablen
    std::printf("n=%d\n", n);

   // malZweiEx( (int*) &d);
}

// ==============================================

