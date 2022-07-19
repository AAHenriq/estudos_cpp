#include "../ch2/std_lib_facilities.h"

int main()
{
    int i1 = 1000; // define um int que excede o limite de bytes de um char
    char c = i1;    // conversão insegure de int para char
    int i2 = c;     // conversão segura de char pra int

    if (i2 != i1) // se os resultados forem diferentes, os imprime mostrando
                  // que houve perda nas conversões
        cout << "Resultados:" << i1 << "!=" << i2 << endl;

    cout << "O char é: " << c << endl;

    return 0;
}