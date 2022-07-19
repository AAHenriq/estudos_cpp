#include "../ch2/std_lib_facilities.h"

int main()
{

    cout << "Insira o operador (*, /, + ou -) seguido de dois operandos:\n";
    char op{' '};        // inicialização
    double d1{0}, d2{0}; // inicialização

    cin >> op >> d1 >> d2; // inserir valores

    if (op == '*') // se *
    {
        cout << "O resultado da multiplicação de " << d1 << " por " // faz e imprime a
             << d2 << " é " << d1 * d2 << endl;                     // a multiplicação
    }
    else if (op == '/') // se /
    {
        cout << "O resultado da divisão de " << d1 << " por " // faz e imprime a
             << d2 << " é " << d1 / d2 << endl;               // a divisão
    }
    else if (op == '+') // se +
    {
        cout << "O resultado da soma de " << d1 << " com " // faz e imprime a
             << d2 << " é " << d1 + d2 << endl;            // a soma
    }
    else if (op == '-') // se -
    {
        cout << "O resultado da diferença de " << d1 << " com " // faz e imprime a
             << d2 << " é " << d1 - d2 << endl;                 // a diferença
    }
    else // para operações inválidas
    {
        cout << "Operação não reconhecida" << endl;
    }

    return 0;
}