#include "../ch2/std_lib_facilities.h"

int main()
    try                             //Bloco try
    {
        vector<int> vetor{0};       //Vetor utilizado para teste 
                                    //inicializado com um único elemento
        cout << vetor[1] << endl;   //Acesso a endereço fora do escopo de vetor
    }
    catch(out_of_range)             //Catch para o throw out_of_range do acesso indevido
    {
        cerr << "Fora do escopo.\n";
        return 1;
    }catch(...){                    //Catch para exceptions acessados por meios mágicos
        cerr << "O que caralhos você fez, irmão?\n";
        return 2;
    }

