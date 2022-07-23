#include "../ch2/std_lib_facilities.h"

int main()
{
    constexpr double pi{22.0/7}; // Só pode ser inicializada com outras constantes

    cout << pi << endl;

    //constexpr double d4;  Não pode ser feito. Uma constante deve ser inicializada durante
    //d4 = 0;               sua declaração. O mesmo vale para const.

    double d1{0},d2{0};
    cin >> d1 >> d2;
    const double d3{d1/d2}; // Pode ser inicializada com as variáveis d1 e d2, porém
                            // não pode ter seu valor alterado após a inicialização

    //constexpr double pi{d1/d2};   Inicialização de constexpr sem constantes. Gera erro.
    //d3 = 0;                       Modificação de const. Gera erro.

    cout << d3 << endl;

    return 0;
}