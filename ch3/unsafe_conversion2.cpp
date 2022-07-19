#include "../ch2/std_lib_facilities.h"

int main()
{
    double d = 0; //inicializa a variável

    while(cin >> d) //enquanto forem inseridos números o loop continua
    {
        int i1 = d;     //passa o valor para uma int (conversão insegura)
        char c = i1;    //passa o valor da int para char (inseguro)
        int i2 = c;     //de char para int (seguro)

        cout << "d: " << d << endl //imprime todas as variáveis para comparação
        << "i1: " << i1 << endl
        << "c: " << c << endl
        << "i2: " << i2 << endl;
    }

    return 0;
}