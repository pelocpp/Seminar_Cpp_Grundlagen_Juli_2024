// #include <iostream>

// Zeiger
void test_pointer()
{
    int n;

    n = 123;

                          // int*:   Datentyp
    int* ip = nullptr;    // ip ist eine Adresse, die auf eine 'int'-Variable zeigt

    ip = &n;    // &: Adresse-von   Operator  // address-of

    *ip = 456;  // *: Operator: Wert-von // Value-of
                // indirekter Variablenzugriff

    // versus
    n = 457;    // direkter Variablenzugriff

    // Adress Arithmetik
    // Zählt 1 zur Adresse - nicht bei Adressen:
    int size = sizeof(int);
    ip++;

    // =============
    char ch = '?';
    char* cp = &ch;
    int charSize = sizeof(char);
    cp++;
}

// Referenz
void test_reference()
{
    int n;

    n = 123;

    int& ri = n;    // ri ist eine Referenzvariable !

    // n = 456;

    ri = 456;       // 456 wird an n zugewiesen

    ri++;           // 1 zu n addieren // NICHT ZUR ADRESSE von n !!!
}

void test_pointer_reference()
{
    test_pointer();
    test_reference();
}