#include "../ch2/std_lib_facilities.h"

int main()
{
    vector<int> vetor;  //Declara um vetor sem nenhum elemento

    //int in = 0;          Inteiro utilizado para entrada de valores
    //while(cin >> in)     Loop while enquanto valores inteiros são digitados
                         //Substituidos por loop for

    for(int in; cin >> in; ){       //Loop for enquanto inteiros são inseridos
        vetor.push_back(in);                        //Adicionar o número digitado ao vetor
        cout << "O novo membro do vetor é " << in   //Imprime novo membro do vetor e tamanho
             << ", o tamanho atual do vetor é: " << vetor.size() << endl;
    }

    cout << "Impressão do vetor: " << endl;

    for(int x : vetor)          //Loop range-for que imprime todos os membros do vetor
        cout << x << '\t';

    cout << endl;

    sort(vetor);                //Ordena os valores

    cout << "Impressão do vetor de forma ordenada: " << endl;

    for(int x : vetor)          //Loop range-for que imprime todos os membros do vetor
        cout << x << '\t';

    cout << endl;

    return 0;
}