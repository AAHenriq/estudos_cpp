#include "../ch2/std_lib_facilities.h"

int main()
{
    cout << "Insira o número de milhas:\n";
    double miles {0};   //inicializa miles
    cin >> miles;       //Insere um valor em milhas

    double km = miles * 1.609; //Transforma o valor de milhas em km

    cout << miles << " milhas equivalem a " << km << " km" << endl; //Imprime o resultado

    return 0;
}