#include "../ch2/std_lib_facilities.h"

constexpr double CM_p_M{1.0/100};
constexpr double IN_p_M{2.54*CM_p_M};
constexpr double FT_p_M{12*IN_p_M};

const vector<string> val_unit{"m", "cm", "ft", "in"};

bool is_unit_val(string uni)
{
    for(string unit: val_unit)
    {
        if(unit == uni)
            return true;
    }

    return false;
}

double unit_conv(double num, string uni)
{
    if(uni == "cm")
        num *= CM_p_M;
    else if(uni == "in")
        num *= IN_p_M;
    else if(uni == "ft")
        num *= FT_p_M;

    return num;
}

int main()
{
    double num{0};
    double bigger{0}, smaller{0};
    string unidade{" "};

    vector<double> registro;
    double sum{0};

    //Primeiro número:
    while(!is_unit_val(unidade)){
        cout << "Insira o primeiro número desejado seguido de sua unidade, "
             << "separados por espaço:" << endl;
        cin >> num >> unidade;                  //Inserção dos valores

        if(!is_unit_val(unidade))               //Checa se a unidade é válida
            cout << "Unidade inválida.\n";
    }

    num = unit_conv(num, unidade);              //Converte o primeiro valor para metros
    registro.push_back(num);                    //Registro
    sum += num;                                 //Soma

    bigger = smaller = num;
    cout << "Primeiro valor inserido: " << num << "m" << endl;

    //Loop while:
    cout << endl << "Insira um número desejado seguido de sua unidade, "
         << "separados por espaço:" << endl;

    while(cin >> num >> unidade)                //Inserção dos valores
    {
        if(!is_unit_val(unidade))               //Checa válidade da unidade
            cout << endl << "Unidade inválida.";
        else
            {
            num = unit_conv(num, unidade);          //Conversão
            registro.push_back(num);                //Registro
            sum += num;                             //Soma

            //Compara os números
            if(bigger < num)
            {
                bigger = num;
                cout << "Novo maior valor inserido: " << num << "m" << endl;
            }else if(smaller > num)
            {
                smaller = num;
                cout << "Novo menor valor inserido: " << num << "m" << endl;
            }
        }
        cout << endl << "Insira um número desejado seguido de sua unidade, "
             << "separados por espaço:" << endl;
    }

    //Impressão das informações:
    cout << endl << "Menor valor: " << smaller << "m;\n"
         << "Maior valor: " << bigger << "m;\n"
         << "Número de valores inseridos: " << registro.size()
         << ";\n" << "Soma dos valores: " << sum << "m;";

    //Impressão do vetor:
    sort(registro);
    cout << endl << "Todos os valores ordenados:\n";
    for(double x: registro)
        cout << x << " m; ";


    return 0;
}